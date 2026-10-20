// IV-1-K1 · Hanoi hakemi
// Girdi: n. Çıktı: "15 adım, hepsi geçerli" ya da "hata: k. adım"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<stack<int>> cubuk(4);      // 1..3 kullanılıyor
int adim{0};
bool hata{false};

void hamle(int kaynak, int hedef) {
  ++adim;
  // kaynak boşsa ya da üstteki disk hedefin üstündekinden büyükse: hata
  // yoksa diski taşıyın
}

void tasi(int n, int kaynak, int hedef, int yardimci) {
  if (n == 0) return;
  tasi(n - 1, kaynak, yardimci, hedef);
  hamle(kaynak, hedef);
  tasi(n - 1, yardimci, hedef, kaynak);
}

int main() {
  int n{0}; cin >> n;
  for (int d{n}; d >= 1; --d) cubuk[1].push(d);
  tasi(n, 1, 3, 2);
  if (not hata) cout << adim << " adım, hepsi geçerli" << endl;
  return 0;
}
