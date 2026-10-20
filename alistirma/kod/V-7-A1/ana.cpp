#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-7-A1 · Yolu da yazın
// Çıktı: "s: u" satırları, sonra "1 -> n: 1 a b ... n (uzaklık u)"
using U = long long;
const U SONSUZ{(U)1e18};
using Hat = pair<U, Nokta>;

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  Dizi<Dizi<Hat>> hatlar(n + 1);
  for (int k{0}; k < m; ++k) { Nokta a, b; U s; cin >> a >> b >> s; hatlar[a].push_back({s, b}); }
  Dizi<U> uzaklik(n + 1, SONSUZ);
  Dizi<Nokta> nereden(n + 1, 0);
  // Dijkstra + nereden; yazdır
  return 0;
}
