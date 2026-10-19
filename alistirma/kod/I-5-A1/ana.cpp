// I-5-A1 · Kaç hak yeter?
// hakSayisi(int sinir): 2^n > sinir olan en küçük n
#include <iostream>
using namespace std;

// hakSayisi işlevini buraya yazın

int main() {
  for (int sinir : {100, 1000, 1000000})
    cout << sinir << " için " << hakSayisi(sinir) << " hak" << endl;
  return 0;
}
