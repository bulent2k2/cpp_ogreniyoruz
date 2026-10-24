# Alıştırma defterinin çıktılarını üretir.
#   make          -> html + pdf + epub
#   make html     -> cikti/*.html (yayımlanabilir bölümler + birleşik belge)
#   make pdf      -> kitap/Keyifli-Alistirmalar-Cpp.pdf
#   make epub     -> kitap/Keyifli-Alistirmalar-Cpp.epub
#   make kapak    -> kitap/kapak-alistirma.png (PDF ve EPUB kapağı)
#   make denetle  -> epubcheck ile EPUB'ı doğrula
#   make sina     -> kod/ altındaki bütün alıştırma dizinlerini derle
#   make temizle  -> üretilen html'leri ve derlenmiş programları sil

KITAP = ../kitap/Keyifli-Alistirmalar-Cpp

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

sina:
	$(MAKE) -C kod derle

temizle:
	rm -rf cikti
	$(MAKE) -C kod temizle

.PHONY: hepsi html pdf epub kapak denetle sina temizle
