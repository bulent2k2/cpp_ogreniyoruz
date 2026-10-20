#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-6-Z1 · Monsters (CSES 1194)
// Çıktı: "YES", adım, tarif  ya da  "NO"
using Kare = pair<int, int>;
int n, m;
Dizi<string> plan;
const int DY[4]{-1, 1, 0, 0}, DX[4]{0, 0, -1, 1};
const char YON[4]{'U', 'D', 'L', 'R'};

int main() {
  cin >> n >> m;
  plan.resize(n);
  for (auto& s : plan) cin >> s;
  // 1) canavar uzaklıkları (çok kaynaklı)
  // 2) A'dan gezi: uzaklik[A]+1 < canavar[komşu] ise gir; kenara varınca dur
  return 0;
}
