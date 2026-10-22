# III-1-A1 · -Wall ne diyor?
# make        -> derle ve çalıştır
# make test   -> çıktını beklenen-cikti ile karşılaştır
hedef: derle calistir

derle:
	g++ -std=c++23 -Wall -Werror ana.cpp -o prog

calistir: derle
	./prog

test: derle
	./prog > test-ciktisi
	diff -Z --strip-trailing-cr beklenen-cikti test-ciktisi && echo "Doğru!"
	rm -rf test-ciktisi

temizle:
	rm -rf prog test-ciktisi

.PHONY: hedef derle calistir test temizle
