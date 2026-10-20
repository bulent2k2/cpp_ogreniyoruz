#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-1-A2 · Bellek olarak vector
// Çıktı: "fib(30) = ...", sonra "belleksiz: X çağrı", "map ile  : Y çağrı", "vector ile: Z çağrı"
S cagri1{0}, cagri2{0}, cagri3{0};

S fibYavas(int n) { ++cagri1; if (n < 2) return n; return fibYavas(n - 1) + fibYavas(n - 2); }

map<int, S> bellek;
S fibMap(int n) {
  ++cagri2;
  if (n < 2) return n;
  if (bellek.contains(n)) return bellek[n];
  return bellek[n] = fibMap(n - 1) + fibMap(n - 2);
}

Dizi<S> bellek2;                 // -1: henüz hesaplanmadı
S fibVec(int n) {
  ++cagri3;
  return 0;
}

int main() {
  int n; cin >> n;
  bellek2.assign(n + 1, -1);
  S a{fibYavas(n)}, b{fibMap(n)}, c{fibVec(n)};
  cout << "fib(" << n << ") = " << a << (a == b and b == c ? "" : "  FARKLI!") << endl;
  // çağrı sayılarını yazdırın
  return 0;
}
