#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-7-A2 · Dijkstra'yı kırın
// Çıktı: "Dijkstra : u1 ... u5" ve "gevşetme : u1 ... u5"
using U = long long;
const U SONSUZ{(U)1e18};
using Hat = pair<U, Nokta>;
struct Bag { Nokta a, b; U x; };

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  Dizi<Dizi<Hat>> hatlar(n + 1);
  Dizi<Bag> baglar;
  for (int k{0}; k < m; ++k) { Nokta a, b; U x; cin >> a >> b >> x; hatlar[a].push_back({x, b}); baglar.push_back({a, b, x}); }
  // 1) klasik Dijkstra: bitti[] dizisi; bitmiş şehre dokunma (kitapçığın 'eski kayıt' sürümü DEĞİL)
  // 2) n-1 tur: her bağ için uzaklik[b] = min(uzaklik[b], uzaklik[a] + x)
  return 0;
}
