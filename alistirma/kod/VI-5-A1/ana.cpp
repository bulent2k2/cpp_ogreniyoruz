#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-5-A1 · Kanıtı sağlayın
// Çıktı: "dizi: 12 hedefte eşleşti" ve "küme: 12 hedefte eşleşti" (eşleşmeyen varsa hangileri)
Dizi<S> paralar{2, 3, 5};

S diziKaba(int kalan) {           // kalan 0: bir dizi bulundu
  return 0;
}
S kumeKaba(int kalan, size_t ilk) {   // ilk: bu adımda kullanılabilecek en küçük para sırası
  return 0;
}

int main() {
  const int hedef{12};
  Dizi<S> d(hedef + 1, 0), k(hedef + 1, 0);
  d[0] = k[0] = 1;
  for (int x{1}; x <= hedef; ++x) for (S p : paralar) if (x - p >= 0) d[x] += d[x - p];
  for (S p : paralar) for (int x{(int)p}; x <= hedef; ++x) k[x] += k[x - p];
  // 1..hedef için karşılaştırın
  return 0;
}
