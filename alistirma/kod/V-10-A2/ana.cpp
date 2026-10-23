// V-10-A2 · Odaları özyinelemeyle sayın
// Çıktı: "4 oda" ve "en büyük oda: 4 kare"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> harita;
int S{0}, K{0};

int doldur(int s, int k) {
  // taban: sınır dışı / duvar / dolu -> 0
  // işaretle ('#' yap), 1 + dört komşu
  return 0;
}

int main() {
  cin >> S >> K;
  harita.resize(S);
  for (string& satir : harita) cin >> satir;
  // her boş kareden doldur başlat; say ve en büyüğü tut
  return 0;
}
