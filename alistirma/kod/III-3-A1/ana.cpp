// III-3-A1 · Yanlış olması gerekeni de sınayın
#include <iostream>
#include <cassert>
using namespace std;

int ebob(int a, int b) {
  while (b != 0) { int k{a % b}; a = b; b = k; }
  return a;
}

void dene() {
  // en az beş assert
  cout << "denemeler geçti." << endl;
}

int main() {
  dene();
  int a{0}, b{0};
  cin >> a >> b;
  cout << "ebob(" << a << ", " << b << ") = " << ebob(a, b) << endl;
  return 0;
}
