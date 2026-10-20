#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-2-A2 · Yol var mı?
// Girdi: çizge, sonra q ve q satır "a b". Çıktı: her soru için "a -> b: evet/hayır"
Dizi<Dizi<Nokta>> komsular;
Dizi<bool> gezildi;

void gez(Nokta bu) {
  if (gezildi[bu]) return;
  gezildi[bu] = true;
  for (Nokta su : komsular[bu]) gez(su);
}

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  komsular.assign(n + 1, {});
  for (int k{0}; k < m; ++k) { Nokta a, b; cin >> a >> b; komsular[a].push_back(b); }
  int q{0}; cin >> q;
  // her soru: gezildi'yi sıfırla, gez(a), gezildi[b]?
  return 0;
}
