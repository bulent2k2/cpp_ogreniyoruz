// II-5-Z1 · Kendi Kesir türünüz
// Çıktı: "1/2 + 1/3 = 5/6" ve "1/2 * 1/2 = 1/4" (yapıcı sadeleştirir)
#include <iostream>
using namespace std;

int ebob(int a, int b) { while (b != 0) { int k{a % b}; a = b; b = k; } return a; }

struct Kesir {
  int pay{0}, payda{1};
  Kesir(int p, int q) : pay{p}, payda{q} {
    // sadeleştirin
  }
};

// operator+, operator*, operator<< işlevlerini buraya yazın

int main() {
  Kesir a{1, 2}, b{1, 3}, c{2, 4}, d{3, 6};
  cout << a << " + " << b << " = " << a + b << endl;
  cout << c << " * " << d << " = " << c * d << endl;
  return 0;
}
