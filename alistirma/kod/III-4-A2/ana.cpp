// III-4-A2 · Adım adım
#include <iostream>
using namespace std;

long long fib(int n) {
  if (n < 2) return n;
  return fib(n - 1) + fib(n - 1);
}

int main() {
  for (int n : {1, 2, 5, 10, 20}) cout << "fib(" << n << ") = " << fib(n) << endl;
  return 0;
}
