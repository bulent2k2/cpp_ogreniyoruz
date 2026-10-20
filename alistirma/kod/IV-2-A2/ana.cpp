// IV-2-A2 · Pascal üçgeni
// Çıktı: "C(30, 15) = 155117520" ve "C(60, 30) = 118264581564861424"
#include <iostream>
#include <map>
#include <utility>
using namespace std;

map<pair<int, int>, long long> bellek;

long long C(int n, int k) {
  // taban: k == 0 ya da k == n
  return 0;
}

int main() {
  cout << "C(30, 15) = " << C(30, 15) << endl;
  cout << "C(60, 30) = " << C(60, 30) << endl;
  return 0;
}
