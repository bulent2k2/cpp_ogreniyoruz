// IV-1-A1 · Faktöriyel ve toplam
// Çıktı: "10! = 3628800" ve "1+...+10 = 55"
#include <iostream>
using namespace std;

long long faktoriyel(int n) { /* taban, sonra adım */ return 0; }
long long toplam(int n)     { /* taban, sonra adım */ return 0; }

int main() {
  int n{0}; cin >> n;
  cout << n << "! = " << faktoriyel(n) << endl;
  cout << "1+...+" << n << " = " << toplam(n) << endl;
  return 0;
}
