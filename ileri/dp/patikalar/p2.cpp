/*
 https://atcoder.jp/contests/dp/tasks/dp_h
 https://atcoder.jp/contests/dp/submissions/70321887
*/

#include <iostream>
#include <string>

#ifdef DEBUG
std::ostream & dout = std::cout;
#else
std::ostream dout = std::ostream(nullptr);
#endif

const long N=1001;
bool saha[N][N]; // satır/sütun (row/col) false: boş, true: duvar var.
int H, W;

const long MOD = 1e9 + 7;
long bellek[N][N];

long patikalar(int r, int c);

long sonSatır(int c) {
  if (c == W) return 1;
  int p = bellek[H][c];
  if (p == -1) {
    if (saha[H][c]) { // duvar
      for (int k = 1; k <= c; k++) bellek[H][k] = 0;
      return 0;
    }
    p = patikalar(H, c+1);
    bellek[H][c+1] = p;
  }
  return (long) p;
}
long sonSütun(int r) {
  if (r == H) return 1;
  int p = bellek[r][W];
  if (p == -1) {
    if (saha[r][W]) { // duvar
      for (int k = 1; k <= r; k++) bellek[k][W] = 0;
      return 0;
    }
    p = patikalar(r+1, W);
    bellek[r+1][W] = p;
  }
  return (long) p;
}

long patikalar(int r, int c) {
  if (r == H) return sonSatır(c);
  else if (c == W) return sonSütun(r);
  long p1=bellek[r+1][c], p2=bellek[r][c+1];
  if (p1 == -1) {
    if (saha[r+1][c]) p1 = 0; // duvar
    else p1 = patikalar(r+1, c);
    bellek[r+1][c] = p1;
  }
  if (p2 == -1) {
    if (saha[r][c+1]) p2 = 0; // duvar
    else p2 = patikalar(r, c+1);
    bellek[r][c+1] = p2;
  }
  return (p1 + p2) % MOD;
}

long bul() {
  return patikalar(1, 1) % MOD;
}

void oku() {
  const char BOS='.';
  const char DUVAR='#';

  std::cin >> H >> W;
  dout << "H=" << H << '\n'
       << "W=" << W << '\n';
  std::string s;
  for (int r=1; r<=H; ++r) {
    std::cin >> s;
    for (int c=1; c<=W; ++c) {
      char h = s[c-1];
      if (h == BOS) saha[r][c] = false;
      else if (h == DUVAR) saha[r][c] = true;
      else throw(h);
    }
  }
}

void yaz() {
  for (int r=1; r<=H; ++r) {
    for (int c=1; c<=W; ++c)
      dout << saha[r][c];
    dout << std::endl;
  }
}

int main() {
  oku();
  yaz();
  for(int r=1; r<=H; ++r)
    for(int c=1; c<=W; ++c)
      bellek[r][c] = -1;
  dout << "Yanıt:\n";
  std::cout << bul() << std::endl;
  return 0;
}
