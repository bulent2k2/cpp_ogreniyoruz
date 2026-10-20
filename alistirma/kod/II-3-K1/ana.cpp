// II-3-K1 · İkiye bölünür mü?
// Girdi: n, n sayı. Çıktı: "Evet, a ve a" ya da "Hayır"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n{0}; cin >> n;
  vector<int> d(n);
  for (int& x : d) cin >> x;
  // buradan devam edin: 0 .. (1 << n) - 1 desenleri
  return 0;
}
