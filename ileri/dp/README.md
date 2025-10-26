Dinamik Programlama (Dynamic Programming, DP)
=======

Bir problemi küçük parçalarına bölerek çözme yöntemine DP deniyor. Küçük parçalar daha da küçük parçalara bölünüyor. Bu yinelenen bölme ve parçalama işlemi çözümünü bildiğimiz küçüklüğe varana kadar devam ediyor. 

En basit örnek, Fibonaççi fonksiyonu:  

```
Fib(n) = Fib(n-1) + Fib(n-2)  
Fib(0) = 0  
Fib(1) = 1
```

Genel olarak iki tür dinamik program var:

1- Yukardan Aşağıya (YA) (Top-down). Özyineleyen işlevlerle (recursive functions) yazılabilir. Büyük problemler için hız sorunu yaşanır. Onun için genelde **memoizasyon** tekniğiyle, yani küçük problemlerin çözümünü belleğe yazarak hızlandırılır.  

2- Aşağıdan Yukarıya (AY) (Bottom-up). En küçük parçaları çözer ve onları bir araya koyarak büyüklerini çözeriz.

Fibonaççi fonksiyonunu iki şekilde de yazabiliriz. [Bir örneği burada](https://onlinegdb.com/bQ9X2XKZd). Bundaki özyineleme (YA) yöntemini hızlandırmak faydalı bir alıştırma olur. 

Bir kademe daha zor bir problem daha görelim. İki yazının (harf dizilerinin) en büyük kesişimini (yani alt dizilerinin en uzununu) nasıl bulabiliriz? [AY DP ile bulmak için bir örnek burada](ortak_altdiziler/altdizi.cpp). Bu problemi YA DP tekniğiyle de çözebilir miyiz? O da bir alıştırma olsun. Ayrıca daha genel diziler için `vector<T>` kalıbı kullanarak çözmek de başka bir alıştırma olsun. Ondan önce aşağıdaki **Longest Common Subsequence** bağlantısına da bakın. 

Başka güzel bir DP problemi de ızgara üzerindeki yolları saymak. En sade hali [Project Euler'in 15. Problemi](https://projecteuler.net/problem=15). Onun YA DP çözümünü özyineleyerek yazmak faydalı bir alıştırma olur. Aranızda yapmayan kalmasın. [Örnek bir çözüm başlangıcı burada](https://onlinegdb.com/PusqCGJ6c). Bellek ekleyerek hızlandırın. Sonra `int` yerine `long` kullanın. Onu çözünce, daha da genel haline bakalım: engelli sahada yolları sayma problemi [AtCoder.jp sitesinde](https://atcoder.jp/contests/dp/tasks/dp_h).

Arkadaşlarınız zıplayan kurbağa problemini de öneriyorlar. O da yine [AtCoder sitesinde burada](https://atcoder.jp/contests/dp/tasks/dp_a).  

Daha pek çok örnek var internette. Örneğin: 

1- [CSES.fi sitesinden](https://cses.fi/problemset/) Dynamic Programming kısmına bakın. Örneğin [**Longest Common Subsequence** yukarıda görüğümüz iki yazı kesişimi problemine denk ](https://cses.fi/problemset/task/3403).  
2- [SPOJ - Sphere Online Judge sitesinden DP problemleri](https://www.spoj.com/problems/tag/dynamic-programming). En popüler problem [**ALPHACODE** burada](https://www.spoj.com/problems/ACODE/) ve faydalı bir alıştırma olur.  

