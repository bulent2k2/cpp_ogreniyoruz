// IV-6-K1 · Grid Paths (CSES 1625)
// Girdi: 48 karakterlik desen. Çıktı: "uyan patika: 201"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string desen;
int patika{0};
vector<vector<bool>> gezildi(7, vector<bool>(7, false));

bool icerdeMi(int r, int c) { return r >= 0 and r < 7 and c >= 0 and c < 7; }
bool dolu(int r, int c) { return not icerdeMi(r, c) or gezildi[r][c]; }

void git(int r, int c, int adim) {
  // hedef (6, 0): adim == 48 ise patika; her durumda dön
  // budamalar; sonra desen[adim]'e göre yalnız izin verilen yönler
}

int main() {
  cin >> desen;
  gezildi[0][0] = true;
  git(0, 0, 0);
  cout << "uyan patika: " << patika << endl;
  return 0;
}
