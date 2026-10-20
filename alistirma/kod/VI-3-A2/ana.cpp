#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-3-A2 · Yukarıdan aşağı zar
// Çıktı: "AY: ...", "YA: ...", "çağrı: ..."
const S MOD{1'000'000'007};
Dizi<S> bellek;
S cagri{0};

S f(int n) {
  ++cagri;
  // taban, bellek, altı çağrı (eksi n: 0)
  return 0;
}

int main() {
  int n; cin >> n;
  Dizi<S> ay(n + 1, 0);
  ay[0] = 1;
  for (int x{1}; x <= n; ++x)
    for (int zar{1}; zar <= 6; ++zar)
      if (x - zar >= 0) ay[x] = (ay[x] + ay[x - zar]) % MOD;
  bellek.assign(n + 1, -1);
  cout << "AY: " << ay[n] << endl;
  cout << "YA: " << f(n) << endl;
  cout << "çağrı: " << cagri << endl;
  return 0;
}
