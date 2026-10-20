#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-9-A1 · Yüksek skor (CSES 1673)
// Çıktı: en büyük skor ya da -1
using S = long long;
const S SONSUZ{(S)1e18};
struct Tunel { int a, b; S x; };

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  Dizi<Tunel> tuneller(m);
  for (auto& t : tuneller) cin >> t.a >> t.b >> t.x;
  // n-1 tur; n'inci turda iyileşenleri işaretle; işaretli bir noktadan n'e yol varsa -1
  return 0;
}
