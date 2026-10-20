// I-4-Z1 · Öklid'in işlevi
// ebob(int, int) ve ekok(int, int); girdi: iki sayı
#include <iostream>
using namespace std;

// ebob ve ekok işlevlerini buraya yazın

int main() {
  int a{0}, b{0};
  cin >> a >> b;
  cout << "ebob(" << a << ", " << b << ") = " << ebob(a, b) << endl;
  cout << "ekok(" << a << ", " << b << ") = " << ekok(a, b) << endl;
  return 0;
}
