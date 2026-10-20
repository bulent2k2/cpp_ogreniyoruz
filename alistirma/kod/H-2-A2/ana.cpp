// H-2-A2 · Derleyici kızmıyor ama yanlış
#include <iostream>
using namespace std;

int main() {
  int sayi{3};
  if (sayi = 7) cout << "yedi" << endl;
  else          cout << "yedi değil" << endl;
  return 0;
}
