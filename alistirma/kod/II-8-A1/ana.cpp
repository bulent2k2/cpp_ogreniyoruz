// II-8-A1 · Toplamın taştığı yer
// Girdi: n, n artı sayı. Çıktı: "toplam k. sayıda int'i aştı" (ya da "taşma yok"), "toplam: ..."
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
  int n{0}; cin >> n;
  vector<int> sayilar(n);
  for (int& s : sayilar) cin >> s;
  // long long toplam; her adımda numeric_limits<int>::max() ile karşılaştırın
  return 0;
}
