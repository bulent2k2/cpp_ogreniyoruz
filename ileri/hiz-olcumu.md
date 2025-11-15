Bir kaç arkadaşınız hocam kodumuzun çalışma hızını nasıl ölçebiliriz acaba diye sordular. Şu örneğe bakıverin: 

```c++
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
    // Performans testi
    cout << "\n--- Performans Testi ---\n";
    
    auto baslangic = chrono::high_resolution_clock::now();
    vector<int> buyuk_dizi(1000000);
    for (int i = 0; i < 100000; i++) {
        buyuk_dizi[i] = 2*i;
    }
    auto bitis = chrono::high_resolution_clock::now();
    auto insa_suresi = chrono::duration_cast<chrono::milliseconds>(bitis - baslangic);

    baslangic = chrono::high_resolution_clock::now();
    int toplam=0;
    for (int i = 0; i < 1000; i++) {
      toplam += buyuk_dizi[i];
    }
    bitis = chrono::high_resolution_clock::now();
    auto sorgu_suresi = chrono::duration_cast<chrono::microseconds>(bitis - baslangic).count() / 1000.0;
    
    cout << fixed << setprecision(4);
    cout << "Dizi boyutu: 100,000 eleman\n";
    cout << "İnşa süresi: " << insa_suresi.count() << "ms\n";
    cout << "Ortalama sorgu süresi: " << sorgu_suresi << "μs\n";
    return 0;
}
```