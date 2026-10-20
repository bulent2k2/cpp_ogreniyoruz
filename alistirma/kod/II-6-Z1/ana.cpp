// II-6-Z1 · Kutu ve Konum
// Çıktı: "42" ve "(3, 4)"
#include <iostream>
#include <vector>
using namespace std;

struct Konum { int x{0}, y{0}; };
ostream& operator<<(ostream& o, const Konum& k) { return o << "(" << k.x << ", " << k.y << ")"; }

// Kutu kalıbını buraya yazın

int main() {
  Kutu<int>   k1{42};
  Kutu<Konum> k2{{3, 4}};
  cout << k1.al() << endl;
  cout << k2.al() << endl;
  return 0;
}
