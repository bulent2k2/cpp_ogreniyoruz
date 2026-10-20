#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-4-K1 · Takım işi, makineyle
// Çıktı:
//   dizi (önce hedef, sonra para):
//   x=1: 1 0 0 0 0 0
//   ...
//   küme (önce para, sonra hedef):
//   p=2: 1 0 1 0 1 0
//   p=3: ...
void yaz(const Dizi<S>& c) { for (size_t k{0}; k < c.size(); ++k) cout << (k ? " " : "") << c[k]; cout << endl; }

int main() {
  const int hedef{5};
  Dizi<S> paralar{2, 3};
  // iki sürüm, her adımda yaz()
  return 0;
}
