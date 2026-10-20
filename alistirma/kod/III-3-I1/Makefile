hedef: derle çalıştır

derle: prog

prog: ana.o asal.o
	c++ -std=c++23 -Wall ana.o asal.o -o prog

ana.o: ana.cpp asal.h
	c++ -std=c++23 -Wall -c ana.cpp

asal.o: asal.cpp asal.h
	c++ -std=c++23 -Wall -c asal.cpp

çalıştır: prog
	./prog 60

test: prog
	./prog 360 > test-ciktisi
	diff beklenen-cikti test-ciktisi && echo "Doğru!"
	rm -f test-ciktisi

temizle:
	rm -f prog *.o test-ciktisi

.PHONY: hedef derle çalıştır test temizle
