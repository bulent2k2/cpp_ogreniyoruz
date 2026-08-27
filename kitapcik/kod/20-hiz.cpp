#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
using namespace std;
using saat = chrono::high_resolution_clock;

int main() {
  const int n = 1'000'000;

  auto basla = saat::now();
  vector<int> dizi(n);
  for (int k = 0; k < n; ++k) dizi[k] = 2 * k;
  auto bitti = saat::now();
  auto insa = chrono::duration_cast<chrono::milliseconds>(bitti - basla);

  const int sorgu = 10'000;
  basla = saat::now();
  long toplam = 0;
  for (int k = 0; k < sorgu; ++k) toplam += dizi[k];
  bitti = saat::now();
  double ort = chrono::duration_cast<chrono::nanoseconds>(bitti - basla).count()
               / (1.0 * sorgu);

  cout << fixed << setprecision(2);
  cout << "dizi boyu          : " << n << " öğe"  << endl;
  cout << "inşa süresi        : " << insa.count() << " ms" << endl;
  cout << "ortalama erişim    : " << ort << " ns" << endl;
  cout << "(toplam " << toplam << ")" << endl;
  return 0;
}
