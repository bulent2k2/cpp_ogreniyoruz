// IV-6-A1 · Hamilton patikaları, budamasız
// Girdi: satır sütun. Çıktı: "patika: P, çağrı: C"
#include <iostream>
#include <vector>
using namespace std;

int S{0}, T{0}, patika{0};
long long cagri{0};
vector<vector<bool>> gezildi;
const vector<pair<int, int>> yonler{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool icerdeMi(int r, int c) { return r >= 0 and r < S and c >= 0 and c < T; }

void git(int r, int c, int kalan) {
  ++cagri;
  // hedefteyiz ve kalan == 0 ise patika
  // dört yön: içeride ve gezilmemişse işaretle, in, temizle
}

int main() {
  cin >> S >> T;
  gezildi.assign(S, vector<bool>(T, false));
  gezildi[0][0] = true;
  git(0, 0, S * T - 1);
  cout << "patika: " << patika << ", çağrı: " << cagri << endl;
  return 0;
}
