// III-3-A2 · Her gün bozulan test
// ./prog [yıl ay gün]: verilmezse bugün. Çıktı: "Doğumdan bu yana N gün geçti."
#include <iostream>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

const year_month_day DOGUM{year{2010}, month{9}, day{2}};

int main(int argc, char** argv) {
  sys_days bugun{floor<days>(system_clock::now())};
  // argc == 4 ise bugun'ü argv'den kurun
  int gecen = (bugun - sys_days{DOGUM}).count();
  cout << "Doğumdan bu yana " << gecen << " gün geçti." << endl;
  return 0;
}
