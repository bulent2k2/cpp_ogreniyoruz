#include <iostream>
#include <string>
using namespace std;

template <typename Tur>
Tur ekle(Tur a, Tur b) { return a + b; }

template <typename Tur>
Tur enBuyuk(Tur a, Tur b) { return a > b ? a : b; }

int main() {
  cout << ekle(3, 4)             << endl;   // Tur = int
  cout << ekle(3.5, 4.25)        << endl;   // Tur = double
  cout << ekle(string("ke"), string("lebek")) << endl;  // Tur = string
  cout << enBuyuk('a', 'z')      << endl;   // Tur = char

  // cout << ekle("ke", "lebek");  // HATA! Neden?
  return 0;
}
