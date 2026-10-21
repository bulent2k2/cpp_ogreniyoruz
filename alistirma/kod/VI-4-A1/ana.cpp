#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-4-A1 · En az para (CSES 1634)
// Çıktı: en az para sayısı ya da -1
int main() {
  int n, x; cin >> n >> x;
  Dizi<S> paralar(n);
  for (auto& p : paralar) cin >> p;
  // f(0) = 0; f(t) = 1 + min f(t - p)
  return 0;
}
