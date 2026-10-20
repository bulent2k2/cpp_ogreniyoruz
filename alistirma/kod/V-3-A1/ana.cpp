#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-3-A1 · Odaları sayın, yığınla
// Çıktı: yalnız oda sayısı
using Kare = pair<int, int>;
using Tahta = Dizi<Dizi<bool>>;

void gez(int y, int x, Tahta& t) {
  stack<Kare> yigin;
  // buradan devam edin
}

int main() {
  int n, m; cin >> n >> m;
  Tahta t(n + 2, Dizi<bool>(m + 2, false));
  for (int y{1}; y <= n; ++y) { string s; cin >> s; for (int x{1}; x <= m; ++x) t[y][x] = s[x - 1] == '.'; }
  int oda{0};
  for (int y{1}; y <= n; ++y) for (int x{1}; x <= m; ++x)
    if (t[y][x]) { ++oda; gez(y, x, t); }
  cout << oda << endl;
  return 0;
}
