// II-5-K1 · Küçük robot
// Girdi: I (ileri) ve D (sağa dön) harfleri. Çıktı: "Konum (x, y), yön Kuzey"
#include <iostream>
#include <string>
using namespace std;

enum class Yon { Kuzey, Dogu, Guney, Bati };

struct Robot {
  int x{0}, y{0};
  Yon yon{Yon::Kuzey};
  void ileri() { /* yöne göre x ya da y değişir */ }
  void sagaDon() { /* bir sonraki yön */ }
};

int main() {
  string komutlar;
  cin >> komutlar;
  Robot r;
  // buradan devam edin
  return 0;
}
