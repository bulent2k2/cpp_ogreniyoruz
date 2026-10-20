// III-4-A1 · Küçülterek
// Girdi: n, sonra n sayı. Çıktı: tek sayıların toplamı. Bir yerde hata var.
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n{0}; cin >> n;
  vector<int> d(n);
  for (int& x : d) cin >> x;
  int toplam{0};
  for (int i{0}; i < n - 1; ++i)
    if (d[i] % 2 == 1) toplam += d[i];
  cout << "Teklerin toplamı: " << toplam << endl;
  return 0;
}
