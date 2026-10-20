// I-6-A2 · İç içe gölgeler: önce tahmin edin
#include <iostream>
using namespace std;

int main() {
  int x{1};
  cout << x;
  {
    int x{2};
    cout << " " << x;
    {
      int x{3};
      cout << " " << x;
    }
    cout << " " << x;
  }
  cout << " " << x << endl;
  return 0;
}
