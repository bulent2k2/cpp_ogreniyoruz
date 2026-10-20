// III-6-I1 · Üç kere aynı döngü
#include <iostream>
using namespace std;

int main() {
  for (int s{0}; s < 2; ++s) {
    for (int k{0}; k < 2; ++k) cout << "*";
    cout << endl;
  }
  cout << endl;
  for (int s{0}; s < 3; ++s) {
    for (int k{0}; k < 3; ++k) cout << "*";
    cout << endl;
  }
  cout << endl;
  for (int s{0}; s < 5; ++s) {
    for (int k{0}; k < 5; ++k) cout << "*";
    cout << endl;
  }
  return 0;
}
