// IV-7-A2 · Tekrarlı harflerin permütasyonları
// Çıktı: "3 farklı permütasyon" sonra aab / aba / baa
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

string yazi, perm;
vector<bool> eklendi;
set<string> farkli;

void uret() {
  // taban: perm.size() == yazi.size() -> farkli.insert(perm)
  // her k için: eklendi değilse ekle, derine in, geri al
}

int main() {
  cin >> yazi;
  eklendi.assign(yazi.size(), false);
  uret();
  // yazdır
  return 0;
}
