#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-2-K1 · Yolu geri kurmak
// Çıktı: "yol: 131 201 ... 331" ve "toplam: 2427"
int main() {
  int n; cin >> n;
  Dizi<Dizi<S>> m(n, Dizi<S>(n));
  for (auto& satir : m) for (auto& x : satir) cin >> x;
  // VI-2-Z1'in çizelgesi, sonra sağ alttan geriye yürüyün
  return 0;
}
