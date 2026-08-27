# Kitapçıktaki bütün örnek programları derler ve çalıştırır.
# Girdi bekleyen iki program (03-tahmin, 41-dijkstra) çalıştırma
# listesinin dışında; onları elle deneyin.

KAYNAKLAR = $(wildcard *.cpp)
PROGRAMLAR = $(patsubst %.cpp,bin/%,$(KAYNAKLAR))
GIRDISIZ = $(filter-out bin/03-tahmin bin/41-dijkstra,$(PROGRAMLAR))

hedef: derle

derle: bin $(PROGRAMLAR)

bin:
	mkdir -p bin

bin/%: %.cpp | bin
	g++ -std=c++23 -Wall $< -o $@

calistir: derle
	@for p in $(GIRDISIZ); do \
	  echo "=== $$p ==="; ./$$p; echo; \
	done

# girdi bekleyen örnek: Dijkstra
dijkstra: bin/41-dijkstra
	printf "3 4\n1 2 6\n1 3 2\n3 2 3\n1 3 4\n" | ./bin/41-dijkstra

temizle:
	rm -rf bin

.PHONY: hedef derle calistir dijkstra temizle
