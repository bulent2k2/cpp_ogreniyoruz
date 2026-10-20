#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-6-K1 · Yaşam oyunu
// Çıktı: nesil sayısı kadar ilerletilmiş tahta (satır satır)
int main() {
  int n, m, nesil; cin >> n >> m >> nesil;
  Dizi<string> tahta(n);
  for (auto& s : tahta) cin >> s;
  // her nesil: her hücrenin canlı komşusunu say (8 yön), dört kuralı uygula, yeni tahtaya yaz
  for (auto& s : tahta) cout << s << endl;
  return 0;
}
