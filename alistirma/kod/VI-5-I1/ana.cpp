#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-5-I1 · Küçük örnekte doğru, aslında yanlış
// Çıktı: "n doğru yanlış" başlığı, 11 satır, sonra "ilk ayrışma: n=?"
int main() {
  const int n{10};
  Dizi<S> f(n + 1, 0), g(n + 1, 0);
  f[0] = 1;
  for (int x{1}; x <= n; ++x)
    for (int zar{1}; zar <= 6; ++zar)
      if (x - zar >= 0) f[x] += f[x - zar];
  // g: g[0] = g[1] = 1, sonra bir öncekinin iki katı
  cout << "n doğru yanlış" << endl;
  for (int x{0}; x <= n; ++x) cout << x << " " << f[x] << " " << g[x] << endl;
  // ilk ayrışma
  return 0;
}
