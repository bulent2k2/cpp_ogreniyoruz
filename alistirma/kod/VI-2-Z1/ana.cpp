#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-2-Z1 · Toplamak yerine en küçüğü (PE 81)
// Çıktı: "en ucuz yol: 2427"
int main() {
  int n; cin >> n;
  Dizi<Dizi<S>> m(n, Dizi<S>(n));
  for (auto& satir : m) for (auto& x : satir) cin >> x;
  // t[r][c] = m[r][c] + min(üst, sol); kenarlarda tek seçenek
  return 0;
}
