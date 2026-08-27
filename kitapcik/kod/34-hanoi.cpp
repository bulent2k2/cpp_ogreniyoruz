#include <iostream>
using namespace std;

int adim = 0;

void tasi(int n, int kaynak, int hedef, int yardimci) {
  if (n == 0) return;
  tasi(n-1, kaynak, yardimci, hedef);        // üstteki n-1 diski aradaki çubuğa
  cout << ++adim << ") " << n << ". diski "
       << kaynak << " -> " << hedef << endl;  // en büyüğü hedefe
  tasi(n-1, yardimci, hedef, kaynak);        // n-1 diski üstüne
}

int main() {
  int n = 3;
  tasi(n, 1, 3, 2);
  cout << "toplam " << adim << " adım (2^" << n << " - 1 = " << ((1<<n)-1) << ")" << endl;
  return 0;
}
