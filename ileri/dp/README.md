Dynamic Programming (DP)
=======

Bir problemi küçük problemlere bölerek çözme yöntemine verilen genel ad.  

En basit örnek, Fibonaççi fonksiyonu:  

```
Fib(n) = Fib(n-1) + Fib(n-2)  
Fib(0) = 0  
Fib(1) = 1
```

Genel olarak iki tür dinamik program var:

1- Yukardan aşağıya (Top-down). Özyineleyen işlevlere yazılabilir. Büyük problemler için hız sorunu yaşanır. Onun için genelde **memoizasyon** tekniğiyle, yani küçük problemlerin çözümünü belleğe yazarak hızlandırılır.  

2- Aşağıdan yukarıya (Bottom-up). En küçük parçaları çözer sonra yavaş yavaş büyüklerini çözeriz.

Fibonaççi fonksiyonunu iki şekilde de yazabiliriz. [Bir örneği burada](https://onlinegdb.com/bQ9X2XKZd). 

Bundaki özyineleme (yukarıdan aşağıya) yöntemini hızlandırmak faydalı bir alıştırma olur. 

Bir kademe daha zor bir problem daha görelim. İki yazının (harf dizilerinin) en büyük kesişimini (yani alt dizilerinin en uzununu) nasıl bulabiliriz? [Aşağıdan yukarı DP ile bulmak için bir örnek burada](ortak_altdiziler/altdizi.cpp). Bu problemi yukarıdan aşağıya tekniğiyle de çözebilir miyiz?

