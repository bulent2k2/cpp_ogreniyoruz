#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-5-I1 · Kitapçığın ilk hatası: eksik else
enum class Takim { Yok, Bir, Iki };
Dizi<Dizi<Nokta>> sinif;
Dizi<Takim> takim;

bool gez(Nokta a) {
  for (Nokta b : sinif[a]) {
    if (takim[b] != Takim::Yok) {
      if (takim[b] == takim[a]) return false;
    }
    takim[b] = (takim[a] == Takim::Bir) ? Takim::Iki : Takim::Bir;
    if (not gez(b)) return false;
  }
  return true;
}

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  sinif.assign(n + 1, {}); takim.assign(n + 1, Takim::Yok);
  for (int k{0}; k < m; ++k) { Nokta a, b; cin >> a >> b; sinif[a].push_back(b); sinif[b].push_back(a); }
  for (Nokta p{1}; p <= n; ++p)
    if (takim[p] == Takim::Yok) {
      takim[p] = Takim::Bir;
      if (not gez(p)) { cout << "IMPOSSIBLE" << endl; return 0; }
    }
  for (Nokta p{1}; p <= n; ++p) cout << (takim[p] == Takim::Bir ? 1 : 2) << " ";
  cout << endl;
  return 0;
}
