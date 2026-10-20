#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-3-Z1 · Yol ağı tasarımı
// Çıktı: k, sonra k satır "a b"
Dizi<Dizi<Nokta>> cizge;
Dizi<int> parca;    // parca[nokta] = kaçıncı parçada, 0: henüz yok

void parcayaEkle(Nokta n, int no) {
  // buradan devam edin
}

int main() {
  int n{0}, m{0};
  cin >> n >> m;
  cizge.assign(n + 1, {}); parca.assign(n + 1, 0);
  for (int k{0}; k < m; ++k) { Nokta a, b; cin >> a >> b; cizge[a].push_back(b); cizge[b].push_back(a); }
  Dizi<Nokta> kok;
  // parçaları bul, temsilcileri zincirle
  return 0;
}
