// IV-2-A1 · Merdiven
// Çıktı: "10 basamak: 89", "30 basamak: 1346269", "50 basamak: 20365011074"
#include <iostream>
#include <vector>
using namespace std;

vector<long long> bellek(51, -1);     // -1: henüz hesaplanmadı

long long yol(int n) {
  // taban; bellek; adım
  return 0;
}

int main() {
  for (int n : {10, 30, 50}) cout << n << " basamak: " << yol(n) << endl;
  return 0;
}
