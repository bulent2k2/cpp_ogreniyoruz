# Bütün alıştırma dizinlerini sırayla gezer.
#   make derle    -> her dizinde g++ (başlangıç dosyalarının bir kısmı bilerek derlenmez)
#   make test     -> her dizinde make test; sonunda özet
#   make temizle  -> prog ve test-ciktisi dosyalarını sil

DIZINLER = $(sort $(dir $(wildcard */Makefile)))

derle:
	@for d in $(DIZINLER); do \
	  printf "%-10s " $$d; \
	  if $(MAKE) -s -C $$d derle >/dev/null 2>&1; then echo derlendi; else echo "derlenmedi"; fi; \
	done

test:
	@dogru=0; yanlis=0; \
	for d in $(DIZINLER); do \
	  if [ -f $$d/beklenen-cikti ]; then \
	    printf "%-10s " $$d; \
	    if $(MAKE) -s -C $$d test >/dev/null 2>&1; then echo "doğru"; dogru=$$((dogru+1)); \
	    else echo "henüz değil"; yanlis=$$((yanlis+1)); fi; \
	  fi; \
	done; \
	echo "---"; echo "$$dogru doğru, $$yanlis henüz değil"

temizle:
	@for d in $(DIZINLER); do $(MAKE) -s -C $$d temizle 2>/dev/null || true; done

.PHONY: derle test temizle
