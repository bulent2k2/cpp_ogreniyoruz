#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-4-A1 · Uzaklık haritası
// Çıktı: n satır; her kare 2 karakter: "##" duvar, ".." ulaşılamaz, " 3" uzaklık
#include <iomanip>
using Kare = pair<int, int>;

int main() {
  int n, m; cin >> n >> m;
  Dizi<string> plan(n);
  for (auto& s : plan) cin >> s;
  Dizi<Dizi<int>> uzaklik(n, Dizi<int>(m, -1));
  // A'yı bul, kuyrukla gez, uzaklıkları yaz, haritayı bas
  return 0;
}
