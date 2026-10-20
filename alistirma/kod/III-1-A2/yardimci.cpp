#include "yardimci.h"

int toplam(const std::vector<int>& d) {
  int t{0};
  for (int x : d) t += x;
  return t;
}

int enBuyuk(const std::vector<int>& d) {
  int e{d[0]};
  for (int x : d) if (x > e) e = x;
  return e;
}
