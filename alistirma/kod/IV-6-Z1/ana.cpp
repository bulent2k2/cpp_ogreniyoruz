// IV-6-Z1 · Kendi budamanız
// Çıktı: "budamasız: P patika, C1 çağrı" / "kitapçık: ..., C2 çağrı" / "sizinki: ..., C3 çağrı"
#include <iostream>
#include <vector>
using namespace std;

int S{0}, T{0}, patika{0}, kural{0};   // kural: 0 budamasız, 1 kitapçık, 2 sizinki
long long cagri{0};
vector<vector<bool>> gezildi;
const vector<pair<int, int>> yonler{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool icerdeMi(int r, int c) { return r >= 0 and r < S and c >= 0 and c < T; }
bool dolu(int r, int c) { return not icerdeMi(r, c) or gezildi[r][c]; }

void git(int r, int c, int kalan) {
  ++cagri;
  // kural'a göre buda; gerisi IV-6-A2
}

void calistir(const char* ad, int k) {
  kural = k; patika = 0; cagri = 0;
  gezildi.assign(S, vector<bool>(T, false));
  gezildi[0][0] = true;
  git(0, 0, S * T - 1);
  cout << ad << ": " << patika << " patika, " << cagri << " çağrı" << endl;
}

int main() {
  cin >> S >> T;
  calistir("budamasız", 0);
  calistir("kitapçık", 1);
  calistir("sizinki", 2);
  return 0;
}
