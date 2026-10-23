// VI-7-A2 · Engelli ızgara, iki yolla
// Çıktı: "en kısa yol: k adım" ve "sağ-aşağı yol sayısı: m"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
  int S{0}, K{0}; cin >> S >> K;
  vector<string> g(S);
  for (string& satir : g) cin >> satir;
  // 1) kuyrukla enlemesine gezi: uzaklik[s][k]
  // 2) çizelge: yol[s][k] = yol[s-1][k] + yol[s][k-1], engel 0, yol[0][0] = 1
  return 0;
}
