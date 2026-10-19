// II-7-I1 · Kopyayı takma ada çevirin: ekleK'ye &
#include <iostream>
using namespace std;

using Sayi  = int;
using Adres = Sayi*;      // Sayı türünün adresi de bir tür

void ekleA(Adres a, Sayi ek) { *a += ek; }   // adresle
void ekleT(Sayi& t, Sayi ek) { t  += ek; }   // takma adla
void ekleK(Sayi  k, Sayi ek) { k  += ek; }   // kopyayla (etkisiz!)

int main() {
  Sayi s{10};

  ekleK(s, 10);  cout << "kopyadan sonra   : " << s << endl;
  ekleA(&s, 10); cout << "adresten sonra   : " << s << endl;
  ekleT(s, 10);  cout << "takma addan sonra: " << s << endl;
  return 0;
}
