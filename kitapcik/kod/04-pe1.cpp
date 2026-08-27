#include <iostream>
using namespace std;

bool bolunuyorMu(int sayi, int bolen) {
  return sayi % bolen == 0;
}

int main() {
  int toplam{0};
  for (int sayi{3}; sayi < 1000; ++sayi)
    if (bolunuyorMu(sayi, 3) or bolunuyorMu(sayi, 5))
      toplam += sayi;

  cout << "Project Euler, birinci problem: " << toplam << endl;
  return 0;
}
