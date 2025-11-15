Bir kaç arkadaşınız hocam kodumuzun çalışma hızını nasıl ölçebiliriz acaba diye sordular. Şu örneğe bakıverin:  

[Onlinegdb'de çalıştırın](https://onlinegdb.com/27-NNYAr8).  
Çıktısı:  
```
--- Performans Testi ---
Dizi boyutu: 1000000 eleman
İnsa süresi: 6ms
Ortalama sorgu süresi: 0.0035μs
```

Kopyası da burada:  

```c++
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
    cout << "\n--- Performans Testi ---\n";
    
    auto baslangic = chrono::high_resolution_clock::now();
    const int n = 1000000;
    vector<int> buyuk_dizi(n);
    for (int i = 0; i < n; i++) {
        buyuk_dizi[i] = 2*i;
    }
    auto bitis = chrono::high_resolution_clock::now();
    auto insa_suresi = chrono::duration_cast<chrono::milliseconds>(bitis - baslangic);

    baslangic = chrono::high_resolution_clock::now();
    const int q = 10000;
    int toplam=0;
    for (int i = 0; i < q; i++) {
      toplam += buyuk_dizi[i];
    }
    bitis = chrono::high_resolution_clock::now();
    auto sorgu_suresi = chrono::duration_cast<chrono::microseconds>(bitis - baslangic).count() / (1.0 * q);
    cout << fixed << setprecision(4);
    cout << "Dizi boyutu: " << n << " eleman\n";
    cout << "İnşa süresi: " << insa_suresi.count() << "ms\n";
    cout << "Ortalama sorgu süresi: " << sorgu_suresi << "μs\n";
    return 0;
}
```