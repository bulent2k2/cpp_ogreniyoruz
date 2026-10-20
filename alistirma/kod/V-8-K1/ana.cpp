#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-8-K1 · Kim kime ulaşır?
// Çıktı: n satır 0/1 (kendine 1), sonra "p: k noktaya ulaşır" satırları
int main() {
  int n{0}, m{0};
  cin >> n >> m;
  Dizi<Dizi<bool>> erisir(n + 1, Dizi<bool>(n + 1, false));
  for (int a{1}; a <= n; ++a) erisir[a][a] = true;
  // bağları oku; üç döngü; yazdır
  return 0;
}
