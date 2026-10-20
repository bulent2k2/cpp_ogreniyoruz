# III-1-Z1 · Komut satırından girdi
# make        -> derle ve çalıştır
# make test   -> çıktını beklenen-cikti ile karşılaştır
hedef: derle calistir

derle:
	g++ -std=c++23 -Wall ana.cpp -o prog

calistir: derle
	./prog 3 14 15 92

test: derle
	./prog 3 14 15 92 > test-ciktisi
	diff beklenen-cikti test-ciktisi && echo "Doğru!"
	rm -rf test-ciktisi

temizle:
	rm -rf prog test-ciktisi

.PHONY: hedef derle calistir test temizle
