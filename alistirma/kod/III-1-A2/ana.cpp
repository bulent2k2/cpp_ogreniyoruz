// III-1-A2 · İki adımda derleme
// Bu dosyaya dokunmayın; iş Makefile'daki derle kuralında.
#include <iostream>
#include <vector>
#include "yardimci.h"
using namespace std;

int main() {
  vector<int> d{3, 1, 4, 1, 5, 9, 2, 6};
  cout << "toplam   : " << toplam(d) << endl;
  cout << "en büyük : " << enBuyuk(d) << endl;
  return 0;
}
