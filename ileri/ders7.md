Yedinci ders
====

[Görsel kayıt](https://drive.google.com/file/d/1n6_-fDBSnLnbIM4GPM2d7P7gvJbVevqj) 1:39:32. 

Geçen hafta yazıdığımız asal çarpan ve fibonaççi kodlarını gözden geçirdik. 
Asal çarpan bulan döngüde düzeltme yaptık. Fibonaççi koduna bellek ekleyerek hızlandırdık.
Sonra da yeni tür tanımlamaya daha derin bir giriş yaptık, bir kaç örnek gördük.

Asal çarpanlar
---- 

Döngümüz bazı çarpanları bulmuyordu. Onu düzelttik. Bir de derste görmedik ama 
döngü yerine özyineleme yöntemiyle de bulabiliriz asal çarpanları. Örneğin:  

[Asal çarpanları özyineleyerek bulalım](https://www.onlinegdb.com/iim7dEsNE)  
Hem `namespace` örneği hem de `<list>` dosyasından `std::list` adlı dizi türü kullanımına dikkat..

Fibonaççi
----

Geçen derste bu özyineleme kodunda iki terim (`fib(n-1) + fib(n-2)`) olduğu için 
çatallanma ve ikiye katlanma olduğunu konuşmuştuk. Onun için büyük sayıları hesaplamak 
çok zaman alabiliyor. Hızlandırmak için bellek ekledik.

[Bellekle hızlandırılmış Fibonaççi](https://onlinegdb.com/XpOcEU6jD)   
[Bu da sayı sınırının farkında Fibonaççi kodu](https://www.onlinegdb.com/9zcoMg7HN)  

Yeni türler
----

[Aralık, Konum ve Dörtgen türleri](https://onlinegdb.com/3fk-Akokh)

Yeni anahtar sözcükler gördük: `struct`, `class`, `const.` Ayrıca şimdilik kullanmamıza
pek gerek duymadığımız `public`, `private` ve `protected` var. Onları sonra göreceğiz.   

Yeni türler oluşturmak neden faydalı acaba diye merak ettik ve biraz yanıtladık. 
En iyisi de örneklerini görmek diye bir kaç tane yeni tür yazdık. 

Yeni bir tür oluşturmak için varolan temel türleri bir araya getirmek gerekiyor. 
Örneğin iki sayıyı bir araya getirerek `konum` adlı yeni bir tür tanımlamak kolay:

```
// nokta
struct konum{
    int x{0},y{0};
    void kaydır(int dx, int dy) {
        x += dx;
        y += dy;
    }
};
```

Bu türü kullanarak yeni nesneler, yeni değişkenler oluşturmak da kolay: 

```
konum k1{3, 4}; // x=3, y=4 koordinatları
k1.x += 2;      // sağa doğru iki birim kaydıralım
k1.kaydır(2, 2);
cout << k1.x * k1.y << endl; // ne yazacak?
```

Daha genel olarak:
```
tür nesne(girdi1); // yapıcı yöntemle yeni bir nesne/değişken tanımladık
oku = nesne.veri; // nesneye özel verileri kullanabiliriz
nesne.veri = yaz; // nesneye özel verileri değiştirebiliriz
çıktı = nesne.yöntem(girdi2); // nesneye özel yöntemleri çağırabiliriz
```

Burada nokta (`.`) işlemcisinin nasıl kullanıldığını da gördük. 


Özgür bellek/özgür dizi
----

[Özgür dizi/özgür bellek](https://www.onlinegdb.com/K0bjhI0l_). Ders sırasında bir arkadaşınız güzel ve zor bir soru sordu. Bir fonksiyon içinde oluşturduğumuz bir diziyi o fonksiyonun dışında kullanmak mümkün mü? Hem de kopyalamadan, aynı adresten. Burada bir örnek görelim. `new` ve `delete` anahtar sözcüklerini kullanıyoruz. Ama modern derleyiciler sayesinde (c++11 ve sonrası) daha akıllı ve becerikli yöntemler de var ([new/delete yerine akıllı pointer kullanımı](https://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself/22146244#22146244)). Ayrıca donanımlar da artık yeterince hızlı. Onun için fonksiyonların girdi ve çıktılarının kopyalanmasında da çok sakınca yok. Bunun bir örneği yukarıdaki özyineleyen asal çarpan kodu ([dizileri girdi ve çıktı olarak kullanmak da kolay](https://www.onlinegdb.com/iim7dEsNE)). Kullandığımız dizi (`std::list<Sayı>`) hem girdi hem de çıktı olarak bol bol kopyalanıyor. Ayrıca yine gelişmiş modern derleyiciler kopyalamak yerine çok daha hızlı olan bir adres taşıma yöntemi de kullanabiliyorlar. Bu derste kısaca gördüğümüz yapıcı (*constuctor*) ve bahsettiğimiz yıkıcı (*destructor*) yöntemlerden başka eşitleme, kopya ve taşıma yapıcıları ( *assignment constructor, copy constructor, move constructor*) da var. Sırası geldikçe önümüzdeki derslerde göreceğiz.

