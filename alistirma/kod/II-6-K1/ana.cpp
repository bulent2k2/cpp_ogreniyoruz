// II-6-K1 · Kendi yığınınız
// Çıktı: "4 1 3" ve "iki bir"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Yigin kalıbını buraya yazın

int main() {
  Yigin<int> y;
  y.koy(3); y.koy(1); y.koy(4);
  while (not y.bosMu()) { cout << y.tepe() << " "; y.cikar(); }
  cout << endl;
  Yigin<string> s;
  s.koy("bir"); s.koy("iki");
  while (not s.bosMu()) { cout << s.tepe() << " "; s.cikar(); }
  cout << endl;
  return 0;
}
