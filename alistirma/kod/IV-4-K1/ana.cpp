// IV-4-K1 · Gezgin satıcı, altı şehir
// Girdi: n, n×n uzaklık tablosu. Çıktı: "En kısa tur: 0 ... 0, uzunluk L"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n{0}; cin >> n;
  vector<vector<int>> u(n, vector<int>(n));
  for (auto& satir : u) for (int& x : satir) cin >> x;
  // 1..n-1'in bütün dizilişleri; her tur için uzunluk; en kısası
  return 0;
}
