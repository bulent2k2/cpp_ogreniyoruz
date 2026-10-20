#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-1-Z1 · Derin çağrı
// Çıktı: "fib(1000000) mod 1e9+7 = ..."
const S MOD{1'000'000'007};
Dizi<S> bellek;

S fibYA(int n) {                        // n = 10^6: bir milyon iç içe çağrı
  if (n < 2) return n;
  if (bellek[n] >= 0) return bellek[n];
  return bellek[n] = (fibYA(n - 1) + fibYA(n - 2)) % MOD;
}

int main() {
  int n; cin >> n;
  bellek.assign(n + 1, -1);
  cout << "fib(" << n << ") mod 1e9+7 = " << fibYA(n) << endl;   // AY ile değiştirin
  return 0;
}
