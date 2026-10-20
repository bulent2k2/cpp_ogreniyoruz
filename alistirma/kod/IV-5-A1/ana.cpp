// IV-5-A1 · Tahtaları çizin
// Girdi: N. Çıktı: ilk üç çözümün tahtası (Q ve .), aralarında boş satır, sonda çözüm sayısı
#include <iostream>
#include <vector>
using namespace std;

int N{8}, cozum{0};
vector<bool> sutun, capraz1, capraz2;
vector<int> yer;                     // yer[satir] = vezirin sütunu

void ciz() {
  // satır satır: Q ya da .
}

void koy(int satir) {
  if (satir == N) { ++cozum; if (cozum <= 3) ciz(); return; }
  for (int s{0}; s < N; ++s) {
    int c1{satir + s}, c2{satir - s + N - 1};
    if (sutun[s] or capraz1[c1] or capraz2[c2]) continue;
    sutun[s] = capraz1[c1] = capraz2[c2] = true;
    yer[satir] = s;
    koy(satir + 1);
    sutun[s] = capraz1[c1] = capraz2[c2] = false;
  }
}

int main() {
  cin >> N;
  sutun.assign(N, false); capraz1.assign(2 * N - 1, false); capraz2.assign(2 * N - 1, false);
  yer.assign(N, 0);
  koy(0);
  cout << N << " vezir: " << cozum << " çözüm" << endl;
  return 0;
}
