#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Kitapçığı yapan betik.

Girdi : kitapcik/ortak.css + kitapcik/bolumler/*.html (gövde parçaları)
Çıktı : kitapcik/cikti/<dosya>.html   -> her biri tek başına yayımlanabilir (artifact)
        kitapcik/cikti/kitapcik-tam.html -> hepsi bir arada, PDF için

Kullanım:  python3 kitapcik/yap.py
"""

import base64
import mimetypes
import pathlib
import re

KOK = pathlib.Path(__file__).resolve().parent
ORTAK = (KOK / "ortak.css").read_text(encoding="utf-8")
CIKTI = KOK / "cikti"
CIKTI.mkdir(exist_ok=True)
RESIM = KOK / "resim"

# Bölüm metinlerinde resimler ../resim/<ad> diye anılıyor. Bu yol
# cikti/*.html ve PDF için doğru; ama tek başına yayımlanan sayfalarda
# yanında dosya olmadığı için resimleri içeri gömmek gerekiyor.
RESIM_DESENI = re.compile(r'src="\.\./resim/([^"]+)"')

BASLIK = "Programlamaya ve Algoritmalara Keyifli Bir Başlangıç"

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
BOLUMLER = [
    ("00-kapak",     "Kılavuz",              "Keyifli Bir Başlangıç",
     "Programlamaya ve algoritmalara giriş kitapçığının kapağı, çalışma yöntemi ve içindekiler."),
    ("01-ilk-adimlar", "I. İlk Adımlar",     "İlk Adımlar",
     "Değer, değişken, tür ve işlev: ilk çalışan programlarınız ve ilk oyununuz."),
    ("02-veri",      "II. Veriyi Düzenlemek", "Veriyi Düzenlemek",
     "Diziler, akıllı diziler, eşlemler, kümeler, yığınlar ve kendi türlerinizi yazmak."),
    ("03-zanaat",    "III. Zanaat",          "Programcının Zanaatı",
     "Derleyici, make, testler, hata ayıklama ve hız ölçümü: programı işe yarar kılan alışkanlıklar."),
    ("04-ozyineleme", "IV. Özyineleme",      "Özyineleme ve Arama",
     "Kendini çağıran işlevler, bellekle hızlandırma, geri dönüşlü arama ve arama uzayını budamak."),
    ("05-cizgeler",  "V. Çizgeler",          "Çizgeler ve Gezintiler",
     "Derinlemesine ve enlemesine gezi, bağlı parçalar, en kısa yol algoritmaları."),
    ("06-dp",        "VI. Dinamik Program",  "Dinamik Programlama",
     "Büyük problemi küçük parçalarına bölmek: zarlar, bozuk paralar, ızgaralar ve yola devam."),
]

SIRA = [b[0] for b in BOLUMLER]
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
        if s == "00-kapak":
            continue
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
        yol = RESIM / ad
        if not yol.exists():
            return eslesme.group(0)
        tur = mimetypes.guess_type(ad)[0] or "image/jpeg"
        veri = base64.b64encode(yol.read_bytes()).decode("ascii")
        return f'src="data:{tur};base64,{veri}"'
    return RESIM_DESENI.sub(degistir, metin)


def artifact_yaz(baglantilar: dict[str, str]) -> None:
    """Her bölüm için tek başına yayımlanabilir dosya."""
    for slug, _kisa, baslik, _tanit in BOLUMLER:
        icerik = resimleri_goem(kur(slug, baglantilar, tam=False))
        html = (
            f"<title>{baslik}</title>\n{FONT}\n"
            f"<style>\n{ORTAK}\n</style>\n"
            f'<div class="sayfa">\n{icerik}\n</div>\n'
        )
        (CIKTI / f"{slug}.html").write_text(html, encoding="utf-8")


def tam_yaz() -> None:
    """Hepsi bir arada: PDF için tam belge."""
    parcalar = [
        '<section class="pdf-kapak">'
        f'<img src="../../kitap/kapak.png" alt="{BASLIK}">'
        "</section>"
    ]
    for i, slug in enumerate(SIRA):
        sinif = "bolum-basi" if i > 0 else ""
        parcalar.append(
            f'<section id="{slug}" class="{sinif}">\n{kur(slug, None, tam=True)}\n</section>'
        )
    html = (
        "<!doctype html>\n"
        '<html lang="tr" data-theme="light">\n<head>\n<meta charset="utf-8">\n'
        '<meta name="viewport" content="width=device-width, initial-scale=1">\n'
        f"<title>{BASLIK}</title>\n{FONT}\n"
        f"<style>\n{ORTAK}\n</style>\n</head>\n<body>\n"
        f'<div class="sayfa">\n' + "\n".join(parcalar) + "\n</div>\n</body>\n</html>\n"
    )
    (CIKTI / "kitapcik-tam.html").write_text(html, encoding="utf-8")


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
    print(f"{len(BOLUMLER)} bölüm + tam belge yazıldı -> {CIKTI}")
