Adres değişkenleri ve iki boyutlu diziler
====

Önce anımsayalım: programlarımızda kullandığımız bütün değişkenler, ister yerel, ister küresel ya da evrensel olsun, hep bellekte bir yere yazılıyor. Bilgisayar belleği, kafamızdaki gibi değil, çok daha basit bir kavram: üstündeki ufak karelere sıfır ya da bir yazılan upuzun bir şerit gibi düşünebiliriz. *Cache*, *RAM*, eskiden *disk* denen yeni nesil *SSD*'ler hep kısa ya da uzun vadeli, yani uçucu ya da kalıcı bellek görevi görüyorlar. Gerisi sadece belleğin hızını ve kapasitesini belirleyen detaylar. Bu şerit bellek Alan Turing'in icat ettiği [*Türing Makinesi*](https://tr.wikipedia.org/wiki/Turing_makinesi)'nin üç önemli parçasından biri. 

Modern bilgisayarların Türing Makinesinden bir farkı, belleğin herhangi bir yerine yazıp, başka herhangi bir yerinden okuyabiliyoruz. Yani sırayla değil, rasgele istediğimiz bir yerini kullanabiliyoruz (Buna *Random Access Memory* deniyor). Onun için belleğin her parçacığının bir adresi var. *C/C++* ve benzeri dillerde bu adresleri tutan değişken türüne *pointer* deniyor. Biz **gösterici** ya da **adres** türü ve değişkeni diyebiliriz. 

Küçük bir örnekle daha iyi anlarız:
```c++
using Sayı = int;
using Adres = Sayı*;  // Sayı türünün Adresi de bir tür

void ekle(Adres b, Sayı ek) { *b += ek; }
int main() {
    Sayı s = 10;
    Adres a = &s;
    *a += 10;    // s şimdi 20 oldu
    ekle(a, 10); // s şimdi 30 oldu
    return 0;
}
```

`main()` içindeki `a` ve `ekle()` içindeki `b` iki farklı adres değişkeni, ama değerleri aynı: `s` değişkeninin bellekte yazıldığı yerin adresi. Yani ikisi de aynı değişkene işaret ediyor. Onun için, `ekle()` işlevi `main()` içindeki `s` yerel değişkeninin değerini değiştirebiliyor. 

Bu kodu [buradan](https://onlinegdb.com/HAN8BByDp) *Fork this* ile çatallayın. *Debug* tuşuna basın. `main()` satırının solundaki satır sayısına tıklayarak bir de *breakpoint* yani durak koyun. Sonra aşağıdaki terminalin üstünde *start* tuşuna basın. Sonra da onun sırasında en sağda *step into* tuşu var. Onunla programı satır satır çalıştırın. Böylece adresleri bütün detaylarıyla görmek faydalı olabilir.

İşlevin girdisi, adres yerine sayının değeri olsaydı, sayıyı değil, kopyasını değiştirirdi elbet. Bu arada kopya yerine benzer ya da ikiz de diyebiliriz, ne dersiniz? Örneğin:
```c++
using S = int;
S ekle(S ikiz, S ek) { return ikiz += ek; }
// main içinde:
S s = 10, t = 10;
t = ekle(s, 10); // t 20 oldu, s hala 10
``` 

Bu basit ve adres değişkeni kullanmayan [kod da burada](https://onlinegdb.com/mNhCeYFS8).  

İki işlev de `ekle()` adında ve basit bir toplama yapıyorlar ama epey farklılar. Girdi türleri farklı çünkü. Birisi sayıyı adresinden okuyor ve ekledikten sonra aynı adrese yazıyor. Çıktısı yok. Öbürü sayının ikizini okuyor ve arttırdıktan sonra çıktı olarak çağıran işleve geri sunuyor.  

Bu ikinci `ekle()` işlevinde küçücük bir değişiklik yaparak bir de İngilizcede *reference* denen **takma ad** kavramını görelim: 

```c++
using S = int;
S ekle(S& ikiz, S ek) { return ikiz += ek; }
// main içinde:
S s = 10, t = 10;
t = ekle(s, 10); // hem t hem de s 20 oldu
``` 

Sadece tek bir `&` imgesi ekledik ve herşey değişti! Artık `ikiz` adlı değişken sadece bir kopya değil, `s` değişkeninin bir takma adı, yani birebir kendisi. Onun için takma adıyla da olsa kendi değeri değişti. 

**C** dilinde sadece adres değişkenleri vardı. Bu takma ad becerisi yıllar sonra **C++** diliyle ortaya çıktı. Pek çok yerde artık adres yerine takma adları kullanıyoruz. Daha sade ve güvenli oluyor programlarımız. Ama iş dizilere gelince eğer akıllı dinamik dizi, yani `std::vector<>` yerine temel dizi kullanmak istersek adres değişkenleri kullanmak gerekebiliyor. Zaten akıllı dizi kalıbı da bize göstermese de kendisi yapıcı yöntemleri içinde adres değişkenleri kullanıyor. Örneğin:

```c++
using Sayı = int;
using Adres = Sayı*;
Sayı s = 10;
Adres a = new Sayı[s];
```
Bu adres şimdi bellekte peşpeşe gelen on tane sayının ilkinin adresi. Bu adrese bir eklersek, ikinci sayının adresini elde ediyoruz. Böyle işlemlere *pointer* artimatiği de derler. Örneğin:

```c++
*a = 5; // dizinin ilk sayısı 5 oldu
a++;
*a = 15; // ikinci sayı 15 oldu
a--;
*a = 10; // ilk sayı 10 oldu
*(a+9) = 100; // onuncu sayı 100 oldu
```

Sayıların hepsini yazdırmak da kolay:
```c++
using K = unsigned;
for (K k = 0; k<10; ++k) 
    std::cout << *(a+k) << " ";
```

Bu kodun hepsi [biraz daha düzenlenmiş haliyle burada](https://onlinegdb.com/2tPZnvgz8).

`new` komutu bellekte yer ayırdığı için, işimiz bitince `delete` komutuyla belleği  geri vermemizde fayda var. Onu da yukarıdaki bağlantıda görebilirsiniz. `stl::vector<Sayı> dizi(n);` ile akıllı dinamik dizi oluşturduğumuzda `vector` sınıfının yapıcı yöntemi de `new Sayı[n]` komutunu kullanır. `dizi.push_back(s);` yöntemi de gerektiğinde, yani `n`'den çok sayı yazmak istediğimizde, önce `a = new Sayı[2*n]` ile daha büyük bir yer ayırıp bütün sayıları oraya kopyalar, ve arkasından `delete [] a` ile eskisini serbest bırakır. 

Ya iki boyutlu bir dizi nasıl olacak? En kolayı şöyle:
```c++
S d1[][3] = { {2, 3, 4}, {5, 6, 7} };
S d2[][2] = { {2, 3}, {4, 5}, {6, 7} };
    
for (auto d: d1) {
    for (K k=0; k<3; ++k) 
        std::cout << d[k] << " ";
    std::cout << '\n';
}
for (auto d: d2) {
    for (K k=0; k<2; ++k)
        std::cout << d[k] << " ";
    std::cout << '\n';
}
```

Derleyici, ilk boyutun uzunluğunu eşittir işaretinin sağındaki sabit dizi değerine bakarak bulabiliyor. İkinci ve varsa sonraki boyutların uzunluğunu bizim belirtmemiz gerek. (Neden?)

Döngülerde kullandığımız `d` aslında bir adres değişkeni. Onun için `d[k]` yerine `*(d+k)` de yazabiliriz.

Bu [kodu burada](https://onlinegdb.com/uQaTKg_lq) çalıştırabilirsiniz. 

Farketmişsinizdir, iki döngü birbirine çok benziyor. Sadeleştirmek iyi olur:

```c++
void yaz(auto d, K b1, K b2) {
    for (K k1 = 0; k1<b1; ++k1) {
        for (K k2=0; k2<b2; ++k2) 
            std::cout << d[k1][k2] << " ";
        std::cout << '\n';
    }
}
   
// main içinde: 
S d1[][3] = { {2, 3, 4}, {5, 6, 7} };
S d2[][2] = { {2, 3}, {4, 5}, {6, 7} };

yaz(d1, std::size(d1), 3);
yaz(d2, std::size(d2), 2);
```

Çok boyutlu bir diziyi bu şekilde işlev girdi olarak da kullanabiliyoruz. 

Bunu da [burada çalıştırabilirsiniz](https://onlinegdb.com/0S6eTQNV6).  

Şimdi biraz daha genelleyelim. İki boyutlu dizinin boyut uzunlukları değişken olsun:
```c++
K b1 = 4, b2 = 7;
S** d;
d = new S*[b1];
for (K k=0; k<b1; ++k)
    d[k] = new S[b2];
yaz(d, b1, b2);
```

Tabii `yaz()` işlevi pek anlamlı birşey yazamayacak. Ufak bir değişiklik yapalım:
```c++
void yaz(auto d, K b1, K b2) { 
    S s = 11;
    for (K k1 = 0; k1<b1; ++k1) {
        for (K k2=0; k2<b2; ++k2) 
            std::cout << (d[k1][k2]=++s) << " ";
        std::cout << '\n';
    }
}
```
Çıktısını merak ederseniz, [kodu buradan](https://onlinegdb.com/EPrtCzTnmC) çalıştırıverin.

Tabii bellekte özel yer ayırdığımız için, temizliğini de yapmamız gerekir. O da kolay:
```c++
for (K k=0; k<b1; ++k)
    delete [] d[k];
delete [] d;
```

Şimdilik bu kadar. Derste yazdığımız kod biraz aceleye geldi ama anımsamak isterseniz [o da burada](https://onlinegdb.com/Z6_283dYl).
