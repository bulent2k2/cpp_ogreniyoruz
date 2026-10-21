#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-5-Z1 · Gidiş dönüş (CSES 1669)
// Çıktı: k, sonra k nokta (ilk ve son aynı); çevrim yoksa "IMPOSSIBLE"
Dizi<Dizi<Nokta>> komsular;
Dizi<bool> gezildi;
Dizi<Nokta> nereden;
Dizi<Nokta> cevrim;

bool gez(Nokta bu, Nokta onceki) {
  // gezilmiş komşu su (onceki değil) -> çevrimi kur, true
  return false;
}

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  komsular.assign(n + 1, {}); gezildi.assign(n + 1, false); nereden.assign(n + 1, 0);
  for (int k{0}; k < m; ++k) { Nokta a, b; cin >> a >> b; komsular[a].push_back(b); komsular[b].push_back(a); }
  for (Nokta p{1}; p <= n; ++p)
    if (not gezildi[p] and gez(p, 0)) {
      cout << cevrim.size() << endl;
      for (Nokta c : cevrim) cout << c << " ";
      cout << endl;
      return 0;
    }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
