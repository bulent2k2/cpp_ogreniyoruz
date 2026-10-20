#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-8-A1 · Shortest Routes II (CSES 1672)
// Çıktı: her soru için bir satır
using U = long long;
const U SONSUZ{(U)1e15};

int main() {
  int n{0}, m{0}, q{0};
  cin >> n >> m >> q;
  Dizi<Dizi<U>> f(n + 1, Dizi<U>(n + 1, SONSUZ));
  for (int a{1}; a <= n; ++a) f[a][a] = 0;
  // yolları oku (min!), üç döngü, soruları yanıtla
  return 0;
}
