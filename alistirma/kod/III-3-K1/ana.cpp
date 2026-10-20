// III-3-K1 · Önce test, sonra kod
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

string romaya(int n) {
  // buraya yazın
  return "";
}

void dene() {
  assert(romaya(1) == "I");
  assert(romaya(4) == "IV");
  assert(romaya(9) == "IX");
  assert(romaya(14) == "XIV");
  assert(romaya(40) == "XL");
  assert(romaya(1987) == "MCMLXXXVII");
  assert(romaya(2026) == "MMXXVI");
  cout << "denemeler geçti." << endl;
}

int main() {
  dene();
  for (int n : {3, 58, 444, 1994}) cout << n << " = " << romaya(n) << endl;
  return 0;
}
