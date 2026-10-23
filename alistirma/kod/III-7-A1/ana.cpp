// III-7-A1 · bolunuyorMu için denemeler
// Çıktı: "denemeler geçti." sonra her çift için "a b -> evet/hayır"
#include <iostream>
#include <cassert>
using namespace std;

bool bolunuyorMu(int a, int b) {
  return false;   // b sıfırsa yanlış; değilse kalana bakın
}

void dene() {
  // dört assert
  cout << "denemeler geçti." << endl;
}

int main() {
  dene();
  int a{0}, b{0};
  while (cin >> a >> b) {
    // yazdır
  }
  return 0;
}
