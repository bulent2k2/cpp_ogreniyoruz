Fen Lisesinde C++ Öğreniyoruz
=============================

Çevirimiçi Derleyiciler
-----------------------
[Sololearn](https://www.sololearn.com/en/compiler-playground/cpp)  `std::cin >> girdi;` çalışıyor. 

[OnlineGdb](https://onlinegdb.com/MOj93f6vtA)  Alttaki terminalde girdi ve çıktılar beraber.  

[CoLiRu](https://coliru.stacked-crooked.com/a/9a5a244a826e572a).  Sağ alttaki **Edit** tuşuna basın.  

[Jupyter: Okuryazar Programlama](https://jupyter.org/).  *Literate programming*. *C++* için aşağıdaki linki kullanın.  

[Jupyter + C++](https://mybinder.org/v2/gh/jupyter-xeus/xeus-cling/stable?filepath=notebooks/xcpp.ipynb).  

Çevirimiçi Dersler (Ücretsiz)
--
[Giriş dersleri](https://www.sololearn.com/en/learn/courses/c-plus-plus-introduction)  Temel bilgiler. Bunun üzerinden geçmekte fayda var.  
[Orta seviye dersler](https://www.sololearn.com/en/learn/courses/c-plus-plus-intermediate)   Orta düzey bilgilerle devam.  
[Yapay beyinden öneriler](https://chatgpt.com/share/674775c0-d424-8009-835a-a1745715f8a7)  Ufak tefek hatalar var ama yine de çok faydalı bilgiler. Çok ileri düzey bilgilere kadar gidiveriyor.  

Diğer Siteler
--
[Project Euler](https://projecteuler.net/)  

[C++ referans](https://en.cppreference.com) 

[Ulusal Standartlar Ofisinden c++ kaynaklari](https://isocpp.org/get-started)

[#include<c++> sitesinden başvuru kaynakları](https://www.includecpp.org/resources/references/)

[Kısa özet, genel, faydalı notlar](notlar/cheatsheets.md)
--
Türkçeye kısa özet diye çevirebileceğimiz *cheatsheet* yani kopya sayfaları hem öğrendiğimiz kavramları hatırlamak için, hem de bilmediğimiz kavramlarla tanışmak için faydalı olabilir. En temel kavramları veren [kısa bir örnek burada](https://www.codewithharry.com/blogpost/cpp-cheatsheet). Daha kapsamlı ve ileri [bir örnek de burada] (https://github.com/mortennobel/cpp-cheatsheet). `c++ cheatsheet` diye arayarak daha başka kaynaklar da bulabilirsiniz. Benzeri genel ve faydalı başka notlar için de [bu alt sayfaya](notlar/cheatsheets.md) bakabilirsiniz.

[Dersler](ileri)
====
Aşağıda ilk on dersimiz hakkında bazı genel bilgiler var. Beşinci dersten itibaren, detaylı ders notlarının olduğu dosyalara linkler de aşağıda. On birinci ve daha sonraki dersler için [ileri adlı dizine](ileri) bakabilirsiniz. [Sondan bir önceki dersimiz burada](ileri/ders20.md). [En son dersimiz de burada](ileri/ders21.md).

İlk derste bazı temel yapıtaşlarını gördük 
-- 
Pekiştirmek için şu örnek programların üzerinden geçmekte fayda var.  

[İlk program](https://sololearn.com/compiler-playground/cHlx3KLO5G6d/)  
Sağ alttaki **RUN** tuşuna basın.  

[Temel veri tipleri](https://sololearn.com/compiler-playground/cPv2HfqDr8h7) sayı(`int`), kesirli sayı (`double`), harf(`char`) ve ikil(`bool`).  

[Girdi alma](https://sololearn.com/compiler-playground/c1JyEkLln8AK) `cin>>girdi`;  

[Kontrol yapıları](https://sololearn.com/compiler-playground/coLvDwg6K4Te) kontrol için `if/else` yapısı, `for` ve `while` döngüleri. Bir de basit bir işlev (*function*) tanımladık.

[İlk oyun!](https://onlinegdb.com/i4AbswzZtP) Rastgele sayı üretme yöntemi çok işe yarar.


İkinci ders
--
[Kod](https://www.sololearn.com/en/compiler-playground/cHXfjbO8i14U) işlevler, isim uzayı (`namespace`), yerel, küresel kapsam, dizilerle işlemler, temel türler, ikil(`bool`), harf(`char`), sayı(`int`), kesirli sayı(`double`). Bir de yazı (`string`), ama o temel değil, `std` yani standart kütüpten.  


Üçüncü ders
--
[Kod1](https://sololearn.com/compiler-playground/crpbSkBKD5ul) adres ve takma ad işlemcileri (*pointer/reference*).  
[Kod2](https://sololearn.com/compiler-playground/cUWBwZrMqVkd) akıllı sayı dizileri (`vector<int>`).   

Ayrıca, isim uzayları ne işe yarar diye güzel bir soru soruldu. [Yanıtı burada](ileri/neden-namespace-kullanırız.md).  

Dördüncü ders
--
[Kod1](https://www.onlinegdb.com/fork/i4AbswzZtP) sayı tahmin etme oyunu.  
[Kod2](https://www.onlinegdb.com/fork/bbM6VmacX) doğum günü girdisiyle gün sayma.  

Beşinci ders
--
[Notlar ve kodlar](ileri/ders5.md). Tam bölünebilen sayıları sayma, komut satırından derleyici çalıştırma. Ayrıca Windows'a Terminal, C++ Derleyici ve Emacs ya da başka Editör eklemek için gerekli linkler.  

Altıncı ders
--
[Notlar](ileri/ders6.md).  Fibonaççi dizisi, asal çarpanlar, yeni türlere ve Project Euler'den 15. soruya bir bakış.

Yedinci ders
--
[Notlar ve görsel kayıt](ileri/ders7.md). Özyineleme tekniği (recursion), `std::list` kalıbı, bellekle hızlandırma (*memoizasyon*), yeni türler: `konum, aralık` ve `dörtgen`, özgür bellek, özgür dizi konuları.  

Sekizinci ders
--
[Görsel kayıt, notlar, kod örnekleri](ileri/ders8.md). Yine `std::list` kullanarak özyineleme, 2025 sayısının özellikleri ve `std::map` kalıbı, *fayda.h* başlık dosyası ve faydaları, dizi (array), akıllı dizi (`vector`), dizin (`list`) ve eşlem (`map`) kalıpları arasındaki benzerlikler ve farklar. Bir de *DRY* ilkesi.

Dokuzuncu ders
--
[Görsel kayıt, notlar, kod örnekleri](ileri/ders9.md). Eşlem kalıbını pekiştirmek için örnekler, matematiksel tam sayı fonksiyonları, `makefile` ve `make` uygulaması ile otomasyon, karmaşık sayı türüyle *nesne yönelimine* hızlı giriş.

Nesne yönelimi de ne demek?
--
`class`, `struct`, `typedef` ve ileride göreceğimiz `enum` ve `template` anahtar sözcükleri, büyük ve sağlam yazılım yapıları oluşturmakta çok önemli ve faydalı özellikler. *Nesne yönelimli yazılım* ilkelerini hayata geçirmek için temel yapı taşları oluyorlar. [Bu konunun temel kavramlarını sunan kısa bir giriş yazısı yazdık yapay beyinle beraber](ileri/sınıf-yapı-kavramı.md). Bir sonraki derste üzerinden geçeceğiz inşallah. Şöyle bir bakıverin, kodları çalıştırın, çatallayıp biraz kurcalayın ki ders sırasında iyice pekiştirebilelim bu kavramları.

[Onuncu ders](ileri/ders10.md)
--
Görsel kayıt ve notlar başlıktaki linkte ve [burada](ileri/ders10.md). 

[Onbirinci ders ve sonrası](ileri)
--
[Bu dosyanın içinde](ileri).

Koco ve Scala'yla öğrenmeye devam
====
Son yıllarda Hintli ve İsveçli birkaç iş arkadaşımla epey emek verdiğimiz bu gönüllü açık kaynak öğrenim ve programlama ortamını denemeye davet ediyorum hepinizi. Derslerimizden birinde ufak bir sunum da yaparım isterseniz. Daha çok bilgi ve indirmek için [link burada](ileri/kocoya-davet.md).

