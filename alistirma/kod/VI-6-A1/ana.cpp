#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-6-A1 · Zıplayan kurbağa (AtCoder DP A)
// Çıktı: en ucuz bedel
int main() {
  int n; cin >> n;
  Dizi<S> h(n);
  for (auto& x : h) cin >> x;
  // f[0] = 0; f[i] = min(f[i-1] + |h[i]-h[i-1]|, f[i-2] + |h[i]-h[i-2]|)
  return 0;
}
