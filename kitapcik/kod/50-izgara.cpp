#include <iostream>
#include <vector>
#include <map>
using namespace std;
using Sayi = unsigned long long;

int N = 20;                       // NxN ızgara
long cagri1 = 0, cagri2 = 0;

// 1) yukarıdan aşağı, belleksiz
Sayi yol1(int r, int c) {
  ++cagri1;
  if (r == 0 or c == 0) return 1;          // kenardaysak tek yol var
  return yol1(r-1, c) + yol1(r, c-1);
}

// 2) yukarıdan aşağı + bellek (memoizasyon)
map<pair<int,int>, Sayi> bellek;
Sayi yol2(int r, int c) {
  ++cagri2;
  if (r == 0 or c == 0) return 1;
  auto anahtar = make_pair(r, c);
  if (bellek.contains(anahtar)) return bellek[anahtar];
  return bellek[anahtar] = yol2(r-1, c) + yol2(r, c-1);
}

// 3) aşağıdan yukarı, iki boyutlu çizelge
Sayi yol3(int n) {
  vector<vector<Sayi>> t(n+1, vector<Sayi>(n+1, 1));
  for (int r = 1; r <= n; ++r)
    for (int c = 1; c <= n; ++c)
      t[r][c] = t[r-1][c] + t[r][c-1];
  return t[n][n];
}

// 4) aşağıdan yukarı, tek satır bellek
Sayi yol4(int n) {
  vector<Sayi> satir(n+1, 1);
  for (int r = 1; r <= n; ++r)
    for (int c = 1; c <= n; ++c)
      satir[c] += satir[c-1];          // satir[c] eski değeri = üstteki satır
  return satir[n];
}

int main() {
  cout << "12x12 belleksiz : " << yol1(12,12) << "  (" << cagri1 << " çağrı)" << endl;
  cout << "12x12 bellekli  : " << yol2(12,12) << "  (" << cagri2 << " çağrı)" << endl;
  cout << "20x20 çizelgeyle: " << yol3(20) << endl;
  cout << "20x20 tek satır : " << yol4(20) << endl;
  return 0;
}
