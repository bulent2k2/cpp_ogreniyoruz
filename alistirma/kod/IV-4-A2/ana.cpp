// IV-4-A2 · Hazırıyla: next_permutation
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string s; cin >> s;
  sort(s.begin(), s.end());
  int sayac{0};
  // do { ... } while (next_permutation(s.begin(), s.end()));
  cout << sayac << " diziliş" << endl;
  return 0;
}
