#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-4-Z1 · Genel çizgede en kısa yol
// Çıktı: "p: d" satırları (ulaşılamaz: -1), sonra "1 -> n: 1 a b ... n"
int main() {
  int n{0}, m{0};
  cin >> n >> m;
  Dizi<Dizi<Nokta>> komsular(n + 1);
  for (int k{0}; k < m; ++k) { Nokta a, b; cin >> a >> b; komsular[a].push_back(b); komsular[b].push_back(a); }
  Dizi<int> uzaklik(n + 1, -1);
  Dizi<Nokta> nereden(n + 1, 0);
  // kuyrukla gez; uzaklıkları yaz; yolu geri sar
  return 0;
}
