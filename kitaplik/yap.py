#!/usr/bin/env python3
"""Keyifli Kitaplık sayfalarını cikti/ dizinine tam HTML olarak yazar.

Kaynak dosyalar (kitaplik.html, dizin.html, inceleme.html) yayımlanan
sayfaların kaynağıdır: <title> ve <style> ile başlar; <html>, <head> ve
<body> sarmalayıcısı yayım sırasında eklenir. Bu betik aynı sarmalayıcıyı
ekler ve dizin-veri.js'yi yanına kopyalar; böylece sayfalar yerelde ya da
başka bir sunucuda (örneğin GitHub Pages) da açılır.

Kullanım: python3 yap.py
"""
import re
import shutil
from pathlib import Path

BURASI = Path(__file__).resolve().parent
CIKTI = BURASI / "cikti"
SAYFALAR = ["kitaplik.html", "dizin.html", "inceleme.html"]


def sar(kaynak: str) -> str:
    """Sayfa kaynağını <html> ... </html> ile sarmalar."""
    baslik = re.search(r"<title>(.*?)</title>", kaynak, re.S)
    ad = baslik.group(1).strip() if baslik else "Keyifli Kitaplık"
    govde = re.sub(r"<title>.*?</title>\s*", "", kaynak, count=1, flags=re.S)
    govde = re.sub(r'<meta name="claude:[^"]*"[^>]*>\s*', "", govde, count=1)
    return (
        '<!doctype html>\n<html lang="tr">\n<head>\n'
        '<meta charset="utf-8">\n'
        '<meta name="viewport" content="width=device-width, initial-scale=1, viewport-fit=cover">\n'
        f"<title>{ad}</title>\n"
        "<style>:root{padding-top:env(safe-area-inset-top,0px);padding-bottom:env(safe-area-inset-bottom,0px)}</style>\n"
        "</head>\n<body>\n" + govde + "\n</body>\n</html>\n"
    )


def main() -> None:
    CIKTI.mkdir(exist_ok=True)
    for ad in SAYFALAR:
        kaynak = (BURASI / ad).read_text(encoding="utf-8")
        (CIKTI / ad).write_text(sar(kaynak), encoding="utf-8")
        print("yazıldı:", CIKTI / ad)
    shutil.copy(BURASI / "dizin-veri.js", CIKTI / "dizin-veri.js")
    print("kopyalandı:", CIKTI / "dizin-veri.js")


if __name__ == "__main__":
    main()
