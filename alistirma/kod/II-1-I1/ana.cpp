// II-1-I1 · short yerine int
#include <iostream>
using namespace std;

int main() {
  short dizi[]{3, 1, 4, 1, 5, 9, 2, 6};

  cout << "dizinin boyu     : " << sizeof(dizi)    << " bayt" << endl;
  cout << "bir öğenin boyu  : " << sizeof(dizi[0]) << " bayt" << endl;
  int ogeSayisi = sizeof(dizi) / sizeof(dizi[0]);
  cout << "öğe sayısı       : " << ogeSayisi << endl;

  for (auto s : dizi) cout << s << " ";
  cout << endl;
  return 0;
}
