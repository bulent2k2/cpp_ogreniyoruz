# Koco kitapçığının bütün çıktılarını üretir.
#   make          -> html + pdf + epub
#   make html     -> cikti/*.html (yayımlanabilir bölümler + birleşik belge)
#   make pdf      -> kitap/...-Islevsel-Bir-Giris.pdf
#   make epub     -> kitap/...-Islevsel-Bir-Giris.epub
#   make kapak    -> kitap/kapak-koco.png (epub ve pdf kapağı)
#   make denetle  -> epubcheck ile doğrula
#   make temizle  -> üretilen html'leri sil

KITAP = ../kitap/Programlamaya-ve-Algoritmalara-Keyifli-ve-Islevsel-Bir-Giris

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
