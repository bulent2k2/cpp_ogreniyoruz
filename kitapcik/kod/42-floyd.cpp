#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using U = long long;
const U SONSUZ = 1e15;

int main() {
  const int n = 4;
  vector<vector<U>> f(n+1, vector<U>(n+1, SONSUZ));
  for (int a = 1; a <= n; ++a) f[a][a] = 0;

  auto yol = [&](int a, int b, U u) { f[a][b] = f[b][a] = min(f[a][b], u); };
  yol(1,2,5); yol(1,4,9); yol(2,3,2); yol(3,4,7);

  // Floyd-Warshall: üç iç içe döngü, o = "ortadaki durak"
  for (int o = 1; o <= n; ++o)
    for (int a = 1; a <= n; ++a)
      for (int b = 1; b <= n; ++b)
        f[a][b] = min(f[a][b], f[a][o] + f[o][b]);

  cout << "     ";
  for (int b = 1; b <= n; ++b) cout << setw(4) << b;
  cout << "\n     " << string(4*n, '-') << endl;
  for (int a = 1; a <= n; ++a) {
    cout << setw(3) << a << " |";
    for (int b = 1; b <= n; ++b) cout << setw(4) << f[a][b];
    cout << endl;
  }
  return 0;
}
