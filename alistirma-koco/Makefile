# Koco cildinin çıktılarını üretir.
#   make          -> html + pdf + epub
#   make html     -> cikti/*.html (yayımlanabilir bölümler + birleşik belge)
#   make pdf      -> kitap/Keyifli-Alistirmalar-Koco.pdf
#   make epub     -> kitap/Keyifli-Alistirmalar-Koco.epub
#   make kapak    -> kitap/kapak-alistirma-koco.png (PDF ve EPUB kapağı)
#   make denetle  -> epubcheck ile EPUB'ı doğrula
#   make test     -> konsol alıştırmalarını Koco'nun Türkçe derleyicisiyle sına (bkz. konsol/)
#   make temizle  -> üretilen html'leri sil

KITAP = ../kitap/Keyifli-Alistirmalar-Koco

hepsi: html pdf epub

html:
	python3 yap.py

pdf: html
	node pdf.mjs

epub: html
	python3 epub.py

kapak:
	node kapak.mjs

denetle: epub
	python3 -m epubcheck $(KITAP).epub

test:
	$(MAKE) -C kod test

temizle:
	rm -rf cikti
	$(MAKE) -C kod temizle

.PHONY: hepsi html pdf epub kapak denetle test temizle
