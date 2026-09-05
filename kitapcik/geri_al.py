#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Yayımlanmış bir bölüm sayfasından (artifact) bölümün kaynağını geri çıkarır
ve depodaki bolumler/<bölüm>.html ile karşılaştırır.

Ne işe yarar: Bir bölüm çevrimiçi sayfada düzeltilip yeniden yayımlanır ama
kaynak dosya depoya işlenmezse PDF ile EPUB geride kalır. Bu betik sayfayı
alıp yap.py'nin yaptığı dönüşümleri tersine çevirir (içindekiler şeridi,
gezinme çubuğu, bölümler arası adresler, içeri gömülmüş resimler) ve farkı
gösterir; istenirse kaynağı sayfadaki hâline getirir.

Kullanım:
    python3 kitapcik/geri_al.py <kitapçık-dizini> <bölüm> <sayfa.html> [--yaz]

    <kitapçık-dizini>  kitapcik ya da kitapcik-koco
    <bölüm>            bolumler/ altındaki dosya adı, uzantısız (01-ilk-adimlar)
    <sayfa.html>       yayımlanan sayfanın kaydedilmiş hâli (tarayıcıdan
                       "sayfayı kaydet" ya da artifact'in ham HTML'i)
    --yaz              kaynak dosyayı sayfadaki hâle getir

Çıkış kodu: 0 aynı, 1 farklı, 2 hata. Resimler bayt bayt karşılaştırılır;
resim sayısı tutmuyorsa yazmaz, elle bakmak gerekir.

Örnek:
    python3 kitapcik/geri_al.py kitapcik-koco 01-ilk-adimlar ~/indirilen/sayfa.html
"""

import base64
import difflib
import importlib.util
import pathlib
import re
import sys

RESIM_YOLU = re.compile(r'src="((?:\.\./)+[^"]+)"')
RESIM_VERI = re.compile(r'src="data:([^;]+);base64,([^"]+)"')


def hata(ileti: str) -> None:
    print("HATA:", ileti, file=sys.stderr)
    sys.exit(2)


def yap_modulu(kok: pathlib.Path):
    """Kitapçığın kendi yap.py'sini yükle (CIKTI dizini oradan geliyor)."""
    ozellik = importlib.util.spec_from_file_location("yap", kok / "yap.py")
    modul = importlib.util.module_from_spec(ozellik)
    ozellik.loader.exec_module(modul)
    return modul


def baglantilar(kok: pathlib.Path) -> dict[str, str]:
    dosya = kok / "baglantilar.txt"
    sonuc = {}
    if not dosya.exists():
        return sonuc
    for satir in dosya.read_text(encoding="utf-8").splitlines():
        satir = satir.strip()
        if satir and not satir.startswith("#") and " " in satir:
            k, v = satir.split(None, 1)
            sonuc[k] = v.strip()
    return sonuc


def govdeyi_al(sayfa: str) -> str:
    bas = '<div class="sayfa">\n'
    i = sayfa.find(bas)
    j = sayfa.rfind("\n</div>")
    if i < 0 or j < 0:
        hata('sayfada <div class="sayfa"> bulunamadı; bu bir bölüm sayfası mı?')
    return sayfa[i + len(bas):j]


def geri_cevir(govde: str, kok: pathlib.Path, cikti: pathlib.Path,
               kaynak: str) -> tuple[str, list[str]]:
    """yap.py'nin dönüşümlerini tersine çevir. Notları da döndür."""
    notlar = []
    # içindekiler şeridi ve gezinme: yap.py bunları yer tutuculardan üretiyor
    govde = re.sub(r'<ul class="icerik-seridi">.*?</ul>', "<!--ICERIK-SERIDI-->",
                   govde, count=1, flags=re.S)
    govde = re.sub(r'<nav class="gezinme">.*?</nav>', "<!--GEZINME-->",
                   govde, count=1, flags=re.S)
    # bölümler arası adresler -> {{bölüm}}
    for bolum, adres in baglantilar(kok).items():
        govde = govde.replace(f'href="{adres}"', f'href="{{{{{bolum}}}}}"')
    # içeri gömülmüş resimler -> kaynaktaki yollar (sırayla)
    yollar = RESIM_YOLU.findall(kaynak)
    veriler = RESIM_VERI.findall(govde)
    if len(yollar) != len(veriler):
        notlar.append(f"resim sayısı tutmuyor: kaynakta {len(yollar)}, "
                      f"sayfada {len(veriler)} -- resimler elle karşılaştırılmalı")
    sira = iter(yollar)

    def degistir(eslesme):
        yol = next(sira, None)
        if yol is None:
            return eslesme.group(0)
        dosya = (cikti / yol).resolve()
        ayni = dosya.exists() and dosya.read_bytes() == base64.b64decode(eslesme.group(2))
        notlar.append(f"resim {yol}: {'aynı' if ayni else 'FARKLI ya da yok'}")
        return f'src="{yol}"'

    govde = RESIM_VERI.sub(degistir, govde)
    return govde.strip() + "\n", notlar


def main(argv: list[str]) -> int:
    yaz = "--yaz" in argv
    argv = [a for a in argv if a != "--yaz"]
    if len(argv) != 3:
        print(__doc__)
        return 2
    kok = pathlib.Path(argv[0]).resolve()
    bolum = argv[1]
    sayfa_yolu = pathlib.Path(argv[2])
    kaynak_yolu = kok / "bolumler" / f"{bolum}.html"
    for p in (kok / "yap.py", kaynak_yolu, sayfa_yolu):
        if not p.exists():
            hata(f"{p} yok")

    yap = yap_modulu(kok)
    kaynak = kaynak_yolu.read_text(encoding="utf-8")
    sayfa = sayfa_yolu.read_text(encoding="utf-8")
    yeni, notlar = geri_cevir(govdeyi_al(sayfa), kok, yap.CIKTI, kaynak)
    for n in notlar:
        print(n)

    eski = kaynak.strip() + "\n"
    if yeni == eski:
        print(f"AYNI: {kaynak_yolu.relative_to(kok.parent)} sayfayla birebir aynı")
        return 0

    fark = list(difflib.unified_diff(eski.splitlines(), yeni.splitlines(),
                                     "kaynak", "sayfa", lineterm="", n=2))
    eklenen = sum(1 for s in fark if s.startswith("+") and not s.startswith("+++"))
    silinen = sum(1 for s in fark if s.startswith("-") and not s.startswith("---"))
    print(f"FARKLI: sayfada {eklenen} satır fazla, {silinen} satır eksik")
    print("\n".join(fark))
    if yaz:
        if any("tutmuyor" in n for n in notlar):
            print("Resim sayısı tutmadığı için yazılmadı.")
            return 1
        kaynak_yolu.write_text(yeni, encoding="utf-8")
        print(f"YAZILDI: {kaynak_yolu.relative_to(kok.parent)}")
    return 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
