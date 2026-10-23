// VI-7-A1 · Çizelgeyi eşlemle tutun
// Çıktı: "2x2: 2 yol", "5x5: 70 yol", "16x16: ... yol", "bellekte ... kayıt"
#include <iostream>
#include <map>
using namespace std;

map<pair<int, int>, long long> bellek;

long long yol(int s, int k) {
  // taban: s == 1 || k == 1 -> 1
  // bellekte varsa dön; yoksa hesapla, kaydet
  return 0;
}

int main() {
  int soru{0}; cin >> soru;
  for (int i = 0; i < soru; ++i) {
    int s{0}, k{0}; cin >> s >> k;
    cout << s << "x" << k << ": " << yol(s, k) << " yol" << endl;
  }
  cout << "bellekte " << bellek.size() << " kayıt" << endl;
  return 0;
}
