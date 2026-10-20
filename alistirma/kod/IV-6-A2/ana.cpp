// IV-6-A2 · Kitapçığın budaması
// IV-6-A1'in kodunu alın; git()'in başına budama kuralını ekleyin
#include <iostream>
#include <vector>
using namespace std;

int S{0}, T{0}, patika{0};
long long cagri{0};
vector<vector<bool>> gezildi;
const vector<pair<int, int>> yonler{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool icerdeMi(int r, int c) { return r >= 0 and r < S and c >= 0 and c < T; }
bool dolu(int r, int c) { return not icerdeMi(r, c) or gezildi[r][c]; }

void git(int r, int c, int kalan) {
  ++cagri;
  // budama: yukarı & aşağı dolu, sol & sağ boş  ya da  sol & sağ dolu, yukarı & aşağı boş -> return
  // gerisi IV-6-A1
}

int main() {
  cin >> S >> T;
  gezildi.assign(S, vector<bool>(T, false));
  gezildi[0][0] = true;
  git(0, 0, S * T - 1);
  cout << "patika: " << patika << ", çağrı: " << cagri << endl;
  return 0;
}
