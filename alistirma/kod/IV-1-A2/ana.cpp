// IV-1-A2 · Öklid, bu sefer özyinelemeli
// Çıktı: "ebob(1071, 462) -> ebob(462, 147) -> ebob(147, 21) -> ebob(21, 0) = 21"
#include <iostream>
using namespace std;

int ebob(int a, int b) {
  cout << "ebob(" << a << ", " << b << ")";
  // buradan devam edin
  return 0;
}

int main() {
  int a{0}, b{0};
  cin >> a >> b;
  int e{ebob(a, b)};
  cout << " = " << e << endl;
  return 0;
}
