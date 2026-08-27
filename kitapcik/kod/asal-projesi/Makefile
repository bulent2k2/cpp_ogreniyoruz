hedef: derle çalıştır

derle: prog

prog: ana.o asal.o
	c++ -std=c++23 ana.o asal.o -o prog

ana.o: ana.cpp asal.h
	c++ -std=c++23 -c ana.cpp

asal.o: asal.cpp asal.h
	c++ -std=c++23 -c asal.cpp

çalıştır: prog
	./prog 60

test: prog
	./prog 360 > test-ciktisi
	diff beklenen-cikti test-ciktisi
	rm -f test-ciktisi
	@echo "TEST GEÇTİ"

temizle:
	rm -f prog *.o test-ciktisi
