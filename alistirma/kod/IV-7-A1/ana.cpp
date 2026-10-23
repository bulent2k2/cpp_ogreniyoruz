// IV-7-A1 · Altküme toplamları, kümede
// Çıktı: "11 farklı toplam" sonra "0 1 2 ... 10"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> kume;
set<int> toplamlar;

void uret(size_t k, int toplam) {
  // taban: toplamlar.insert(toplam); ALMA / AL
}

int main() {
  int n{0}; cin >> n;
  kume.resize(n);
  for (int& x : kume) cin >> x;
  uret(0, 0);
  // yazdır
  return 0;
}
