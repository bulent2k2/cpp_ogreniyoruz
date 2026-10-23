# Kitaplık sayfaları ve GitHub Pages aynası.
#   make          -> html
#   make html     -> cikti/kitaplik.html, cikti/dizin.html, cikti/inceleme.html
#   make ayna     -> ../docs/ : dört eser + bu sayfalar, GitHub Pages için
#   make temizle  -> üretilen html'leri sil

hepsi: html

html:
	python3 yap.py

ayna:
	python3 ayna.py

temizle:
	rm -rf cikti

.PHONY: hepsi html ayna temizle
