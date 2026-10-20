// IV-1-Z1 · Hanoi'yi saymak
// Girdi: n. Çıktı: her disk için "k. disk: m kere", sonra "toplam ... adım"
#include <iostream>
#include <vector>
using namespace std;

vector<long long> kacKere;   // kacKere[k]: k. disk kaç kere taşındı

void tasi(int n, int kaynak, int hedef, int yardimci) {
  // buradan devam edin
}

int main() {
  int n{0}; cin >> n;
  kacKere.assign(n + 1, 0);
  tasi(n, 1, 3, 2);
  // yazdırın
  return 0;
}
