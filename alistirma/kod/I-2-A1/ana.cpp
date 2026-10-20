// I-2-A1 · Faktöriyel nerede taşar?
// 12! ve 13! int ile; 13! ve 20! long long ile
#include <iostream>
using namespace std;

int main() {
  int kucuk{1};
  for (int k{1}; k <= 12; ++k) kucuk *= k;
  cout << "12! (int)       : " << kucuk << endl;
  // buradan devam edin
  return 0;
}
