#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-4-A2 · Para kombinasyonları I ve II (CSES 1635, 1636)
// Çıktı: "dizi: 8" ve "küme: 3"
const S MOD{1'000'000'007};

int main() {
  int n, x; cin >> n >> x;
  Dizi<S> paralar(n);
  for (auto& p : paralar) cin >> p;
  // d: önce hedef sonra para; k: önce para sonra hedef
  return 0;
}
