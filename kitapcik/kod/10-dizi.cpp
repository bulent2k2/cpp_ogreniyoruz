#include <iostream>
using namespace std;

int main() {
  short dizi[]{3, 1, 4, 1, 5, 9, 2, 6};

  cout << "dizinin boyu     : " << sizeof(dizi)    << " bayt" << endl;
  cout << "bir öğenin boyu  : " << sizeof(dizi[0]) << " bayt" << endl;
  int ogeSayisi = sizeof(dizi) / sizeof(dizi[0]);
  cout << "öğe sayısı       : " << ogeSayisi << endl;

  cout << "ilk öğenin adresi: " << (void*) dizi        << endl;
  cout << "ikincininki      : " << (void*) (dizi + 1)  << endl;

  for (auto s : dizi) cout << s << " ";
  cout << endl;

  cout << "taşma: " << dizi[12] << endl;   // dizinin dışı! kimse uyarmıyor
  return 0;
}
