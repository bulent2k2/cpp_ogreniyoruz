#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-1-I1 · Çizelgeyle Fibonaççi
// Çıktı: "n=10: YA 55, AY 55" biçiminde üç satır (10, 50, 90)
map<int, S> bellek;
S fibYA(int n) {                 // yukarıdan aşağı + bellek (Bölüm IV)
  if (n < 2) return n;
  if (bellek.contains(n)) return bellek[n];
  return bellek[n] = fibYA(n - 1) + fibYA(n - 2);
}

S fibAY(int n) {                 // aşağıdan yukarı: çizelgeyi 0'dan n'e doldurun
  return 0;
}

int main() {
  for (int n : {10, 50, 90})
    cout << "n=" << n << ": YA " << fibYA(n) << ", AY " << fibAY(n) << endl;
  return 0;
}
