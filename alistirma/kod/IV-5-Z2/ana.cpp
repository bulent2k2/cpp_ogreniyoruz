// IV-5-Z2 · Erken mi, geç mi?
// Çıktı: "erken: 4 çözüm, X çağrı" ve "geç: 4 çözüm, Y çağrı"
#include <iostream>
#include <vector>
using namespace std;

const int N{6};
vector<int> yer(N);
long long cagri{0};
int cozum{0};

bool uygun(int satir, int s) {   // önceki satırlardaki vezirlerle çakışıyor mu?
  for (int r{0}; r < satir; ++r)
    if (yer[r] == s or yer[r] - r == s - satir or yer[r] + r == s + satir) return false;
  return true;
}

void erken(int satir) { /* uygun değilse hiç inme */ }
void gec(int satir)   { /* hep in; satir == N olunca bütün tahtayı denetle */ }

int main() {
  cagri = 0; cozum = 0; erken(0);
  cout << "erken: " << cozum << " çözüm, " << cagri << " çağrı" << endl;
  cagri = 0; cozum = 0; gec(0);
  cout << "geç: " << cozum << " çözüm, " << cagri << " çağrı" << endl;
  return 0;
}
