#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-9-Z1 · Çevrim n'e ulaşmıyorsa
// Girdi: art arda iki çizge. Çıktı: her biri için bir satır (-1 ya da skor)
using S = long long;
const S SONSUZ{(S)1e18};
struct Tunel { int a, b; S x; };

S coz(int n, const Dizi<Tunel>& tuneller) {
  // V-9-A1
  return 0;
}

int main() {
  int n{0}, m{0};
  while (cin >> n >> m) {
    Dizi<Tunel> tuneller(m);
    for (auto& t : tuneller) cin >> t.a >> t.b >> t.x;
    cout << coz(n, tuneller) << endl;
  }
  return 0;
}
