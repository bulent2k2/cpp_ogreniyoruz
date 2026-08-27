#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

int main() {
  int a{2000}, b{3000};

  cout << "2000'in küpü (int) : " << a * a * a << endl;   // eksi!
  cout << "3000'ün küpü (int) : " << b * b * b << endl;   // yanlış!
  cout << "3000'ün küpü (long): " << 1L * b * b * b << endl;

  cout << "karekök(2000'in küpü) : " << sqrt(a * a * a) << endl; // nan

  cout << "int'in en büyüğü           : "
       << numeric_limits<int>::max() << endl;
  cout << "unsigned long'un en büyüğü : "
       << numeric_limits<unsigned long>::max() << endl;
  return 0;
}
