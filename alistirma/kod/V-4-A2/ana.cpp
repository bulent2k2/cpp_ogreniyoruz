#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-4-A2 · Labyrinth (CSES 1193)
// Çıktı: "YES", adım sayısı, tarif  ya da  "NO"
using Kare = pair<int, int>;

int main() {
  int n, m; cin >> n >> m;
  Dizi<string> plan(n);
  for (auto& s : plan) cin >> s;
  Dizi<Dizi<char>> nereden(n, Dizi<char>(m, 0));   // 0: gezilmedi; 'A' başlangıç; U/D/L/R
  // buradan devam edin
  return 0;
}
