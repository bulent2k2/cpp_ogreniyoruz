// III-5-A1 · Üç sınır, üç süre
// Sayılar cout'a, süreler cerr'e
#include <iostream>
#include <chrono>
using namespace std;
using saat = chrono::steady_clock;

bool asalN(int n)    { /* bölen < n */      return false; }
bool asalYarim(int n){ /* bölen <= n/2 */   return false; }
bool asalKok(int n)  { /* bölen*bölen <= n */ return false; }

template <typename F>
void olc(const char* ad, F asal) {
  auto basla = saat::now();
  int sayac{0};
  for (int n{2}; n < 200000; ++n) if (asal(n)) ++sayac;
  auto ms = chrono::duration_cast<chrono::milliseconds>(saat::now() - basla).count();
  cout << ad << ": " << sayac << " asal" << endl;
  cerr << ad << ": " << ms << " ms" << endl;
}

int main() {
  olc("n'e kadar", asalN);
  olc("n/2'ye kadar", asalYarim);
  olc("köke kadar", asalKok);
  return 0;
}
