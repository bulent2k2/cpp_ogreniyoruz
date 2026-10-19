# Alıştırma defterinin çıktılarını üretir.
#   make          -> html (şimdilik; pdf ve epub bölümler çoğalınca)
#   make html     -> cikti/*.html (yayımlanabilir bölümler + birleşik belge)
#   make sina     -> kod/ altındaki bütün alıştırma dizinlerini derle
#   make temizle  -> üretilen html'leri ve derlenmiş programları sil

hepsi: html

html:
	python3 yap.py

sina:
	$(MAKE) -C kod derle

temizle:
	rm -rf cikti
	$(MAKE) -C kod temizle

.PHONY: hepsi html sina temizle
