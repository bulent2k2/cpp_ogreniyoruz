// II-7-A2 · Kopyalamayın, değiştirmeyin
// Çıktı: "toplam 14" / "6 2 8 2 10" / "toplam 28"
#include <iostream>
#include <vector>
using namespace std;

// toplam ve ikiyeKatla işlevlerini buraya yazın

int main() {
  vector<int> d{3, 1, 4, 1, 5};
  cout << "toplam " << toplam(d) << endl;
  ikiyeKatla(d);
  for (int x : d) cout << x << " ";
  cout << endl;
  cout << "toplam " << toplam(d) << endl;
  return 0;
}
