#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(nullptr));
  const int gizli{rand() % 100 + 1};
  int hak{7};

  cout << "1 ile 100 arasında bir sayı tuttum. " << hak << " hakkın var." << endl;

  while (hak > 0) {
    cout << "Tahminin: ";
    int tahmin;
    if (not (cin >> tahmin)) break;   // girdi bitti ya da bozuk
    --hak;

    if (tahmin == gizli) {
      cout << "Bildin! " << (7 - hak) << " tahminde." << endl;
      return 0;
    }
    cout << (tahmin < gizli ? "Daha büyük." : "Daha küçük.")
         << " Kalan hak: " << hak << endl;
  }
  cout << "Hakkın bitti. Tuttuğum sayı " << gizli << " idi." << endl;
  return 0;
}
