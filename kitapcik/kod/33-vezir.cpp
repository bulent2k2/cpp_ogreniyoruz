#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
vector<bool> sutun(N, false),          // bu sütunda vezir var mı?
             capraz1(2*N-1, false),    // sol-üstten sağ-alta: satır + sütun sabit
             capraz2(2*N-1, false);    // sağ-üstten sol-alta: satır - sütun sabit
int cozum = 0;

void koy(int satir) {
  if (satir == N) { ++cozum; return; }        // sekiz vezir yerleşti

  for (int s = 0; s < N; ++s) {
    int c1 = satir + s, c2 = satir - s + N - 1;
    if (sutun[s] or capraz1[c1] or capraz2[c2]) continue;   // tehdit altında

    sutun[s] = capraz1[c1] = capraz2[c2] = true;   // vezir kondu
    koy(satir + 1);                                 // bir alt satıra geç
    sutun[s] = capraz1[c1] = capraz2[c2] = false;  // geri al
  }
}

int main() {
  koy(0);
  cout << N << " vezir bulmacasının çözüm sayısı: " << cozum << endl;
  return 0;
}
