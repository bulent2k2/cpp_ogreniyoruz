// III-1-A1 · -Wall ne diyor?
// Makefile -Wall -Werror ile derliyor: uyarıları giderin, çıktı aynı kalsın
#include <iostream>
#include <vector>
using namespace std;

int kacTane(const vector<int>& d, int aranan) {
  int sayac{0};
  for (int i{0}; i < d.size(); ++i)
    if (d[i] == aranan) ++sayac;
  return sayac;
}

int main() {
  vector<int> d{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  int gereksiz;
  int bes{kacTane(d, 5)};
  if (bes = 3) cout << "5 üç kere geçiyor" << endl;
  else         cout << "5 başka sayıda geçiyor" << endl;
  return 0;
}
