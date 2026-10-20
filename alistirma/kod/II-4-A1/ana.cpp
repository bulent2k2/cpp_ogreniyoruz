// II-4-A1 · Parantez: tek sayaçla
// Her satır için "dengeli" ya da "dengesiz"
#include <iostream>
#include <string>
using namespace std;

bool dengeliMi(const string& s) {
  // buraya yazın
  return false;
}

int main() {
  string s;
  while (cin >> s) cout << (dengeliMi(s) ? "dengeli" : "dengesiz") << endl;
  return 0;
}
