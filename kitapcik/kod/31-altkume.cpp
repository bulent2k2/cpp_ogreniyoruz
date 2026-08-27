#include <iostream>
#include <vector>
using namespace std;
using Dizi = vector<int>;

Dizi kume{3, 1, 2}, secilen;

void yaz() {
  cout << "{ ";
  for (int s : secilen) cout << s << " ";
  cout << "}" << endl;
}

// 1. yol: geri dönüşlü arama (backtracking)
void uret(size_t k) {
  if (k == kume.size()) { yaz(); return; }
  uret(k + 1);                    // k'ıncı öğeyi ALMA
  secilen.push_back(kume[k]);
  uret(k + 1);                    // k'ıncı öğeyi AL
  secilen.pop_back();             // geri dön: bıraktığın gibi bırak
}

// 2. yol: bitlerle
void bitlerle() {
  size_t n = kume.size(), altKumeSayisi = 1u << n;   // 2^n
  for (size_t ak = 0; ak < altKumeSayisi; ++ak) {
    cout << ak << "  ";
    for (size_t k = n; k-- > 0; ) cout << ((ak >> k) & 1);
    cout << "  { ";
    for (size_t k = 0; k < n; ++k)
      if (ak & (1u << k)) cout << kume[k] << " ";
    cout << "}" << endl;
  }
}

int main() {
  cout << "-- geri dönüşlü arama --" << endl; uret(0);
  cout << "\n-- bitlerle --"          << endl; bitlerle();
  return 0;
}
