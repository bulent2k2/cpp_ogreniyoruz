#include <iostream>
using namespace std;

int main() {
  cout << "Merhaba! Ben senin ilk programın." << endl;

  int    yas      {16};        // sayı
  double boy      {1.72};      // kesirli sayı
  char   basHarfi {'B'};       // harf
  bool   ogrenci  {true};      // ikil

  cout << "Yaş      : " << yas      << endl;
  cout << "Boy      : " << boy      << " m" << endl;
  cout << "Baş harfi: " << basHarfi << endl;
  cout << "Öğrenci  : " << ogrenci  << endl;          // 1 yazar!
  cout << "Öğrenci  : " << boolalpha << ogrenci << endl; // true yazar

  cout << "On yıl sonra: " << yas + 10 << endl;
  return 0;
}
