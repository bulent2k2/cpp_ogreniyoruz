// IV-4-A1 · Harflerin sırası
// Girdi: sözcük. Çıktı: bütün dizilişler, sonda "n diziliş"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string sozcuk, dizilis;
vector<bool> eklendi;
int sayac{0};

void uret() {
  // taban: dizilis.size() == sozcuk.size()
  // her kullanılmamış harf için: seç, derine in, geri al
}

int main() {
  cin >> sozcuk;
  eklendi.assign(sozcuk.size(), false);
  uret();
  cout << sayac << " diziliş" << endl;
  return 0;
}
