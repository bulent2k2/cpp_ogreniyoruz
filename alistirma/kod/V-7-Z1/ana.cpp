#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-7-Z1 · Eski kayıt
// Çıktı: uzaklıklar; "atlanan eski kayıt: k"; "satırsız: aynı/FARKLI, gevşetilen hat: a yerine b"
using U = long long;
const U SONSUZ{(U)1e18};
using Hat = pair<U, Nokta>;

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  Dizi<Dizi<Hat>> hatlar(n + 1);
  for (int k{0}; k < m; ++k) { Nokta a, b; U s; cin >> a >> b >> s; hatlar[a].push_back({s, b}); }
  // iki sürüm: satırlı (atlanan sayar) ve satırsız (gevşetme sayar)
  return 0;
}
