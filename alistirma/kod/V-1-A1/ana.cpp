#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-1-A1 · Komşuluk matrisi
// Çıktı: n satır, her satırda n tane 0/1, boşlukla ayrılmış
int main() {
  int n{0}, m{0};
  cin >> n >> m;
  Dizi<Dizi<int>> km(n + 1, Dizi<int>(n + 1, 0));
  // bağları okuyun, matrisi doldurun, yazın
  return 0;
}
