// I-5-K1 · Oyunu büyütün. Beklenen çıktı yok: make ile derleyip oynayın.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(nullptr));
  const int gizli{rand() % 100 + 1};
  const int toplamHak{7};
  int hak{toplamHak};

  cout << "1 ile 100 arasında bir sayı tuttum. " << hak << " hakkın var." << endl;

  while (hak > 0) {
    cout << "Tahminin: ";
    int tahmin;
    if (not (cin >> tahmin)) break;   // girdi bitti ya da bozuk
    --hak;

    if (tahmin == gizli) {
      cout << "Bildin! " << (toplamHak - hak) << " tahminde." << endl;
      return 0;
    }
    cout << (tahmin < gizli ? "Daha büyük." : "Daha küçük.")
         << " Kalan hak: " << hak << endl;
  }
  cout << "Hakkın bitti. Tuttuğum sayı " << gizli << " idi." << endl;
  return 0;
}
