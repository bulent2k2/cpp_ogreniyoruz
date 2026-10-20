// III-6-Z1 · Dört yön, bir sınır denetimi
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  vector<string> g(a);
  for (auto& s : g) cin >> s;
  for (int i{0}; i < a; ++i) {
    for (int j{0}; j < b; ++j) {
      int c{0};
      if (i - 1 >= 0 and g[i - 1][j] == '#') ++c;
      if (i + 1 < a and g[i + 1][j] == '#') ++c;
      if (j - 1 >= 0 and g[i][j - 1] == '#') ++c;
      if (j + 1 <= b and g[i][j + 1] == '#') ++c;
      cout << c;
    }
    cout << endl;
  }
  return 0;
}
