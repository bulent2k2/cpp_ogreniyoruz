#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-8-Z1 · Yolu geri kurmak
// Çıktı: her soru için "a -> b: a x y b (uzaklık u)"
using U = long long;
const U SONSUZ{(U)1e15};

int main() {
  int n{0}, m{0}, q{0};
  cin >> n >> m >> q;
  Dizi<Dizi<U>> f(n + 1, Dizi<U>(n + 1, SONSUZ));
  Dizi<Dizi<int>> sonraki(n + 1, Dizi<int>(n + 1, 0));
  for (int a{1}; a <= n; ++a) f[a][a] = 0;
  // yolları oku: f ve sonraki[a][b] = b; üç döngü sonraki'yi de güncellesin; soruları yanıtla
  return 0;
}
