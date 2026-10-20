// I-6-Z1 · Küreselsiz sayaç
// Küreseli kaldırın; ikinci satır: "b: 1 2"
#include <iostream>
using namespace std;

int sayac{0};               // küresel: bundan kurtulun

void say() {
  ++sayac;
  cout << " " << sayac;
}

int main() {
  cout << "a:";
  say(); say(); say();
  cout << endl;
  return 0;
}
