# V-5-Z1 · Gidiş dönüş
# make        -> derle ve çalıştır
# make test   -> çıktını beklenen-cikti ile karşılaştır
hedef: derle calistir

derle:
	g++ -std=c++23 -Wall ana.cpp -o prog

calistir: derle
	./prog < girdi

test: derle
	./prog < girdi > test-ciktisi
	diff -Z --strip-trailing-cr beklenen-cikti test-ciktisi && echo "Doğru!"
	rm -rf test-ciktisi

temizle:
	rm -rf prog test-ciktisi

.PHONY: hedef derle calistir test temizle
