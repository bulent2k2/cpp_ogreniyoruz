> [Önceki](ders6.md) [Hepsi](icindekiler.md) [Sonraki](ders8.md)

*Özyineleme tekniği (recursion), `std::list` kalıbı, bellekle hızlandırma (*memoizasyon*), yeni türler: `konum, aralık` ve `dörtgen`, özgür bellek, özgür dizi konuları.*  

[Görsel kayıt](https://drive.google.com/file/d/1n6_-fDBSnLnbIM4GPM2d7P7gvJbVevqj) 1:39:32. 

Geçen hafta yazdığımız asal çarpan ve fibonaççi kodlarını gözden geçirdik. 
Asal çarpan bulan döngüde düzeltmeler yaptık. Fibonaççi koduna bellek ekleyerek hızlandırdık.
Sonra da yeni türler tanımlamaya büyük bir giriş yaptık, bir kaç örnek gördük.

Asal çarpanlar
---- 

Döngümüz bazı çarpanları bulmuyordu. Onu düzelttik. Bir de derste görmedik ama 
döngü yerine özyineleme yöntemiyle de bulabiliriz asal çarpanları. Örneğin:  

[Asal çarpanları özyineleyerek bulalım](https://www.onlinegdb.com/fIuuPTf33)  
Hem `namespace` örneği hem de `<list>` dosyasından `std::list` adlı dizi türü (*dizin* de denir) kullanımına dikkat. Çok faydalı bir türdür.

Fibonaççi
----

Geçen derste bu özyineleme kodunda iki terim (`fib(n-1) + fib(n-2)`) olduğu için 
çatallanma ve ikiye katlanma olduğunu konuşmuştuk. Onun için büyük sayıları hesaplamak 
çok zaman alabiliyor. Hızlandırmak için bir bellek ekledik.

[Bellekle hızlandırılmış Fibonaççi](https://onlinegdb.com/XpOcEU6jD) 
    
[Bu da sayı sınırının farkında Fibonaççi kodu](https://www.onlinegdb.com/9zcoMg7HN)  

Yeni türler
----

[Aralık, Konum ve Dörtgen türleri](https://onlinegdb.com/3fk-Akokh)

Yeni anahtar sözcükler gördük: `struct`, `class`, `const.` Ayrıca şimdilik kullanmamıza
pek gerek duymadığımız `public`, `private` ve `protected` var. Onları sonra göreceğiz.   

Yeni türler oluşturmak neden faydalı acaba diye merak ettik ve biraz yanıtladık. 
En iyisi de örneklerini görmek diye bir kaç tane yeni tür yazdık. 

Yeni bir tür oluşturmaya, elimizdeki hazır türlerden bir kaçını bir araya getirerek başlayabiliriz. 
Örneğin, iki sayıyı bir araya getirerek `konum` adlı yeni bir tür tanımlamak kolay:

```
// nokta
struct konum{
    int x{0}, y{0};  // türün içindeki veriler
    void kaydır(int dx, int dy) {  // türün içindeki yöntemlere örnek
        x += dx;
        y += dy;
    }
};
```

Bu türü kullanarak yeni nesneler, yeni değişkenler oluşturmak da kolay: 

```
konum k1{3, 4}; // x=3, y=4 koordinatları
k1.x += 2;      // sağa doğru iki birim kaydıralım
k1.kaydır(2, 2); // hem sağa hem de yukarı doğru kaydıralım
cout << k1.x * k1.y << endl; // ne yazacak?
```

Daha genel olarak:
```
tür nesne(girdi1); // yapıcı yöntemle yeni bir nesne/değişken tanımladık
oku = nesne.veri; // nesnenin içindeki verileri kullanabiliriz
nesne.veri = yaz; // nesnenin içindeki verileri değiştirebiliriz
çıktı = nesne.yöntem(girdi2); // nesnenin içindeki yöntemleri çağırabiliriz
```

Burada nokta (`.`) işlemcisinin nasıl kullanıldığını da gördük. 

Gelecek hafta iki dikdörtgenin kesişimini bulan bir yöntem ekleyerek devam ederiz. Merak edenler için örnek bir çözüm: 
[Kesişen dikdörtgenler](https://www.onlinegdb.com/edit/aUcE6ZaZy). Bu arada, 
`throw`, `operator` ve `const` adlı anahtar sözcükleri de kullanıyoruz bu kodla.

Özgür bellek/özgür dizi
----

[Özgür dizi/özgür bellek](https://www.onlinegdb.com/K0bjhI0l_). Ders sırasında bir arkadaşınız güzel ve zor bir soru sordu. Bir fonksiyon içinde oluşturduğumuz bir diziyi o fonksiyonun dışında kullanmak mümkün mü? Hem de kopyalamadan, aynı adresten. Burada bir örnek görelim. `new` ve `delete` anahtar sözcüklerini kullanıyoruz. Ama modern derleyiciler sayesinde (c++11 ve sonrası) daha akıllı ve becerikli yöntemler de var ([new/delete yerine akıllı pointer kullanımı](https://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself/22146244#22146244)). Ayrıca donanımlar da artık yeterince hızlı. Onun için fonksiyonların girdi ve çıktılarının kopyalanmasında da çok sakınca yok. Bunun bir örneği yukarıdaki özyineleyen asal çarpan kodu ([dizileri girdi ve çıktı olarak kullanmak da kolay](https://www.onlinegdb.com/fIuuPTf33)). Kullandığımız dizi (`std::list<Sayı>`) hem girdi hem de çıktı olarak bol bol kopyalanıyor. Ayrıca yine gelişmiş modern derleyiciler kopyalamak yerine çok daha hızlı olan bir adres taşıma yöntemi de kullanabiliyorlar. Bu derste kısaca gördüğümüz yapıcı (*constuctor*) ve bahsettiğimiz yıkıcı (*destructor*) yöntemlerden başka eşitleme, kopya ve taşıma yapıcıları ( *assignment constructor, copy constructor, move constructor*) da var. Sırası geldikçe önümüzdeki derslerde göreceğiz.

> [Önceki](ders6.md) [Hepsi](icindekiler.md) [Sonraki](ders8.md)
