// III-4-I1 · dout'u kapatın
#include <iostream>
#include <vector>
using namespace std;

bool yaz = true;                 // ayıklama açık kalmış
ostream nout{nullptr};           // hiçbir yere yazmayan akım
ostream& dout = yaz ? cout : nout;

int main() {
  int n{0}; cin >> n;
  vector<int> d(n);
  for (int& x : d) cin >> x;
  int enBuyuk{d[0]};
  for (int x : d) {
    dout << "x=" << x << " enBuyuk=" << enBuyuk << endl;
    if (x > enBuyuk) enBuyuk = x;
  }
  cout << "En büyük: " << enBuyuk << endl;
  return 0;
}
