// III-4-Z1 · Sessiz taşma
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n{0}; cin >> n;
  vector<int> d(n);
  for (int& x : d) cin >> x;
  int toplam{0};
  for (int x : d) toplam += x;
  cout << "Toplam: " << toplam << endl;
  cout << "Ortalama: " << toplam / n << endl;
  return 0;
}
