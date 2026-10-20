#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Alıştırma defterinin Koco cildini yapan betik. (alistirma/yap.py'nin kardeşi.)

Girdi : ../kitapcik/ortak.css + ../alistirma/ek.css + ../kitapcik-koco/ek.css + ek.css
        + bolumler/*.html (gövde parçaları)
Çıktı : cikti/<dosya>.html       -> her biri tek başına yayımlanabilir (artifact)
        cikti/defter-tam.html    -> yazılmış bölümler bir arada, PDF için

Kullanım:  python3 alistirma-koco/yap.py
"""

import base64
import mimetypes
import os
import pathlib
import re

KOK = pathlib.Path(__file__).resolve().parent
# Biçem: kardeş kitapçığın ortak.css'i, C++ cildinin basamak biçemleri
# (alistirma/ek.css), Koco kitapçığının vurgu rengi (petrol; kitapcik-koco/ek.css)
# ve bu cilde özgü birkaç satır (ek.css: "Tuvalde" tarifi).
ORTAK = "\n".join(p.read_text(encoding="utf-8") for p in (
    KOK.parent / "kitapcik" / "ortak.css", KOK.parent / "alistirma" / "ek.css",
    KOK.parent / "kitapcik-koco" / "ek.css", KOK / "ek.css"))
CIKTI = KOK / "cikti"
CIKTI.mkdir(exist_ok=True)
# yazı tipleri de kardeş kitapçıktan (bkz. kitapcik/yazitipi/indir.py)
YAZITIPI = KOK.parent / "kitapcik" / "yazitipi" / "yazitipi.css"
# kod bloklarındaki "Hepsini seç" düğmesinin betiği
KOPYALA = KOK.parent / "kitapcik" / "kopyala.js"

# Bölüm metinlerindeki resim yolları cikti/ dizinine göre yazılıyor
# (../../kitapcik/resim/<ad>, ../../kitap/kapak-alistirma-koco.png). Tek başına
# yayımlanan sayfalarda resimler data URI olarak gömülüyor.
RESIM_DESENI = re.compile(r'src="((?:\.\./)+[^"]+)"')

BASLIK = "Keyifli Alıştırmalar · Koco"

FONT = (
    '<link rel="preconnect" href="https://fonts.googleapis.com">\n'
    '<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>\n'
    '<link rel="stylesheet" href="https://fonts.googleapis.com/css2?'
    "family=Bitter:ital,wght@0,400;0,600;0,700;1,400&"
    "family=IBM+Plex+Mono:ital,wght@0,400;0,500;0,600;1,400&"
    "family=IBM+Plex+Sans:ital,wght@0,400;0,500;0,600;1,400&"
    'display=swap">'
)

# (dosya, kısa ad, artifact başlığı, tek satırlık tanıtım)
# Henüz yazılmamış bölümler için govde() boş bir başlık basar; yapı bozulmaz.
BOLUMLER = [
    ("00-hazirlik",   "Hazırlık",              "Hazırlık: iKojo'da, Hiçbir Şey Yüklemeden",
     "Kaplumbağayı tanımak: ileri, dön, zıpla, renk. Tek konu, beş çizim."),
    ("01-ilk-adimlar", "I. İlk Adımlar",       "Alıştırmalar I: Kaplumbağayla İlk Adımlar",
     "tanım, dez/den, türler, çıktısı olan işlevler, ilk Project Euler'ler ve tahmin oyunu."),
    ("02-veri",       "II. Veriyi Düzenlemek", "Alıştırmalar II: Veriyi Düzenlemek",
     "Dizin, işle/ele/indirge, küme ve eşlem, yığın ve kuyruk."),
    ("03-soyutlama",  "III. Soyutlama",        "Alıştırmalar III: Soyutlama Sanatı",
     "Tekrara ad takmak, işlevi girdi alan işlevler, belirt ile sınama, ölçme."),
    ("04-ozyineleme", "IV. Özyineleme",        "Alıştırmalar IV: Özyineleme ve Fraktallar",
     "Taban ve adım, ağaçlar, Koch tanesi, Hanoi, dizinlerde özyineleme, bellek."),
    ("05-cizgeler",   "V. Çizgeler",           "Alıştırmalar V: Çizgeler ve Gezintiler",
     "Eşlemle çizge, işlevsel derinlemesine ve enlemesine gezi, bağlı parçalar, Dijkstra."),
    ("06-dp",         "VI. Dinamik Programlama", "Alıştırmalar VI: Dinamik Programlama",
     "Izgara yolları, bozuk paralar, karmaşık sayılar ve Mandelbrot, yola devam."),
]

# Yalnız yazılmış bölümler sayfaya, şeride ve birleşik belgeye girer;
# BOLUMLER'deki ötekiler henüz başlık.
SIRA = [b[0] for b in BOLUMLER if (KOK / "bolumler" / f"{b[0]}.html").exists()]
AD = {b[0]: b[1] for b in BOLUMLER}
BAS = {b[0]: b[2] for b in BOLUMLER}


def govde(slug: str) -> str:
    yol = KOK / "bolumler" / f"{slug}.html"
    if not yol.exists():          # henüz yazılmamış bölüm: yapıyı bozmasın
        return f'<header class="ust"><h1>{BAS[slug]}</h1></header>'
    return yol.read_text(encoding="utf-8").strip()


def gezinme(slug: str, baglantilar: dict[str, str] | None) -> str:
    """Alt gezinme çubuğu. baglantilar verilmezse (PDF) hiç basılmaz."""
    if baglantilar is None:
        return ""
    i = SIRA.index(slug)
    onceki = SIRA[i - 1] if i > 0 else None
    sonraki = SIRA[i + 1] if i < len(SIRA) - 1 else None
    sol = sag = ""
    if onceki and baglantilar.get(onceki):
        sol = (f'<a href="{baglantilar[onceki]}"><span class="yon">Önceki</span>'
               f"{AD[onceki]}</a>")
    if sonraki and baglantilar.get(sonraki):
        sag = (f'<a class="sag" href="{baglantilar[sonraki]}"><span class="yon">Sonraki</span>'
               f"{AD[sonraki]}</a>")
    if not sol and not sag:
        return ""
    return f'<nav class="gezinme">{sol or "<span></span>"}{sag}</nav>'


def icerik_seridi(slug: str, baglantilar: dict[str, str] | None) -> str:
    """Başlıktaki bölüm şeridi. Bağlantı yoksa düz yazı olarak basılır."""
    ogeler = []
    for s in SIRA:
        etiket = AD[s]
        if s == slug:
            ogeler.append(
                f'<li><a aria-current="page" style="border-color:var(--mavi);'
                f'color:var(--mavi)">{etiket}</a></li>'
            )
        elif baglantilar and baglantilar.get(s):
            ogeler.append(f'<li><a href="{baglantilar[s]}">{etiket}</a></li>')
        else:
            ogeler.append(f"<li><a>{etiket}</a></li>")
    return '<ul class="icerik-seridi">' + "".join(ogeler) + "</ul>"


def kur(slug: str, baglantilar: dict[str, str] | None, tam: bool = False) -> str:
    g = govde(slug)
    g = g.replace("<!--ICERIK-SERIDI-->", icerik_seridi(slug, baglantilar))
    g = g.replace("<!--GEZINME-->", gezinme(slug, baglantilar))
    # PDF'te tüm bölümler tek belgede: iç bağlantıları çapa yap
    if tam:
        for s in SIRA:
            g = g.replace(f'href="{{{{{s}}}}}"', f'href="#{s}"')
    else:
        for s in SIRA:
            hedef = (baglantilar or {}).get(s)
            g = re.sub(
                r'href="\{\{' + re.escape(s) + r'\}\}"',
                f'href="{hedef}"' if hedef else 'href="#"',
                g,
            )
    return g


def resimleri_goem(metin: str) -> str:
    """Resimleri data URI olarak gömer: sayfa tek başına taşınabilsin diye."""
    def degistir(eslesme):
        ad = eslesme.group(1)
        yol = (CIKTI / ad).resolve()
        if not yol.exists():
            return eslesme.group(0)
        tur = mimetypes.guess_type(ad)[0] or "image/jpeg"
        veri = base64.b64encode(yol.read_bytes()).decode("ascii")
        return f'src="data:{tur};base64,{veri}"'
    return RESIM_DESENI.sub(degistir, metin)


def artifact_yaz(baglantilar: dict[str, str]) -> None:
    """Her bölüm için tek başına yayımlanabilir dosya."""
    for slug, _kisa, baslik, _tanit in BOLUMLER:
        if slug not in SIRA:
            continue
        icerik = resimleri_goem(kur(slug, baglantilar, tam=False))
        html = (
            f"<title>{baslik}</title>\n{FONT}\n"
            f"<style>\n{ORTAK}\n</style>\n"
            # Tek başına yayımlanan sayfada <html lang> bizden çıkmıyor;
            # Türkçe büyük harf (i -> İ) doğru olsun diye burada kuruyoruz.
            '<script>document.documentElement.lang = "tr"</script>\n'
            f'<div class="sayfa">\n{icerik}\n</div>\n'
            f"{kopyala_betigi()}"
        )
        (CIKTI / f"{slug}.html").write_text(html, encoding="utf-8")


def kopyala_betigi() -> str:
    """Kod bloklarına "Hepsini seç" düğmesini ekleyen betik, sayfanın içine
    gömülü. Tek başına yayımlanan sayfanın yanında ayrı dosya bulunmadığı için
    gömmek gerekiyor; EPUB'da ise paketin içine dosya olarak konuyor."""
    if not KOPYALA.exists():
        return ""
    return "<script>\n" + KOPYALA.read_text(encoding="utf-8") + "</script>\n"


def yerel_yazitipi() -> str:
    """PDF için yazı tipleri yerelden gelsin: ağ yoksa ya da Google Fonts
    yüklenemezse Chromium sessizce sistem yazı tipine düşüyor ve PDF başka
    görünüyordu. Yayımlanan sayfalar (artifact) Google Fonts'u kullanmaya
    devam ediyor; oralarda yerel dosya yok."""
    if not YAZITIPI.exists():
        return FONT
    css = YAZITIPI.read_text(encoding="utf-8")
    yol = os.path.relpath(YAZITIPI.parent, CIKTI).replace(os.sep, "/")
    return "<style>\n" + css.replace("url('", f"url('{yol}/") + "</style>"


def tam_yaz() -> None:
    """Hepsi bir arada: PDF için tam belge."""
    parcalar = []
    kapak = KOK.parent / "kitap" / "kapak-alistirma-koco.png"
    if kapak.exists():          # kapak henüz yok; olunca PDF'in ilk sayfası olur
        parcalar.append('<section class="pdf-kapak">'
                        f'<img src="../../kitap/kapak-alistirma-koco.png" alt="{BASLIK}">'
                        "</section>")
    for i, slug in enumerate(SIRA):
        sinif = "bolum-basi" if i > 0 else ""
        parcalar.append(
            f'<section id="{slug}" class="{sinif}">\n{kur(slug, None, tam=True)}\n</section>'
        )
    html = (
        "<!doctype html>\n"
        '<html lang="tr" data-theme="light">\n<head>\n<meta charset="utf-8">\n'
        '<meta name="viewport" content="width=device-width, initial-scale=1">\n'
        f"<title>{BASLIK}</title>\n{yerel_yazitipi()}\n"
        f"<style>\n{ORTAK}\n</style>\n</head>\n<body>\n"
        f'<div class="sayfa">\n' + "\n".join(parcalar) + "\n</div>\n"
        + kopyala_betigi() + "</body>\n</html>\n"
    )
    (CIKTI / "defter-tam.html").write_text(html, encoding="utf-8")


if __name__ == "__main__":
    baglanti_dosyasi = KOK / "baglantilar.txt"
    baglantilar = {}
    if baglanti_dosyasi.exists():
        for satir in baglanti_dosyasi.read_text(encoding="utf-8").splitlines():
            satir = satir.strip()
            if not satir or satir.startswith("#") or " " not in satir:
                continue
            k, v = satir.split(None, 1)
            baglantilar[k] = v.strip()
    artifact_yaz(baglantilar)
    tam_yaz()
    print(f"{len(SIRA)} bölüm + tam belge yazıldı -> {CIKTI}")
