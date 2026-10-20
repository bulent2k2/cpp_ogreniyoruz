// III-1-I1 · Girdiyi dosyadan
// ./prog < girdi ile çalıştırın; sonra "En büyük: ..." satırı ekleyin
#include <iostream>
using namespace std;

int main() {
  int x{0}, adet{0};
  long long toplam{0};
  while (cin >> x) {
    ++adet;
    toplam += x;
  }
  cout << "Adet: " << adet << endl;
  cout << "Toplam: " << toplam << endl;
  return 0;
}
