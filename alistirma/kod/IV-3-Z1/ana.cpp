// IV-3-Z1 · Elmaları bölmek
// Çıktı: "En küçük fark: 1"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<long long> elma;
long long enKucuk{-1};

void ara(size_t k, long long birinci, long long ikinci) {
  // taban: k == elma.size() -> fark; enKucuk güncelle
  // k'ıncı elma birinciye, k'ıncı elma ikinciye
}

int main() {
  int n{0}; cin >> n;
  elma.resize(n);
  for (auto& x : elma) cin >> x;
  ara(0, 0, 0);
  cout << "En küçük fark: " << enKucuk << endl;
  return 0;
}
