// I-2-Z1 · Neden tam 2147483647?
// 2^31, 2^31 - 1, 2^32, 2^63 - 1 — kaydırma işleciyle
#include <iostream>
using namespace std;

int main() {
  cout << "2^31     = " << (1LL << 31) << endl;
  // buradan devam edin
  return 0;
}
