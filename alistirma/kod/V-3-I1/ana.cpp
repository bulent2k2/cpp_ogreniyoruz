#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-3-I1 · Çapraz da komşu olsun
// Çıktı: "4 yönlü: 3" ve "8 yönlü: ?"
using Tahta = Dizi<Dizi<bool>>;   // true: boş ve gezilmemiş

bool gez(int y, int x, Tahta& t) {
  if (not t[y][x]) return false;
  t[y][x] = false;
  gez(y - 1, x, t); gez(y + 1, x, t); gez(y, x - 1, t); gez(y, x + 1, t);
  return true;
}

Tahta oku(int& n, int& m) {
  cin >> n >> m;
  Tahta t(n + 2, Dizi<bool>(m + 2, false));     // çerçeve: duvar
  for (int y{1}; y <= n; ++y) {
    string satir; cin >> satir;
    for (int x{1}; x <= m; ++x) t[y][x] = satir[x - 1] == '.';
  }
  return t;
}

int main() {
  int n, m;
  Tahta t{oku(n, m)};
  int oda{0};
  for (int y{1}; y <= n; ++y) for (int x{1}; x <= m; ++x) if (gez(y, x, t)) ++oda;
  cout << "4 yönlü: " << oda << endl;
  return 0;
}
