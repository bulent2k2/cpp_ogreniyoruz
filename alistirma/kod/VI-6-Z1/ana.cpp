#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-6-Z1 · Başı sonu aynı altdizi
// Çıktı: "kaba: 11" ve "eşlemle: 11"
S kaba(const Dizi<S>& d) {           // her (i, j) çifti
  return 0;
}
S eslemle(const Dizi<S>& d) {        // ilk konum eşlemi + ön toplam
  return 0;
}

int main() {
  int n; cin >> n;
  Dizi<S> d(n);
  for (auto& x : d) cin >> x;
  cout << "kaba: " << kaba(d) << endl;
  cout << "eşlemle: " << eslemle(d) << endl;
  return 0;
}
