#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-2-A1 · Dikdörtgen ızgara
// Çıktı: her çift için "rxc: yol sayısı"
int main() {
  int r, c;
  while (cin >> r >> c) {
    // tek satır: satir[j] += satir[j-1]
    cout << r << "x" << c << ": " << 0 << endl;
  }
  return 0;
}
