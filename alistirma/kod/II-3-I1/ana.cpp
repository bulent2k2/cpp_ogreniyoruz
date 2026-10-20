// II-3-I1 · Harf kümesi: yazi -> "programlama"
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
  string yazi{"kelebek kanadi"};
  set<char> harfler;
  for (char h : yazi)
    if (h != ' ') harfler.insert(h);
  for (char h : harfler) cout << h;
  cout << endl << harfler.size() << " ayrı harf" << endl;
  return 0;
}
