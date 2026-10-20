#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-6-A1 · Yavaş ve hızlı, yan yana
// Çıktı: "aynı" / "FARKLI", sonra "yavaş: X çıkarma", "hızlı: Y çıkarma"
using Kare = pair<int, int>;
using Harita = Dizi<Dizi<int>>;
int n, m;
Dizi<string> plan;
const int DY[4]{-1, 1, 0, 0}, DX[4]{0, 0, -1, 1};

// kaynaklardan gezi: uzaklik'i doldurur, kuyruktan çıkarma sayısını döndürür
long long gez(const Dizi<Kare>& kaynaklar, Harita& uzaklik) {
  return 0;
}

int main() {
  cin >> n >> m;
  plan.resize(n);
  for (auto& s : plan) cin >> s;
  Dizi<Kare> canavarlar;
  for (int y{0}; y < n; ++y) for (int x{0}; x < m; ++x) if (plan[y][x] == 'M') canavarlar.push_back({y, x});
  // yavaş: her canavar için gez, her karede küçüğü tut; hızlı: hepsiyle tek gez
  return 0;
}
