#include "asal.h"

bool asalMi(int n) {
  if (n < 2) return false;
  for (int b = 2; b * b <= n; ++b)
    if (n % b == 0) return false;
  return true;
}

std::vector<int> carpanlar(int n) {
  std::vector<int> sonuc;
  for (int b = 2; b * b <= n; ++b)
    while (n % b == 0) { sonuc.push_back(b); n /= b; }
  if (n > 1) sonuc.push_back(n);
  return sonuc;
}
