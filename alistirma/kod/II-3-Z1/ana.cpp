// II-3-Z1 · Bölenler eşlemi
// 1..12 için bölen kümeleri; sonra asallar ve en çok böleni olan
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  map<int, set<int>> bolenler;
  for (int n{1}; n <= 12; ++n)
    for (int b{1}; b <= n; ++b)
      if (n % b == 0) bolenler[n].insert(b);
  // buradan devam edin
  return 0;
}
