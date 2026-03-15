[Maraton]()
====

*Aralık 2014, 1. Bronz Problem*  
*Yazarı Nick Wu*  

Maraton parkuru, sırayla ziyaret edilmesi gereken `N` kontrol noktasından (`3 <= N <= 100,000`) oluşuyor.
İlk kontrol noktası (no. 1) başlangıç ​​noktası, son nokta da (no. `N`) bitiş noktasıdır. Koşucunun bu kontrol
noktalarını sırayla ziyaret etmesi gerekiyor. Yanlız bu maratona özel olarak, kontrol noktalarından
birini atlama hakkı var. Ancak ilk ve son kontrol noktaları atlanamıyor. Bu durumda parkurun uzunluğu en az ne olur?

Maratonun parkuru sokakların ızgara şeklinde düzenlendiği bir şehir merkezinde yer alıyor.
Bu nedenle `(x1, y1)` ve `(x2, y2)` konumlarındaki iki kontrol noktası
arasındaki mesafe `|x1-x2| + |y1-y2|` ile hesaplanabilir.
Bu mesafe ölçme yöntemi - yatay uzaklık artı dikey uzaklık - bazen *Manhattan mesafesi* olarak bilinir.
Şehir merkezinde sadece yatay ya da dikey seyahat edilebileceği, yani çapraz ya da *kuş uçuşu* olarak seyahat
edilemediği anlamına da gelir.

Başka bir örnek de yonga tasarımında karşımıza çıkıyor. Yonga üstündeki transistörlerin
arasındaki bağlantılar da sadece yatay ve dikey olarak çizilebiliyor. Bunun istisnası da var ama çok yaygın değil, çünkü
yollar kısalsa da, yapım masrafı epey artıyor.

GİRDİ (marathon.in dosyası)
---- 
İlk satır N değerini verir. Sonraki N satırın her biri, bir kontrol noktasını temsil eden
`(-1000 <= x <= 1000, -1000 <= y <= 1000)` iki boşlukla ayrılmış tamsayı `x` ve `y` içerir.
Kontrol noktaları, ziyaret edilmeleri gereken sırayla verilmiştir.
Parkurun birkaç kez kendi üzerinden geçebileceğini ve aynı fiziksel konumda birden fazla 
kontrol noktasının bulunabileceğini unutmayın. Bessie böyle bir kontrol noktasını atladığında,
yalnızca o kontrol noktasının bir örneğini atlar; aynı konumda bulunan her kontrol noktasını atlamaz.

ÖRNEK GİRDİ
---- 
```
4
0 0
8 3
11 -1
10 0
```

ÇIKTI (marathon.out dosyası)
----
Koşucunun en fazla bir kontrol noktasını atlayarak koşabileceği minimum mesafeyi yazdırın.
Çıktınızı yeni bir satırla bitirmeyi unutmayın. Burada gösterilen örnekte,
`(8, 3)` konumundaki kontrol noktasını atlamak, minimum toplam mesafenin `14` olmasına yol açar.

ÖRNEK ÇIKTI
---- 
14
