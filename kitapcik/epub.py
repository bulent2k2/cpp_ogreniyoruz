#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Kitapçığı EPUB 3 dosyasına çevirir. Dışarıdan kütüphane gerekmiyor.

Girdi : kitapcik/bolumler/*.html + kitapcik/epub.css (+ varsa kitap/kapak.png)
Çıktı : kitap/Programlamaya-ve-Algoritmalara-Keyifli-Bir-Baslangic.epub

Kullanım:  python3 kitapcik/epub.py
"""

import mimetypes
import pathlib
import re
import xml.etree.ElementTree as ET
import zipfile

import yap  # bölüm listesi ve gövde birleştirme mantığı oradan geliyor

KOK = pathlib.Path(__file__).resolve().parent
RESIM = KOK / "resim"
# bölüm metinlerindeki ../resim/<ad> yolları EPUB içinde resim/<ad> oluyor
RESIM_DESENI = re.compile(r'src="\.\./resim/([^"]+)"')
CIKTI = KOK.parent / "kitap" / "Programlamaya-ve-Algoritmalara-Keyifli-Bir-Baslangic.epub"

BASLIK = "Programlamaya ve Algoritmalara Keyifli Bir Başlangıç"
YAZAR = "Bülent Başaran"
DIL = "tr"
# Kitabın kimliği ve sürüm tarihi sabit: aynı kaynaktan hep aynı dosya çıksın.
# Depo adresinden türetilmiş, değişmeyen bir UUID (uuid5).
KIMLIK = "urn:uuid:7188b95a-e853-5f6a-9f5c-fa048b5e0f2e"
SURUM = "2026-08-27T00:00:00Z"
ZIP_TARIHI = (2026, 8, 27, 0, 0, 0)

HAKLAR = (
    "Metin: CC BY-SA 4.0. Örnek programlar: MIT. "
    "Telif hakkı (c) 2024-2026 Bülent Başaran."
)

# XML'de tanımlı olmayan adlandırılmış varlıkları gerçek harflere çeviriyoruz.
# &lt; &gt; &amp; &quot; &apos; dokunulmadan kalıyor; onlar XML'de geçerli.
VARLIKLAR = {
    "&mdash;": "—", "&ndash;": "–",
    "&ldquo;": "“", "&rdquo;": "”",
    "&lsquo;": "‘", "&rsquo;": "’",
    "&hellip;": "…", "&nbsp;": " ",
    "&infin;": "∞", "&times;": "×",
    "&middot;": "·", "&rarr;": "→", "&larr;": "←",
    "&minus;": "−",
}

# XML'de tanımlı olan beşli; bunlara dokunmuyoruz
XML_VARLIKLARI = {"lt", "gt", "amp", "quot", "apos"}
KALAN_VARLIK = re.compile(r"&([a-zA-Z][a-zA-Z0-9]*);")

XHTML = """<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="{dil}" lang="{dil}">
<head>
<meta charset="utf-8"/>
<title>{baslik}</title>
<link rel="stylesheet" type="text/css" href="bicem.css"/>
</head>
<body>
{govde}
</body>
</html>
"""


def dosya_adi(slug: str) -> str:
    return "b%02d.xhtml" % yap.SIRA.index(slug)


def xhtml_yap(parca: str) -> str:
    """HTML parçasını iyi biçimli XHTML'e çevirir."""
    for adi, harf in VARLIKLAR.items():
        parca = parca.replace(adi, harf)
    # boş öğeler XHTML'de kapanmak zorunda
    parca = re.sub(r"<br\s*/?>", "<br/>", parca)
    parca = re.sub(r"<(hr|img|meta|link)([^>]*?)/?>", r"<\1\2/>", parca)

    # Haritada olmayan bir varlık kalmışsa XML çözümleyici anlaşılmaz bir
    # hata verir. Onun yerine burada adıyla söyleyelim.
    kalan = {a for a in KALAN_VARLIK.findall(parca) if a not in XML_VARLIKLARI}
    if kalan:
        raise SystemExit(
            "VARLIKLAR haritasına eklenmesi gereken adlar: "
            + ", ".join(f"&{a};" for a in sorted(kalan))
        )
    return parca


def denetle(ad: str, metin: str) -> None:
    """XML iyi biçimli mi? Değilse hemen hata versin, sessizce bozuk EPUB üretmeyelim."""
    try:
        ET.fromstring(metin.replace("<!DOCTYPE html>", ""))
    except ET.ParseError as hata:
        raise SystemExit(f"{ad}: XHTML iyi biçimli değil -> {hata}")


def bolum_sayfalari() -> tuple[list[tuple[str, str, str]], list[str]]:
    """(dosya adı, başlık, xhtml) üçlüleri ve kullanılan resimlerin listesi."""
    baglantilar = {s: dosya_adi(s) for s in yap.SIRA}
    sayfalar, resimler = [], []
    for slug, _kisa, baslik, _tanit in yap.BOLUMLER:
        govde = yap.kur(slug, baglantilar, tam=False)
        for ad in RESIM_DESENI.findall(govde):
            if ad not in resimler:
                resimler.append(ad)
        # kapak resmi EPUB'da zaten OEBPS/kapak.png olarak duruyor
        govde = govde.replace('src="../../kitap/kapak.png"', 'src="kapak.png"')
        govde = RESIM_DESENI.sub(r'src="resim/\1"', govde)
        sayfa = XHTML.format(dil=DIL, baslik=baslik, govde=xhtml_yap(govde))
        denetle(slug, sayfa)
        sayfalar.append((dosya_adi(slug), baslik, sayfa))
    return sayfalar, resimler


def kapak_sayfasi(kapak_var: bool) -> str:
    if kapak_var:
        govde = ('<section epub:type="cover" class="kapak-sayfasi" '
                 'xmlns:epub="http://www.idpf.org/2007/ops">\n'
                 f'<img src="kapak.png" alt="{BASLIK}"/>\n</section>')
    else:
        govde = ('<section class="kapak-sayfasi">\n'
                 f"<h1>{BASLIK}</h1>\n<p>{YAZAR}</p>\n</section>")
    sayfa = XHTML.format(dil=DIL, baslik=BASLIK, govde=govde)
    denetle("kapak", sayfa)
    return sayfa


def nav_sayfasi(sayfalar) -> str:
    ogeler = "\n".join(
        f'    <li><a href="{ad}">{baslik}</a></li>' for ad, baslik, _ in sayfalar
    )
    govde = (
        '<nav xmlns:epub="http://www.idpf.org/2007/ops" epub:type="toc" id="toc">\n'
        "  <h1>İçindekiler</h1>\n  <ol>\n" + ogeler + "\n  </ol>\n</nav>"
    )
    sayfa = XHTML.format(dil=DIL, baslik="İçindekiler", govde=govde)
    denetle("nav", sayfa)
    return sayfa


def opf(sayfalar, kapak_var: bool, resimler=()) -> str:
    manifest = [
        '    <item id="nav" href="nav.xhtml" media-type="application/xhtml+xml" '
        'properties="nav"/>',
        '    <item id="bicem" href="bicem.css" media-type="text/css"/>',
        '    <item id="kapaksayfa" href="kapak.xhtml" '
        'media-type="application/xhtml+xml"/>',
        '    <item id="ncx" href="toc.ncx" media-type="application/x-dtbncx+xml"/>',
    ]
    if kapak_var:
        manifest.append(
            '    <item id="kapakresmi" href="kapak.png" media-type="image/png" '
            'properties="cover-image"/>'
        )
    for i, ad in enumerate(resimler):
        tur = mimetypes.guess_type(ad)[0] or "image/jpeg"
        manifest.append(
            f'    <item id="r{i}" href="resim/{ad}" media-type="{tur}"/>'
        )
    omurga = ['    <itemref idref="kapaksayfa"/>', '    <itemref idref="nav"/>']
    for i, (ad, _baslik, _icerik) in enumerate(sayfalar):
        manifest.append(
            f'    <item id="b{i}" href="{ad}" media-type="application/xhtml+xml"/>'
        )
        omurga.append(f'    <itemref idref="b{i}"/>')

    return f"""<?xml version="1.0" encoding="utf-8"?>
<package xmlns="http://www.idpf.org/2007/opf" version="3.0"
         unique-identifier="kitapkimlik" xml:lang="{DIL}">
  <metadata xmlns:dc="http://purl.org/dc/elements/1.1/">
    <dc:identifier id="kitapkimlik">{KIMLIK}</dc:identifier>
    <dc:title>{BASLIK}</dc:title>
    <dc:creator id="yazar">{YAZAR}</dc:creator>
    <dc:language>{DIL}</dc:language>
    <dc:date>2026</dc:date>
    <dc:publisher>cpp_ogreniyoruz</dc:publisher>
    <dc:rights>{HAKLAR}</dc:rights>
    <dc:description>Fen Lisesi öğrencileri için C++ ve algoritmalara altı bölümlük bir giriş.</dc:description>
    <dc:subject>Programlama</dc:subject>
    <dc:subject>Algoritmalar</dc:subject>
    <dc:subject>C++</dc:subject>
    <meta refines="#yazar" property="role" scheme="marc:relators">aut</meta>
    <meta property="dcterms:modified">{SURUM}</meta>
  </metadata>
  <manifest>
{chr(10).join(manifest)}
  </manifest>
  <spine toc="ncx">
{chr(10).join(omurga)}
  </spine>
</package>
"""


def ncx(sayfalar) -> str:
    """Eski okuyucular için EPUB 2 içindekiler dosyası."""
    noktalar = []
    for i, (ad, baslik, _icerik) in enumerate(sayfalar, start=1):
        noktalar.append(
            f'    <navPoint id="np{i}" playOrder="{i}">\n'
            f"      <navLabel><text>{baslik}</text></navLabel>\n"
            f'      <content src="{ad}"/>\n'
            f"    </navPoint>"
        )
    return f"""<?xml version="1.0" encoding="utf-8"?>
<ncx xmlns="http://www.daisy.org/z3986/2005/ncx/" version="2005-1">
  <head>
    <meta name="dtb:uid" content="{KIMLIK}"/>
    <meta name="dtb:depth" content="1"/>
    <meta name="dtb:totalPageCount" content="0"/>
    <meta name="dtb:maxPageNumber" content="0"/>
  </head>
  <docTitle><text>{BASLIK}</text></docTitle>
  <navMap>
{chr(10).join(noktalar)}
  </navMap>
</ncx>
"""


CONTAINER = """<?xml version="1.0" encoding="utf-8"?>
<container version="1.0" xmlns="urn:oasis:names:tc:opendocument:xmlns:container">
  <rootfiles>
    <rootfile full-path="OEBPS/content.opf" media-type="application/oebps-package+xml"/>
  </rootfiles>
</container>
"""


def yaz(z: zipfile.ZipFile, ad: str, veri, sikistir=True) -> None:
    bilgi = zipfile.ZipInfo(ad, date_time=ZIP_TARIHI)
    bilgi.compress_type = zipfile.ZIP_DEFLATED if sikistir else zipfile.ZIP_STORED
    bilgi.external_attr = 0o644 << 16
    z.writestr(bilgi, veri)


def main() -> None:
    kapak_png = CIKTI.parent / "kapak.png"   # kitap/kapak.png
    kapak_var = kapak_png.exists()

    sayfalar, resimler = bolum_sayfalari()
    eksik = [a for a in resimler if not (RESIM / a).exists()]
    if eksik:
        raise SystemExit("resim bulunamadı: " + ", ".join(eksik))

    denetle("container", CONTAINER)
    denetle("opf", opf(sayfalar, kapak_var, resimler))
    denetle("ncx", ncx(sayfalar))

    CIKTI.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(CIKTI, "w") as z:
        # mimetype ilk sıradaki ve sıkıştırılmamış dosya olmak zorunda
        yaz(z, "mimetype", "application/epub+zip", sikistir=False)
        yaz(z, "META-INF/container.xml", CONTAINER)
        yaz(z, "OEBPS/content.opf", opf(sayfalar, kapak_var, resimler))
        yaz(z, "OEBPS/toc.ncx", ncx(sayfalar))
        yaz(z, "OEBPS/nav.xhtml", nav_sayfasi(sayfalar))
        yaz(z, "OEBPS/kapak.xhtml", kapak_sayfasi(kapak_var))
        yaz(z, "OEBPS/bicem.css", (KOK / "epub.css").read_text(encoding="utf-8"))
        if kapak_var:
            yaz(z, "OEBPS/kapak.png", kapak_png.read_bytes())
        for ad in resimler:
            yaz(z, "OEBPS/resim/" + ad, (RESIM / ad).read_bytes())
        for ad, _baslik, icerik in sayfalar:
            yaz(z, "OEBPS/" + ad, icerik)

    boyut = CIKTI.stat().st_size / 1024
    print(f"EPUB yazıldı: {CIKTI}  ({boyut:.0f} KB, {len(sayfalar)} bölüm, "
          f"{len(resimler)} resim{', kapaklı' if kapak_var else ', kapaksız'})")


if __name__ == "__main__":
    main()
