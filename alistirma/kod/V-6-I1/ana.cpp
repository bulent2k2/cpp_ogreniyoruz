#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-6-I1 · En yakın canavar: en uzak kareyi de yazın
#include <iomanip>
using Kare = pair<int, int>;

int main() {
  int n, m; cin >> n >> m;
  Dizi<string> plan(n);
  for (auto& s : plan) cin >> s;
  Dizi<Dizi<int>> uzaklik(n, Dizi<int>(m, -1));
  queue<Kare> kuyruk;
  for (int y{0}; y < n; ++y) for (int x{0}; x < m; ++x)
    if (plan[y][x] == 'M') { uzaklik[y][x] = 0; kuyruk.push({y, x}); }   // HEPSİ önce
  const int DY[4]{-1, 1, 0, 0}, DX[4]{0, 0, -1, 1};
  while (not kuyruk.empty()) {                                           // sonra TEK gezi
    auto [y, x] = kuyruk.front(); kuyruk.pop();
    for (int k{0}; k < 4; ++k) {
      int ny{y + DY[k]}, nx{x + DX[k]};
      if (ny < 0 or ny >= n or nx < 0 or nx >= m) continue;
      if (plan[ny][nx] == '#' or uzaklik[ny][nx] != -1) continue;
      uzaklik[ny][nx] = uzaklik[y][x] + 1;
      kuyruk.push({ny, nx});
    }
  }
  for (int y{0}; y < n; ++y) {
    for (int x{0}; x < m; ++x) {
      if (plan[y][x] == '#') cout << "##";
      else if (uzaklik[y][x] < 0) cout << "..";
      else cout << setw(2) << uzaklik[y][x];
    }
    cout << endl;
  }
  // "en uzak kare: d adım" satırını ekleyin
  return 0;
}
