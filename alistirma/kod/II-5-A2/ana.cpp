// II-5-A2 · Konum artı Konum
#include <iostream>
using namespace std;

struct Konum { int x{0}, y{0}; };

ostream& operator<<(ostream& o, const Konum& k) {
  return o << "(" << k.x << ", " << k.y << ")";
}

// operator+ işlevini buraya yazın

int main() {
  Konum a{3, 4}, b{1, 2};
  cout << a << " + " << b << " = " << a + b << endl;
  return 0;
}
