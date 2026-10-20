# Beklenen çıktısı olan alıştırma dizinlerini konsol düzeneğiyle sınar.
#   make test     -> her dizinde ana.kojo'yu çalıştır, beklenen-cikti ile karşılaştır
#   make temizle  -> test-ciktisi dosyalarını sil
# Düzenek: ../konsol/koco.sh (bir kere ../konsol/kur.sh ile kurulur; Java gerekir).
# Çizim alıştırmalarının beklenen çıktısı yok; onlar iKojo'da gözle sınanır.

KOCO = ../konsol/koco.sh
DIZINLER = $(sort $(dir $(wildcard */beklenen-cikti)))

test:
	@dogru=0; yanlis=0; \
	for d in $(DIZINLER); do \
	  printf "%-10s " $$d; \
	  g=/dev/null; [ -f $$d/girdi ] && g=$$d/girdi; \
	  if $(KOCO) $$d/ana.kojo $$g > $$d/test-ciktisi 2>/dev/null && diff -q $$d/beklenen-cikti $$d/test-ciktisi >/dev/null; then \
	    echo "doğru"; dogru=$$((dogru+1)); rm -f $$d/test-ciktisi; \
	  else echo "henüz değil"; yanlis=$$((yanlis+1)); fi; \
	done; \
	echo "---"; echo "$$dogru doğru, $$yanlis henüz değil"

temizle:
	@rm -f */test-ciktisi

.PHONY: test temizle
