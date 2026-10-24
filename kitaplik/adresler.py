# -*- coding: utf-8 -*-
"""
claude.ai adreslerini GitHub Pages adreslerine çevirir.

Bölüm kaynaklarında (bolumler/*.html, kitaplik/*.html) bağlantılar claude.ai
adresleriyle yazılıdır; çevrimiçi sayfalar bu hâliyle yayımlanır. Ama PDF ve
EPUB kâğıtta ya da e-kitap okuyucuda yaşar: oradan açılan kardeş kitapçık, defter,
dizin ve Kitaplık bağlantıları kalıcı ve herkese açık Pages adresine gitmeli.

baglantilar.txt satırları: <anahtar> <claude.ai adresi> <Pages adresi>
(kitapcik, kitapcik-koco, alistirma, alistirma-koco, kitaplik dizinlerinde).
Adresin ardındaki #çapa olduğu gibi kalır.

yap.py'ler (PDF için kitapcik-tam.html) ve epub.py'ler bunu içe aktarır;
docs/ aynasını üreten ayna.py ise göreli yola çevirdiği için kendi haritasını
kullanır.
"""
import pathlib

DEPO = pathlib.Path(__file__).resolve().parent.parent
DIZINLER = ["kitapcik", "kitapcik-koco", "alistirma", "alistirma-koco", "kitaplik"]


def harita() -> dict[str, str]:
    """claude.ai adresi -> Pages adresi."""
    h = {}
    for d in DIZINLER:
        dosya = DEPO / d / "baglantilar.txt"
        if not dosya.exists():
            continue
        for satir in dosya.read_text(encoding="utf-8").splitlines():
            parca = satir.split()
            if len(parca) >= 3 and not satir.lstrip().startswith("#"):
                h[parca[1]] = parca[2]
    return h


def cevir(metin: str) -> str:
    """Metindeki bilinen claude.ai adreslerini Pages adresine çevirir."""
    h = harita()
    for adres in sorted(h, key=len, reverse=True):
        metin = metin.replace(adres, h[adres])
    return metin
