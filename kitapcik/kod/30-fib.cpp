#include <iostream>
#include <map>
#include <chrono>
using namespace std;
using Sayi = unsigned long long;

Sayi cagri1 = 0, cagri2 = 0;

Sayi fibYavas(int n) {                    // düpedüz tanım
  ++cagri1;
  if (n < 2) return n;
  return fibYavas(n-1) + fibYavas(n-2);
}

map<int, Sayi> bellek;                    // memoizasyon
Sayi fibHizli(int n) {
  ++cagri2;
  if (n < 2) return n;
  if (bellek.contains(n)) return bellek[n];
  return bellek[n] = fibHizli(n-1) + fibHizli(n-2);
}

int main() {
  const int n = 40;
  auto t0 = chrono::steady_clock::now();
  Sayi a = fibYavas(n);
  auto t1 = chrono::steady_clock::now();
  Sayi b = fibHizli(n);
  auto t2 = chrono::steady_clock::now();

  auto ms = [](auto x, auto y) {
    return chrono::duration_cast<chrono::microseconds>(y - x).count();
  };

  cout << "fib(" << n << ") = " << a << endl;
  cout << "yavaş: " << cagri1 << " çağrı, " << ms(t0,t1) << " mikrosaniye" << endl;
  cout << "hızlı: " << cagri2 << " çağrı, " << ms(t1,t2) << " mikrosaniye" << endl;
  cout << "kontrol: " << (a == b ? "aynı sonuç" : "FARKLI!") << endl;
  return 0;
}
