#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-3-A2 · En büyük oda
// Çıktı: "k oda, en büyüğü s kare"
using Tahta = Dizi<Dizi<bool>>;

int gez(int y, int x, Tahta& t) {
  // 0 ya da 1 + komşulardan dönenler
  return 0;
}

int main() {
  int n, m; cin >> n >> m;
  Tahta t(n + 2, Dizi<bool>(m + 2, false));
  for (int y{1}; y <= n; ++y) { string s; cin >> s; for (int x{1}; x <= m; ++x) t[y][x] = s[x - 1] == '.'; }
  // buradan devam edin
  return 0;
}
