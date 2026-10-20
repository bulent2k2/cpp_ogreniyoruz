#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-5-Z1 · Döngü sırasını bozun
// Çıktı: "k en dışta: 2->1 = 3" ve "k en içte : 2->1 = -1"
const S SONSUZ{(S)1e15};
using Matris = Dizi<Dizi<S>>;

S dogru(Matris f, int n) { /* k, a, b */ return 0; }
S bozuk(Matris f, int n) { /* a, b, k */ return 0; }

int main() {
  int n, m; cin >> n >> m;
  Matris f(n + 1, Dizi<S>(n + 1, SONSUZ));
  for (int a{1}; a <= n; ++a) f[a][a] = 0;
  for (int i{0}; i < m; ++i) { int a, b; S u; cin >> a >> b >> u; f[a][b] = min(f[a][b], u); }
  cout << "k en dışta: 2->1 = " << dogru(f, n) << endl;
  cout << "k en içte : 2->1 = " << bozuk(f, n) << endl;
  return 0;
}
