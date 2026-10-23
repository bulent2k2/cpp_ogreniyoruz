// III-5-Z1 · Tekrar var mı, üç yol, üç boy
// Sonuçlar cout'a, süreler cerr'e. Süre tablonuzu buraya yorum olarak yazın.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
using namespace std;
using saat = chrono::steady_clock;

vector<int> veri(int n) {              // 0..n-1 karışık, son iki öge eşit
  vector<int> d(n);
  for (int k{0}; k < n; ++k) d[k] = (long long)k * 7919 % n;
  d[n - 1] = d[n - 2];
  return d;
}

bool tekrarKume(const vector<int>& d) {
  set<int> g;
  for (int x : d) if (not g.insert(x).second) return true;
  return false;
}
bool tekrarSirala(vector<int> d) { /* sıralayıp komşulara bakın */ return false; }
bool tekrarDongu(const vector<int>& d) { /* iç içe iki döngü */ return false; }

template <typename F>
void olc(const char* ad, F f, int n) {
  auto basla = saat::now();
  bool sonuc{f(veri(n))};
  auto ms = chrono::duration_cast<chrono::milliseconds>(saat::now() - basla).count();
  cout << ad << " n=" << n << ": " << (sonuc ? "tekrar var" : "tekrar yok") << endl;
  cerr << ad << " n=" << n << ": " << ms << " ms" << endl;
}

int main() {
  for (int n : {10000, 30000, 100000, 1000000}) {
    olc("küme   ", tekrarKume, n);
    olc("sırala ", tekrarSirala, n);
    if (n <= 30000) olc("döngü  ", tekrarDongu, n);
  }
  return 0;
}
