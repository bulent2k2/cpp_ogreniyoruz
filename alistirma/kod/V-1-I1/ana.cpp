#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using Nokta = int;
template <class T> using Dizi = vector<T>;

// V-1-I1 · Yönsüzden yönlüye: bir satır silin
int main() {
  int n{0}, m{0};
  cin >> n >> m;
  Dizi<Dizi<Nokta>> komsular(n + 1);
  for (int k{0}; k < m; ++k) {
    Nokta a, b; cin >> a >> b;
    komsular[a].push_back(b);
    komsular[b].push_back(a);     // yönsüz: iki yöne de
  }
  for (Nokta p{1}; p <= n; ++p) {
    cout << p << ":";
    for (Nokta q : komsular[p]) cout << " " << q;
    cout << endl;
  }
  return 0;
}
