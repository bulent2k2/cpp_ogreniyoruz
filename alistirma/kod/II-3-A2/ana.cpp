// II-3-A2 · Kesişim, birleşim, fark
// Girdi: n, n öğe, m, m öğe. Çıktı: Kesişim / Birleşim / Fark
#include <iostream>
#include <set>
using namespace std;

set<int> oku() {
  int n{0}; cin >> n;
  set<int> k;
  for (int i{0}; i < n; ++i) { int x; cin >> x; k.insert(x); }
  return k;
}

int main() {
  set<int> a{oku()}, b{oku()};
  // buradan devam edin
  return 0;
}
