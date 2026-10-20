// IV-6-I1 · Tabloyu üretin
// Çıktı, her n için:
//   n=20
//     log n   : 4 sığar
//     n       : 20 sığar
//     n log n : 80 sığar
//     n^2     : 400 sığar
//     2^n     : 1048576 sığar      (yalnız n=20 için)
// log n: round(log2(n)); 1000 için 10
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  const long long SANIYE{100000000};   // saniyede işlem
  for (long long n : {20LL, 1000LL, 1000000LL}) {
    // buradan devam edin
  }
  return 0;
}
