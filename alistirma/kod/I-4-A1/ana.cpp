// I-4-A1 · Üçün en büyüğü
// Girdi: üç tam sayı. Çıktı: "En büyük: <sayı>"
#include <iostream>
using namespace std;

// enBuyuk(int, int, int) işlevini buraya yazın

int main() {
  int a{0}, b{0}, c{0};
  cin >> a >> b >> c;
  cout << "En büyük: " << enBuyuk(a, b, c) << endl;
  return 0;
}
