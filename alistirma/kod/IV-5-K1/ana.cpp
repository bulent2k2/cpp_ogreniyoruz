// IV-5-K1 · Sudoku
// Girdi: 9 satır, 0 boş. Çıktı: çözülmüş 9 satır
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> t(9);

bool uygun(int r, int c, char rakam) { /* satır, sütun, 3x3 kutu */ return false; }

bool coz() {
  // ilk boş kareyi bul; yoksa true
  // 1..9 dene: uygun ise koy, coz() true ise true; geri al
  return false;
}

int main() {
  for (auto& s : t) cin >> s;
  if (coz()) for (auto& s : t) cout << s << endl;
  else cout << "çözüm yok" << endl;
  return 0;
}
