#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

using Nokta = unsigned;
template <class T> using Dizi = vector<T>;

// yönlü çizge: komsular[n] = n'den çıkan okların vardığı noktalar
Dizi<Dizi<Nokta>> komsular;
Dizi<bool> gezildi;

void hazirla(size_t n) { gezildi.assign(n + 1, false); }

// 1) derinlemesine, özyinelemeyle
void gez(Nokta bu) {
  if (gezildi[bu]) return;
  gezildi[bu] = true;
  cout << bu << " ";
  for (Nokta su : komsular[bu]) gez(su);
}

// 2) derinlemesine, yığınla
void gez2(Nokta ilk) {
  stack<Nokta> tepe;
  tepe.push(ilk);
  while (not tepe.empty()) {
    Nokta bu = tepe.top(); tepe.pop();
    if (gezildi[bu]) continue;
    gezildi[bu] = true;
    cout << bu << " ";
    for (Nokta su : komsular[bu]) if (not gezildi[su]) tepe.push(su);
  }
}

// 3) enlemesine, kuyrukla
void gez3(Nokta ilk) {
  queue<Nokta> kuyruk;
  kuyruk.push(ilk);
  while (not kuyruk.empty()) {
    Nokta bu = kuyruk.front(); kuyruk.pop();
    if (gezildi[bu]) continue;      // aynı nokta kuyruğa iki yoldan girebilir!
    gezildi[bu] = true;
    cout << bu << " ";
    for (Nokta su : komsular[bu]) if (not gezildi[su]) kuyruk.push(su);
  }
}

int main() {
  const Nokta n = 7;
  komsular.assign(n + 1, {});
  auto bagla = [](Nokta a, Nokta b) { komsular[a].push_back(b); };
  bagla(1,2); bagla(1,3); bagla(2,5); bagla(3,4);
  bagla(4,6); bagla(4,7); bagla(5,7); bagla(6,1); bagla(7,5);

  cout << "derinlemesine (özyineleme): "; hazirla(n); gez(1);  cout << endl;
  cout << "derinlemesine (yığınla)   : "; hazirla(n); gez2(1); cout << endl;
  cout << "enlemesine    (kuyrukla)  : "; hazirla(n); gez3(1); cout << endl;
  return 0;
}
