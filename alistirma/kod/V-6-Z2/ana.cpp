#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-6-Z2 · En güvenli kare
// Çıktı: "en yakın duvara en uzak: d adım, k kare"
using Kare = pair<int, int>;

int main() {
  int n, m; cin >> n >> m;
  Dizi<string> plan(n);
  for (auto& s : plan) cin >> s;
  // kaynaklar: bütün '#' kareleri ve kenar dışı (çerçeve)
  return 0;
}
