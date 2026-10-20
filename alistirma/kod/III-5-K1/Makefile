# III-5-K1 · -O2 farkı
#   make yavas  -> -O0 ile derle ve çalıştır
#   make hizli  -> -O2 ile derle ve çalıştır
hedef: yavas hizli

derle:
	g++ -std=c++23 -Wall -O0 ana.cpp -o prog-O0
	g++ -std=c++23 -Wall -O2 ana.cpp -o prog-O2

yavas:
	g++ -std=c++23 -Wall -O0 ana.cpp -o prog-O0
	@echo "--- -O0 ---"; ./prog-O0

hizli:
	g++ -std=c++23 -Wall -O2 ana.cpp -o prog-O2
	@echo "--- -O2 ---"; ./prog-O2

temizle:
	rm -f prog-O0 prog-O2

.PHONY: hedef derle yavas hizli temizle
