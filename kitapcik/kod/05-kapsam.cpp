#include <iostream>
int sayi = 3;              // küresel

void f() { sayi = 10; }     // küreseli değiştirir
void g() { int sayi = 99; } // kendi yerelini yapar, küresele dokunmaz

int main() {
  int sayi = 5;            // yerel, küreseli gölgeliyor
  f();
  g();
  std::cout << sayi << " " << ::sayi;   // ?? ve ??
}
