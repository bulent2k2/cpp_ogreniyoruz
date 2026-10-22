hedef: derle calistir

derle:
	g++ -std=c++23 ana.cpp -o prog

ayikla:   # hata ararken: temizleyicilerle derle (bkz. kitapçık III)
	g++ -std=c++23 -Wall -g -fsanitize=address,undefined ana.cpp -o prog

calistir:
	./prog a b c Merhaba "ya bu nedir?" 3 14 2.7181

test:
	./prog a b c Merhaba "ya bu nedir?" 3 14 2.7181 > test-ciktisi
	diff beklenen-cikti test-ciktisi
	rm -rf test-ciktisi

temizle:
	rm -rf prog test-ciktisi

