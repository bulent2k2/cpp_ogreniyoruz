#include <iostream>
#include <cmath>
using namespace std;

struct Konum {
  int x{0}, y{0};                         // veriler

  void kaydir(int dx, int dy) {           // yöntem
    x += dx;
    y += dy;
  }
  double uzaklik() const {                // const: hiçbir şeyi değiştirmem
    return sqrt(1.0 * x * x + y * y);
  }
};

// türün üyesi olmayan ama türü tanıyan bir işlemci:
ostream& operator<<(ostream& o, const Konum& k) {
  return o << "(" << k.x << ", " << k.y << ")";
}

int main() {
  Konum k{3, 4};
  cout << k << " başlangıca uzaklığı: " << k.uzaklik() << endl;

  k.kaydir(2, 2);
  cout << k << " şimdi uzaklığı: " << k.uzaklik() << endl;
  return 0;
}
