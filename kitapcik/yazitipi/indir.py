#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Kitapçığın yazı tiplerini Google Fonts'tan indirip bu dizine koyar ve
yazitipi.css'i üretir. Bir kere çalıştırmak yeter; dosyalar depoda duruyor.

Neden? PDF ve kapak Chromium'la üretiliyor; ağ yoksa (ya da Google Fonts
yüklenemezse) Chromium sessizce sistem yazı tipine düşüyor ve PDF başka
görünüyordu. Yazı tipleri yerelde durunca çıktı her makinede aynı olur.

Yalnızca latin ve latin-ext alt kümeleri alınıyor: Türkçe için bu ikisi
yetiyor (ç, ğ, ı, ö, ş, ü, İ latin-ext'te).

Kullanım:  python3 kitapcik/yazitipi/indir.py
"""

import pathlib
import re
import subprocess
import sys

KOK = pathlib.Path(__file__).resolve().parent
ALTKUMELER = {"latin", "latin-ext"}

# yap.py'deki FONT bağlantısıyla aynı aileler ve ağırlıklar
ADRES = ("https://fonts.googleapis.com/css2?"
         "family=Bitter:ital,wght@0,400;0,600;0,700;1,400&"
         "family=IBM+Plex+Mono:ital,wght@0,400;0,500;0,600;1,400&"
         "family=IBM+Plex+Sans:ital,wght@0,400;0,500;0,600;1,400&"
         "display=swap")
# woff2 sürümünü vermesi için Google'a yeni bir tarayıcı gibi görünmek gerekiyor
TARAYICI = ("Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 "
            "(KHTML, like Gecko) Chrome/120 Safari/537.36")

BLOK = re.compile(r"/\* (?P<altkume>[\w-]+) \*/\s*@font-face \{(?P<govde>.*?)\}", re.S)


def indir(adres: str) -> bytes:
    # curl: sistemin vekil ve sertifika ayarlarına uyar
    return subprocess.run(["curl", "-sSf", "-A", TARAYICI, adres],
                          check=True, capture_output=True).stdout


def ozellik(govde: str, ad: str) -> str:
    return re.search(ad + r":\s*([^;]+);", govde).group(1).strip()


def main() -> None:
    css = indir(ADRES).decode("utf-8")
    kurallar = []
    for e in BLOK.finditer(css):
        altkume, govde = e.group("altkume"), e.group("govde")
        if altkume not in ALTKUMELER:
            continue
        aile = ozellik(govde, "font-family").strip("'\"")
        bicem = ozellik(govde, "font-style")
        agirlik = ozellik(govde, "font-weight")
        aralik = ozellik(govde, "unicode-range")
        kaynak = re.search(r"url\(([^)]+)\)", govde).group(1)
        dosya = "%s-%s-%s-%s.woff2" % (aile.lower().replace(" ", "-"), agirlik, bicem, altkume)
        (KOK / dosya).write_bytes(indir(kaynak))
        kurallar.append(
            "@font-face {\n"
            f"  font-family: '{aile}';\n"
            f"  font-style: {bicem};\n"
            f"  font-weight: {agirlik};\n"
            "  font-display: swap;\n"
            f"  src: url('{dosya}') format('woff2');\n"
            f"  unicode-range: {aralik};\n"
            "}\n"
        )
        print(dosya)
    if not kurallar:
        sys.exit("Google Fonts'tan @font-face kuralı okunamadı; çıktı beklenen biçimde değil.")
    (KOK / "yazitipi.css").write_text(
        "/* Bu dosya indir.py tarafından üretildi; elle düzenlemeyin.\n"
        "   Bitter ve IBM Plex: SIL Open Font License 1.1 (bkz. kök LICENSE). */\n\n"
        + "\n".join(kurallar), encoding="utf-8")
    print(f"{len(kurallar)} yazı tipi dosyası + yazitipi.css -> {KOK}")


if __name__ == "__main__":
    main()
