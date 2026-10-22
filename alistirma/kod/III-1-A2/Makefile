# III-1-A2 · İki adımda derleme
# derle kuralını siz yazın: önce .o dosyaları (-c), sonra bağlama
hedef: derle calistir

derle:
	@echo "derle kuralı henüz yazılmadı"; exit 1

calistir: derle
	./prog

test: derle
	./prog > test-ciktisi
	diff -Z --strip-trailing-cr beklenen-cikti test-ciktisi && echo "Doğru!"
	rm -rf test-ciktisi

temizle:
	rm -rf prog *.o test-ciktisi

.PHONY: hedef derle calistir test temizle
