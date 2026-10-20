#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-4-Z1 · Hangi paralar?
// Çıktı: "3 para: p1 p2 p3" (geriye izlerken bulunan sırayla)
int main() {
  int n, x; cin >> n >> x;
  Dizi<S> paralar(n);
  for (auto& p : paralar) cin >> p;
  // f ve son; sonra t = x'ten geriye: p = son[t], t -= p
  return 0;
}
