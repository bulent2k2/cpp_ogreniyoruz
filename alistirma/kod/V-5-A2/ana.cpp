#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-5-A2 · Çevrim var mı?
Dizi<Dizi<Nokta>> komsular;
Dizi<bool> gezildi;

bool cevrimVar(Nokta bu, Nokta onceki) {
  // gezildi; komşular: onceki hariç, gezilmişse true, değilse in
  return false;
}

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  komsular.assign(n + 1, {}); gezildi.assign(n + 1, false);
  for (int k{0}; k < m; ++k) { Nokta a, b; cin >> a >> b; komsular[a].push_back(b); komsular[b].push_back(a); }
  bool var{false};
  for (Nokta p{1}; p <= n; ++p) if (not gezildi[p] and cevrimVar(p, 0)) var = true;
  cout << (var ? "çevrim var" : "çevrim yok") << endl;
  return 0;
}
