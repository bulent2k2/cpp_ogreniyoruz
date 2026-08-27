#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using S = long long;
const S SONSUZ = 1e15;

int main() {
  vector<S> paralar{1, 5, 7};
  const int hedef = 11;

  // 1) EN AZ KAÇ PARA?  f(x) = 1 + min f(x - p)
  vector<S> f(hedef+1, SONSUZ);
  f[0] = 0;
  for (int x = 1; x <= hedef; ++x)
    for (S p : paralar)
      if (x - p >= 0) f[x] = min(f[x], 1 + f[x - p]);

  cout << "paralar: 1, 5, 7   hedef: " << hedef << endl;
  cout << "en az para sayısı : " << f[hedef] << endl;
  cout << "  (aç gözlü çözüm 7+1+1+1+1 yani 5 para kullanırdı)" << endl;

  // 2) KAÇ FARKLI DİZİ?  sıra önemli
  vector<S> paralar2{2, 3, 5};
  const int h2 = 9;
  vector<S> d(h2+1, 0);
  d[0] = 1;
  for (int x = 1; x <= h2; ++x)
    for (S p : paralar2)
      if (x - p >= 0) d[x] += d[x - p];

  // 3) KAÇ FARKLI KÜME?  sıra önemsiz -- döngülerin sırası değişti!
  vector<S> k(h2+1, 0);
  k[0] = 1;
  for (S p : paralar2)                 // önce para, sonra hedef
    for (int x = p; x <= h2; ++x)
      k[x] += k[x - p];

  cout << "\nparalar: 2, 3, 5   hedef: " << h2 << endl;
  cout << "kaç farklı dizi : " << d[h2] << endl;
  cout << "kaç farklı küme : " << k[h2] << endl;
  return 0;
}
