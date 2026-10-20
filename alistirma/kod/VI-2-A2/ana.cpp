#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-2-A2 · Engelli ızgara (AtCoder DP H)
// Çıktı: yol sayısı mod 1e9+7
const S MOD{1'000'000'007};

int main() {
  int h, w; cin >> h >> w;
  Dizi<string> plan(h);
  for (auto& s : plan) cin >> s;
  Dizi<Dizi<S>> t(h, Dizi<S>(w, 0));
  t[0][0] = 1;
  for (int r{0}; r < h; ++r)
    for (int c{0}; c < w; ++c) {
      // duvar? yoksa üstten ve soldan gelenler (mod)
    }
  cout << t[h - 1][w - 1] << endl;
  return 0;
}
