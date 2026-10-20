#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-9-I1 · Kaç tur yetti? Erken durun, tur sayısını yazın
using S = long long;
const S SONSUZ{(S)1e18};
struct Tunel { int a, b; S x; };

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  Dizi<Tunel> tuneller(m);
  for (auto& t : tuneller) cin >> t.a >> t.b >> t.x;
  Dizi<S> skor(n + 1, -SONSUZ);
  skor[1] = 0;
  for (int k{1}; k < n; ++k)
    for (auto [a, b, x] : tuneller)
      if (skor[a] != -SONSUZ) skor[b] = max(skor[b], skor[a] + x);
  cout << "en büyük skor: " << skor[n] << endl;
  return 0;
}
