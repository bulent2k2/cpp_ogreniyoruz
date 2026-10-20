#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-2-A1 · Erişilebilenler
// Çıktı: "1'den erişilebilen: 1 2 3 ..." ve "k nokta"
Dizi<Dizi<Nokta>> komsular;
Dizi<bool> gezildi;

void gez(Nokta bu) {
  // beş satır
}

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  komsular.assign(n + 1, {});
  gezildi.assign(n + 1, false);
  for (int k{0}; k < m; ++k) { Nokta a, b; cin >> a >> b; komsular[a].push_back(b); }
  gez(1);
  // yazdırın
  return 0;
}
