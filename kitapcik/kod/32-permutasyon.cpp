#include <iostream>
#include <vector>
using namespace std;

const int N = 3;
vector<int> perm;
vector<bool> eklendi(N, false);
int sayac = 0;
const bool izle = true;          // akışı görmek için

void uret(int derinlik) {
  if ((int) perm.size() == N) {
    cout << string(derinlik, ' ') << "  " << ++sayac << ". permütasyon: ";
    for (int s : perm) cout << s;
    cout << endl;
    return;
  }
  for (int k = 0; k < N; ++k) {
    if (eklendi[k]) continue;

    eklendi[k] = true;
    perm.push_back(k);
    if (izle) {
      cout << string(derinlik + 1, '+') << " k=" << k << "  perm: ";
      for (int s : perm) cout << s;
      cout << endl;
    }
    uret(derinlik + 1);
    perm.pop_back();             // geri dön
    eklendi[k] = false;          // bıraktığın gibi bırak
  }
}

int main() { uret(0); return 0; }
