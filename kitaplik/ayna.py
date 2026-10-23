#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
GitHub Pages aynası: dört eserin bölümlerini ve Kitaplık sayfalarını
tam HTML olarak depo kökündeki docs/ dizinine yazar.

    docs/index.html                 Keyifli Kitaplık (genel sayfa)
    docs/dizin.html, dizin-veri.js  kavram dizini
    docs/inceleme.html              inceleme raporu
    docs/kitapcik/<bölüm>.html      C++ kitapçığı
    docs/kitapcik-koco/<bölüm>.html Koco kitapçığı
    docs/alistirma/<bölüm>.html     alıştırma defteri, C++ cildi
    docs/alistirma-koco/<bölüm>.html alıştırma defteri, Koco cildi

Sayfaların gövdesini her eserin kendi yap.py'si kurar (kur()); bu betik yalnız
sarmalayıp iki dönüşüm uygular:

  * Bölümler arası bağlantılar claude.ai adresleri yerine göreli yollara gider
    (baglantilar.txt'deki ilk adres -> docs/ içindeki dosya). Böylece ayna
    kendi içinde kapalıdır; claude.ai sayfalarına bağımlı değildir.
  * Resimler gömülmez (sayfa şişmesin) ve docs/'a kopyalanmaz (ikili dosya
    çoğalmasın); deponun ham GitHub adresinden okunur.

Kullanım:  python3 kitaplik/ayna.py      (ya da  make -C kitaplik ayna)

docs/ üretilmiş dosyadır; elle düzenlemeyin, kaynağı değiştirip yeniden üretin.
GitHub Pages'in depo ayarlarında "main, /docs" olarak açılması gerekir; adres:
https://bulent2k2.github.io/cpp_ogreniyoruz/
"""

import importlib.util
import os
import pathlib
import re
import sys

DEPO = pathlib.Path(__file__).resolve().parent.parent
DOCS = DEPO / "docs"
HAM = "https://raw.githubusercontent.com/bulent2k2/cpp_ogreniyoruz/main/"
ESERLER = ["kitapcik", "kitapcik-koco", "alistirma", "alistirma-koco"]
KITAPLIK = {"kitaplik": "index.html", "dizin": "dizin.html", "inceleme": "inceleme.html"}


def modul(dizin: str):
    """<dizin>/yap.py'yi ad çakışmadan yükler (hepsinin adı yap)."""
    yol = DEPO / dizin / "yap.py"
    spec = importlib.util.spec_from_file_location("yap_" + dizin.replace("-", "_"), yol)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def adresler(dizin: str) -> dict[str, str]:
    """baglantilar.txt: anahtar -> ilk adres (claude.ai). İkinci sütun aynanın adresi."""
    dosya = DEPO / dizin / "baglantilar.txt"
    sonuc = {}
    if not dosya.exists():
        return sonuc
    for satir in dosya.read_text(encoding="utf-8").splitlines():
        satir = satir.strip()
        if not satir or satir.startswith("#") or " " not in satir:
            continue
        k, v = satir.split()[:2]
        sonuc[k] = v
    return sonuc


def harita() -> dict[str, str]:
    """claude.ai adresi -> docs/ içindeki yol."""
    h = {}
    for e in ESERLER:
        for slug, adres in adresler(e).items():
            h[adres] = f"{e}/{slug}.html"
    for ad, adres in adresler("kitaplik").items():
        h[adres] = KITAPLIK.get(ad, f"{ad}.html")
    return h


def baglantilari_cevir(metin: str, sayfa_dizini: str, h: dict[str, str]) -> str:
    """claude.ai adreslerini sayfanın bulunduğu dizine göre göreli yola çevirir.
    Adresin ardındaki #çapa olduğu gibi kalır."""
    for adres in sorted(h, key=len, reverse=True):
        hedef = os.path.relpath(h[adres], sayfa_dizini or ".").replace(os.sep, "/")
        metin = metin.replace(adres, hedef)
    return metin


def resimleri_cevir(metin: str, cikti: pathlib.Path) -> str:
    """cikti/'ye göre yazılmış ../ resim yollarını deponun ham adresine çevirir."""
    def degistir(eslesme):
        ad = eslesme.group(1)
        yol = (cikti / ad).resolve()
        if not yol.exists():
            return eslesme.group(0)
        return f'src="{HAM}{yol.relative_to(DEPO).as_posix()}"'
    return re.compile(r'src="((?:\.\./)+[^"]+)"').sub(degistir, metin)


def eser_yaz(e: str, h: dict[str, str]) -> int:
    m = modul(e)
    dizin = DOCS / e
    dizin.mkdir(parents=True, exist_ok=True)
    yerel = {s: f"{s}.html" for s in m.SIRA}      # komşu bölümler yan yana
    sayi = 0
    for slug, _kisa, baslik, tanit in m.BOLUMLER:
        if slug not in m.SIRA:
            continue
        govde = m.kur(slug, yerel, tam=False)
        govde = resimleri_cevir(govde, m.CIKTI)
        govde = baglantilari_cevir(govde, e, h)
        sayfa = (
            "<!doctype html>\n"
            f"<!-- Üretilmiş dosya (kitaplik/ayna.py). Kaynak: {e}/bolumler/{slug}.html -->\n"
            '<html lang="tr">\n<head>\n<meta charset="utf-8">\n'
            '<meta name="viewport" content="width=device-width, initial-scale=1">\n'
            f"<title>{baslik}</title>\n"
            f'<meta name="description" content="{tanit}">\n'
            f"{m.FONT}\n<style>\n{m.ORTAK}\n</style>\n</head>\n<body>\n"
            f'<div class="sayfa">\n{govde}\n</div>\n'
            f"{m.kopyala_betigi()}</body>\n</html>\n"
        )
        (dizin / f"{slug}.html").write_text(sayfa, encoding="utf-8")
        sayi += 1
    return sayi


def kitaplik_yaz(h: dict[str, str]) -> int:
    m = modul("kitaplik")
    sayi = 0
    for ad, hedef in KITAPLIK.items():
        kaynak = (DEPO / "kitaplik" / f"{ad}.html").read_text(encoding="utf-8")
        sayfa = m.sar(kaynak).replace(
            "<!doctype html>\n",
            f"<!doctype html>\n<!-- Üretilmiş dosya (kitaplik/ayna.py). Kaynak: kitaplik/{ad}.html -->\n", 1)
        (DOCS / hedef).write_text(baglantilari_cevir(sayfa, "", h), encoding="utf-8")
        sayi += 1
    veri = (DEPO / "kitaplik" / "dizin-veri.js").read_text(encoding="utf-8")
    (DOCS / "dizin-veri.js").write_text(baglantilari_cevir(veri, "", h), encoding="utf-8")
    return sayi + 1


def denetle() -> list[str]:
    """Aynadaki göreli bağlantıların hedefi ve #çapası var mı, claude.ai adresi kaldı mı?"""
    hatalar = []
    for sayfa in sorted(DOCS.rglob("*.html")):
        metin = sayfa.read_text(encoding="utf-8")
        if "https://claude.ai/" in metin:
            hatalar.append(f"{sayfa.relative_to(DOCS)}: claude.ai adresi kalmış")
        # yalnız göreli bağlantılar: "dosya", "dosya#çapa", "#çapa"
        for hedef, capa in re.findall(r'href="(?![a-z]+:)([^"#]*)(?:#([^"]*))?"', metin):
            if not hedef and not capa:
                continue
            dosya = (sayfa.parent / hedef) if hedef else sayfa
            if not dosya.exists():
                hatalar.append(f"{sayfa.relative_to(DOCS)}: {hedef} yok")
            elif capa and f'id="{capa}"' not in dosya.read_text(encoding="utf-8"):
                hatalar.append(f"{sayfa.relative_to(DOCS)}: {hedef}#{capa} çapası yok")
    return hatalar


if __name__ == "__main__":
    DOCS.mkdir(exist_ok=True)
    (DOCS / ".nojekyll").write_text("")      # dosyalar olduğu gibi sunulsun
    h = harita()
    toplam = sum(eser_yaz(e, h) for e in ESERLER) + kitaplik_yaz(h)
    hatalar = denetle()
    for hata in hatalar:
        print("HATA:", hata, file=sys.stderr)
    print(f"{toplam} dosya yazıldı -> {DOCS}" + (f", {len(hatalar)} hata" if hatalar else ""))
    sys.exit(1 if hatalar else 0)
