> [Önceki](ders5.md) [Hepsi](icindekiler.md) [Sonraki](ders7.md)

*Fibonaççi dizisi, asal çarpanlar, yeni türlere ve Project Euler'den 15. soruya bir bakış.*

Geçen hafta Project Euler'in ilk sorusunu çözmüştük beraber. Bu derste de iki soruyu daha çözdük. 

[PE 2](https://projecteuler.net/problem=2): Fibonaççi serisi.  
[PE 3](https://projecteuler.net/problem=3): Asal çarpanlar. 

Çözümler aşağıda.  

Dersimizin sonunda kendi türlerimizi tanımlamaya hızlı bir giriş yaptık. Şu ana kadar çoğunlukla temel türler görmüş ve kullanmıştık sadece. Örneğin: `bool`, `int`, `double`, `char`. Bir de standart kütüpten türler gördük. Örneğin `std::string`, `std::vector`, vb. Ama ya `Kişi` diye bir tür olsun ve ad, soyad, tel bilgilerini biraya getirsin istersek? Onun için bir de `Telefon` diye bir tür faydalı olmaz mı? Ya da geometrik şekiller için örneğin `Dikdörtgen` diye bir tür? Bunları gelecek hafta görmeye başlayalım.   

Beraber yazdığımız kodlar
----
[Fibonaççi ve özyineleme]( 
https://www.onlinegdb.com/3BkmN8ubE). Bunda özyinelemeli fonksiyon tanımlaması yapmıştık, ama hatalı olmuş. Daha doğrusu şöyle olacak: 
```
// klasik fonksiyon tanımı bire bir:
y = f(x) // yani (x1, y1), (x2, y2), (x3, y3), ...

// özyinelemeli tanım:
f(0) = sabit
f(n+1) = g(f(n), f(n-1), f(n-2), ..., f(1), f(0))
// yani daha önceki bazı değerlerin bir fonksiyonu
```  

[PE 2 çözümü]( 
https://www.onlinegdb.com/NPW4wUzoH)  

[PE 3 çözümü](  
https://www.onlinegdb.com/Yiqp2YvUo)  

[Yeni türlere giriş (İngilizce'si user type)](  
https://sololearn.com/compiler-playground/cVc74iqt2Ul0)  

Yukarıdaki yeni türlere giriş kodunun en başında temel sayı türleriyle ilgili küçük bir soru var. Onu da yanıtlamaya çalışın.  

Bir de c++ temel türlerle kolaylıkla hesaplayabileceğimiz en büyük doğal sayının şu olduğunu bulun:  
    18446744073709551615.  
Türü: `unsigned long`. 
Okuması daha kolay olsun diye virgüllerle yazalım:  
    18,446,744,073,709,551,615.  
Yani 18 milyar kere milyardan fazla.  
Yani 1.8e19'dan fazla ama 1.8e20'den az.  
Doğru mu?  
Yanıtı için biraz düşündükten sonra şuna bakın:
[Sayısal Sınırlar](https://onlinegdb.com/MMtBYyiXQ).  

PE 15
----
[PE 15](https://projecteuler.net/problem=15) Project Euler'in 15. problem çok güzel ve öğretici. Aradakileri atlamakta pek sakınca yok. Onlara sonra döneriz. Bu problem satranç tahtasının çizgileri üzerinde en kısa yolları bulmak ve saymakla ilgili. Sol üst köşeden sağ alt köşeye giden yolların hepsini saymak istiyoruz. Gelecek dersten önce biraz uğraşmanızda fayda var. Şu ipuçları işinize yarayabilir:  

*İpucu 1)* 1x1'lik tahtada sadece iki yol var. Birinci yol sağa git, sonra aşağıya git olsun. Öbür yol da önce aşağıya git sonra sağa git olacak. 2x2'lik tahtada 6 yol var. Bunları 1x1'lik çözümü kullanarak bulalım. Yani, bir problemi çözmeden önce ona benzeyen daha küçük bir problemi çözmek. Bu indirgeme tekniği çok becerikli ve genel bir tekniktir ve **dynamic programming** adıyla da bilinir. Ama nasıl olacak? İkinci ipucuna da bakın:

*İpucu 2)* PE 2'de gördüğümüz özyineleme (recursion) yöntemi çok faydalı olacak. Ama 10x10'a kadar deneyin. Sonra çok yavaşlar ve hatta belleğe sığmayabilir!   

*İpucu 3)* Küçük tahtadaki, yani daha önce bulduğumuz yanıtı iki boyutlu bir diziyle (`bellek[N][N]`) belleğe yazarsak, tekrar tekrar özyinelemeye ve hesaplamaya gerek kalmaz. Fibonaççi serisini hızlandırmak için tek boyutlu bellek yeter (`bellek[N]`). Bakın bu çözüm derste yaptığımıza çok benziyor ama çok daha hızlı:  [hızlı fibonaççi](https://onlinegdb.com/9zcoMg7HN).    

*İpucu 4)* Çok sade ve güzel bir çözümü var. Özyinelemenin gücünü ortaya koyacak iyice.

Biraz düşünün, biraz kod yazın, gelecek hafta beraber çözelim.    

Not
----
*Dinamik programlama* diye google edince yapay beyinden faydalı olabilecek bilgiler çıktı. YouTube videosuna link de var, ilgilenenlere: [Gemini on Dynamic Programming](https://docs.google.com/document/d/1ASiWWVzfq-02uKg9foiEJ0XCbrhyJHPJvqJIVoPA11g/edit?usp=sharing).

> [Önceki](ders5.md) [Hepsi](icindekiler.md) [Sonraki](ders7.md)
