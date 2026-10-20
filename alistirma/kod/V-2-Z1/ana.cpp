#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-2-Z1 · Gezi ağacı
// Çıktı: "p: nereden=q derinlik=d" (1 için "kök"), sonra "en derin: p (d)"
Dizi<Dizi<Nokta>> komsular;
Dizi<bool> gezildi;
Dizi<Nokta> nereden;
Dizi<int> derinlik;

void gez(Nokta bu, Nokta onceki, int d) {
  // buradan devam edin
}

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  komsular.assign(n + 1, {}); gezildi.assign(n + 1, false);
  nereden.assign(n + 1, 0); derinlik.assign(n + 1, -1);
  for (int k{0}; k < m; ++k) { Nokta a, b; cin >> a >> b; komsular[a].push_back(b); }
  gez(1, 0, 0);
  // yazdırın
  return 0;
}
