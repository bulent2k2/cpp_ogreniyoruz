#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Sehir = unsigned;
using U     = long long;                 // uzaklık/süre
const U SONSUZ = 1e18;

using Hat   = pair<U, Sehir>;            // {süre, varış}  -- sıra ÖNEMLİ
template <class T> using OncelikSirasi =
    priority_queue<T, vector<T>, greater<T>>;   // küçükten büyüğe

vector<vector<Hat>> hatlar;

void gez(Sehir ilk, vector<U>& uzaklik) {
  OncelikSirasi<Hat> sira;
  sira.push({0, ilk});
  uzaklik[ilk] = 0;

  while (not sira.empty()) {
    auto [u, bu] = sira.top();
    sira.pop();
    if (uzaklik[bu] < u) continue;             // eski, işi bitmiş kayıt

    for (auto [sure, su] : hatlar[bu]) {
      U yeni = u + sure;
      if (yeni < uzaklik[su]) {
        uzaklik[su] = yeni;
        sira.push({yeni, su});
      }
    }
  }
}

int main() {
  Sehir n; unsigned m;
  cin >> n >> m;
  hatlar.resize(n + 1);
  while (m-- > 0) {
    Sehir kalkis, varis; U sure;
    cin >> kalkis >> varis >> sure;
    hatlar[kalkis].push_back({sure, varis});
  }
  vector<U> uzaklik(n + 1, SONSUZ);
  gez(1, uzaklik);
  for (Sehir s = 1; s <= n; ++s) cout << uzaklik[s] << " ";
  cout << endl;
  return 0;
}
