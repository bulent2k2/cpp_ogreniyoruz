// II-2-Z1 · Tuzağı kuran program
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
  map<string, int> plaka{{"Ankara", 6}, {"İstanbul", 34}, {"İzmir", 35}};
  set<string> sorulan;
  int bulunan{0};
  string sehir;
  while (cin >> sehir) {
    sorulan.insert(sehir);
    if (plaka[sehir] != 0) ++bulunan;      // tuzak burada
  }
  cout << "sorulan ayrı şehir: " << sorulan.size() << endl;
  cout << "defterde bulunan  : " << bulunan << endl;
  cout << "defterin boyu     : " << plaka.size() << endl;
  return 0;
}
