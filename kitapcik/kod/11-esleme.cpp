#include <iostream>
#include <map>
#include <string>
using namespace std;

using Sayac = map<char, int>;

int main() {
  string yazi{"kelebek kanadi"};

  Sayac kac;
  for (char h : yazi)
    if (h != ' ') ++kac[h];          // yoksa sıfırdan başlar

  for (auto [harf, adet] : kac)      // anahtarlar kendiliğinden sıralı
    cout << harf << " -> " << adet << endl;

  cout << "kaç ayrı harf: " << kac.size() << endl;

  // Dikkat! Olmayan bir anahtarı [] ile okumak onu YARATIR:
  cout << "z kaç kere: " << kac['z'] << endl;
  cout << "kaç ayrı harf: " << kac.size() << "  <- arttı!" << endl;

  // Doğrusu:
  cout << "q var mı: " << (kac.contains('q') ? "evet" : "hayır") << endl;
  cout << "kaç ayrı harf: " << kac.size() << "  <- değişmedi" << endl;
  return 0;
}
