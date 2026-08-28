# Kitapçığın bütün çıktılarını üretir.
#   make          -> html + pdf + epub
#   make html     -> cikti/*.html (yayımlanabilir bölümler + birleşik belge)
#   make pdf      -> kitap/...-Baslangic.pdf
#   make epub     -> kitap/...-Baslangic.epub
#   make kapak    -> kitap/kapak.png (epub kapağı)
#   make denetle  -> epubcheck ile doğrula
#   make temizle  -> üretilen html'leri sil

KITAP = ../kitap/Programlamaya-ve-Algoritmalara-Keyifli-Bir-Baslangic

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

temizle:
	rm -rf cikti

.PHONY: hepsi html pdf epub kapak denetle temizle
