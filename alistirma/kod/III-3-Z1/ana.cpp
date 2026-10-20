// III-3-Z1 · Kesir'e denemeler
// Çıktı: "denemeler geçti." ve "1/2 + 1/3 = 5/6"
#include <iostream>
#include <cassert>
using namespace std;

int ebob(int a, int b) { while (b != 0) { int k{a % b}; a = b; b = k; } return a; }

struct Kesir {
  int pay{0}, payda{1};
  Kesir(int p, int q) : pay{p}, payda{q} { int e{ebob(pay, payda)}; pay /= e; payda /= e; }
};
Kesir operator+(const Kesir& a, const Kesir& b) { return {a.pay * b.payda + b.pay * a.payda, a.payda * b.payda}; }
Kesir operator*(const Kesir& a, const Kesir& b) { return {a.pay * b.pay, a.payda * b.payda}; }
ostream& operator<<(ostream& o, const Kesir& k) { return o << k.pay << "/" << k.payda; }
// operator== buraya

void dene() {
  // assert'ler buraya
  cout << "denemeler geçti." << endl;
}

int main() {
  dene();
  Kesir a{1, 2}, b{1, 3};
  cout << a << " + " << b << " = " << a + b << endl;
  return 0;
}
