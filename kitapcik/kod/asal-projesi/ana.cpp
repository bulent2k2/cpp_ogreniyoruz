#include <iostream>
#include <cassert>
#include "asal.h"

void dene() {
  assert(asalMi(2));
  assert(asalMi(97));
  assert(not asalMi(1));
  assert(not asalMi(91));      // 7 * 13
  assert(carpanlar(60).size() == 4);   // 2, 2, 3, 5
  std::cout << "denemeler geçti." << std::endl;
}

int main(int argc, char** argv) {
  dene();
  int n = (argc > 1) ? std::stoi(argv[1]) : 60;
  std::cout << n << " sayısının asal çarpanları:";
  for (auto c : carpanlar(n)) std::cout << " " << c;
  std::cout << std::endl;
  return 0;
}
