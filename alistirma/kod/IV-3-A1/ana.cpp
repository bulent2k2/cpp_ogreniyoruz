// IV-3-A1 · Toplamı tutan altkümeler
#include <iostream>
#include <vector>
using namespace std;
using Dizi = vector<int>;

Dizi kume, secilen;
int hedef{0}, bulunan{0};

void yaz() {
  cout << "{ ";
  for (int s : secilen) cout << s << " ";
  cout << "}" << endl;
}

void uret(size_t k, int toplam) {
  // taban: k == kume.size(); toplam == hedef ise yaz, ++bulunan
  // ALMA, AL (toplam + kume[k]), geri al
}

int main() {
  int n{0}; cin >> n;
  kume.resize(n);
  for (int& x : kume) cin >> x;
  cin >> hedef;
  uret(0, 0);
  cout << bulunan << " altküme" << endl;
  return 0;
}
