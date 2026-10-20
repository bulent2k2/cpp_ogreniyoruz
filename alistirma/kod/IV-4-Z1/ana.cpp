// IV-4-Z1 · Güzel permütasyon
// Girdi: n. Çıktı: "üretimle: 1 3 5 2 6 4 7" ve "doğrudan: 2 4 6 1 3 5 7"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool guzelMi(const vector<int>& p) { /* komşu farkı 1 olan var mı? */ return false; }

int main() {
  int n{0}; cin >> n;
  // 1) üretim: 1..n sıralı, next_permutation ile ilk güzeli bul
  // 2) doğrudan: çiftler sonra tekler (n'e göre özel durumlar)
  return 0;
}
