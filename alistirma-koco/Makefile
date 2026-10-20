# Koco cildinin çıktılarını üretir.
#   make          -> html
#   make html     -> cikti/*.html (yayımlanabilir bölümler + birleşik belge)
#   make test     -> konsol alıştırmalarını Koco'nun Türkçe derleyicisiyle sına (bkz. konsol/)
#   make temizle  -> üretilen html'leri sil

hepsi: html

html:
	python3 yap.py

test:
	$(MAKE) -C kod test

temizle:
	rm -rf cikti
	$(MAKE) -C kod temizle

.PHONY: hepsi html test temizle
