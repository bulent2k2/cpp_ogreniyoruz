// III-6-A1 · Dört tablo, bir hata
#include <iostream>
using namespace std;

int main() {
  cout << "6:";
  for (int k{1}; k <= 10; ++k) cout << " " << 6 * k;
  cout << endl;
  cout << "7:";
  for (int k{1}; k <= 10; ++k) cout << " " << 7 * k;
  cout << endl;
  cout << "8:";
  for (int k{1}; k <= 10; ++k) cout << " " << 7 * k;
  cout << endl;
  cout << "9:";
  for (int k{1}; k <= 10; ++k) cout << " " << 9 * k;
  cout << endl;
  return 0;
}
