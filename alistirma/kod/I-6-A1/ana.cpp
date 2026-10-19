// I-6-A1 · Döngüden sonra
#include <iostream>
using namespace std;

int main() {
  for (int k{0}; k < 10; ++k) {
    // bir şey yapıyormuş gibi
  }
  cout << "k = " << k << endl;   // derlenmez: k burada yok
  return 0;
}
