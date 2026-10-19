// I-3-Z1 · Klasik tuzağı kendiniz kurun
// Üç satır: iki if (yanlış), 15 çıkarılmış (yamalı), or'lu (doğru)
#include <iostream>
using namespace std;

bool bolunuyorMu(int sayi, int bolen) { return sayi % bolen == 0; }

int main() {
  int yanlis{0}, yamali{0}, dogru{0};
  // buradan devam edin
  cout << "iki if ile  : " << yanlis << endl;
  cout << "15 çıkarınca: " << yamali << endl;
  cout << "or ile      : " << dogru << endl;
  return 0;
}
