# III-3-A2 · Her gün bozulan test
# make        -> derle ve çalıştır
# make test   -> çıktını beklenen-cikti ile karşılaştır
hedef: derle calistir

derle:
	g++ -std=c++23 -Wall ana.cpp -o prog

calistir: derle
	./prog 2026 10 20

test: derle
	./prog 2026 10 20 > test-ciktisi
	diff beklenen-cikti test-ciktisi && echo "Doğru!"
	rm -rf test-ciktisi

temizle:
	rm -rf prog test-ciktisi

.PHONY: hedef derle calistir test temizle
