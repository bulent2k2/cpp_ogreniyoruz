# II-1-A1 · Toplam, en büyük, en küçük
# make        -> derle ve çalıştır
# make test   -> çıktını beklenen-cikti ile karşılaştır
hedef: derle calistir

derle:
	g++ -std=c++23 -Wall ana.cpp -o prog

calistir: derle
	./prog < girdi

test: derle
	./prog < girdi > test-ciktisi
	diff beklenen-cikti test-ciktisi && echo "Doğru!"
	rm -rf test-ciktisi

temizle:
	rm -rf prog test-ciktisi

.PHONY: hedef derle calistir test temizle
