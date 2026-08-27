#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
using K = int;
template <class T> using Dizi = vector<T>;

struct Bilgi { bool yol; char adim; };     // müsait mi, buraya nereden geldik
const Bilgi YOL{true, '.'}, DUVAR{false, '#'};
using Tahta = Dizi<Dizi<Bilgi>>;

struct Oda { K y, x; };
using Komsu = pair<Oda, char>;

int main() {
  Dizi<string> plan{           // A: başlangıç, B: çıkış
    "#########",
    "#A#.....#",
    "#.#.###.#",
    "#.#...#.#",
    "#.#####.#",
    "#......B#",
    "#########"};

  K n = plan.size(), m = plan[0].size();
  Tahta t(n, Dizi<Bilgi>(m, DUVAR));
  Oda A{0,0}, B{0,0};
  for (K y = 0; y < n; ++y)
    for (K x = 0; x < m; ++x) {
      char c = plan[y][x];
      if (c != '#') t[y][x] = YOL;
      if (c == 'A') A = {y, x};
      if (c == 'B') B = {y, x};
    }

  queue<Oda> kuyruk;
  kuyruk.push(A);
  t[A.y][A.x] = {false, 'A'};
  bool vardik = false;

  while (not kuyruk.empty()) {
    auto [y, x] = kuyruk.front();
    kuyruk.pop();
    if (y == B.y and x == B.x) { vardik = true; break; }

    Dizi<Komsu> komsular{{{y-1,x},'U'}, {{y+1,x},'D'},
                         {{y,x-1},'L'}, {{y,x+1},'R'}};
    for (auto [oda, yon] : komsular)
      if (t[oda.y][oda.x].yol) {
        t[oda.y][oda.x] = {false, yon};   // hem işaretle hem yönü kaydet
        kuyruk.push(oda);
      }
  }

  if (not vardik) { cout << "yol yok" << endl; return 0; }

  string yolTarifi;                       // B'den geriye doğru
  for (Oda o = B; not (o.y == A.y and o.x == A.x); ) {
    char yon = t[o.y][o.x].adim;
    yolTarifi += yon;
    if (yon == 'U') ++o.y; else if (yon == 'D') --o.y;
    else if (yon == 'L') ++o.x; else --o.x;
  }
  string ters(yolTarifi.rbegin(), yolTarifi.rend());
  cout << "en kısa yol " << ters.size() << " adım: " << ters << endl;
  return 0;
}
