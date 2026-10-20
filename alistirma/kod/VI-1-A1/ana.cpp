#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-1-A1 · İki değişken yeter
// Çıktı: "fib(90) = ..." ve "fib(92) = ..."
S fib(int n) {
  // a = f(k-1), b = f(k); her adımda ikisini kaydırın
  return 0;
}

int main() {
  for (int n : {90, 92}) cout << "fib(" << n << ") = " << fib(n) << endl;
  return 0;
}
