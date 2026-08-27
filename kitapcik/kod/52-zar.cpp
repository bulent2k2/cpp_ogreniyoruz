#include <iostream>
#include <vector>
using namespace std;
using S = long long;
const S MOD = 1'000'000'007;

int main() {
  const int n = 10;
  vector<S> f(n+1, 0);
  f[0] = 1;                                  // boş dizi: toplamı sıfır
  for (int x = 1; x <= n; ++x)
    for (int zar = 1; zar <= 6; ++zar)
      if (x - zar >= 0) f[x] = (f[x] + f[x - zar]) % MOD;

  for (int x = 0; x <= n; ++x)
    cout << "f(" << x << ") = " << f[x] << endl;
  return 0;
}
