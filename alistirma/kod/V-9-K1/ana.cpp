#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-9-K1 · Çevrim bulma (CSES 1197)
// Çıktı: "YES" ve çevrim (ilk ve son aynı) ya da "NO"
using S = long long;
struct Bag { int a, b; S x; };

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  Dizi<Bag> baglar(m);
  for (auto& t : baglar) cin >> t.a >> t.b >> t.x;
  Dizi<S> uzaklik(n + 1, 0);
  Dizi<int> nereden(n + 1, 0);
  // n tur; son turda iyileşen x; x'i n kere geri sar; çevrimi topla
  return 0;
}
