
[Omuzda taşıma (*piggyback*)](https://usaco.org/index.php?page=viewproblem2&cpid=491)
====

*Aralık 2014, 1. Gümüş Problem*  
*Yazarı Brian Dean*  

Benekli ve kız kardeşi Pamuk gün boyunca değişik otlaklarda otlarlar ve akşamları ikisi de dinlenmek için ahıra geri yürümek ister. Zeki sığırlar oldukları için, yürürken harcadıkları toplam enerjiyi en aza indirecek bir plan geliştirirler. 

Benekli bir otlaktan bitişik bir otlağa yürürken `B` birim enerji harcar. Pamuk ise `P` birim enerji harcar. Ancak, Benekli ve Pamuk aynı otlaktalarsa, Benekli Pamuğu omuzunda taşıyabilir ve ikisi de sadece `T` birim enerji harcayarak komşu otlağa gidebilirler. Genelde `T`, Benekli ve Pamuğun komşu otlağa ayrı ayrı yürürken harcayacakları `B+E` miktarından önemli ölçüde daha az olabilir. Eğer `T` çok küçükse, en verimli, yani en az enerji harcayan çözüm, Benekli ve Pamuğun ortak bir buluşma alanına gitmeleri ve ardından ahıra kadar olan yolculuğun geri kalanında birlikte seyahat etmeleri olabilir. Elbette, `T` büyükse, Benekli ve Pamuğun ayrı ayrı seyahat etmesi yine de en mantıklısı olabilir.

`B`, `P` ve `T` değerlerinin yanı sıra çiftliğin düzenini de göz önünde bulundurarak, Benekli ve Pamuğun ahıra ulaşması için gereken en az enerji miktarını hesaplayın.

GİRDİ (piggyback.in adlı dosyadan okunacak)
---- 
Girdinin ilk satırı pozitif tamsayılar `B`, `P`, `T`, `N` ve `M`'yi içerir. Bunların her birisi en fazla `40`bindir. `B`, `P` ve `T` yukarıda açıklanmıştır. `N` çiftlikteki otlakların sayısıdır (`1..N` ve `N >= 3`). `M` de otlaklar arasındaki bağlantı sayısıdır. 

Benekli ve Pamuk sırasıyla `1` ve `2` numaralı otlaklarda başlarlar. Ahır, `N` numaralı otlakta yer almaktadır. 

Arkadan gelen `M` satırın her biri, iki otlağın tam sayı indeksleriyle belirtilen iki farklı otlak arasındaki bağlantıyı tanımlar. Bağlantılar çift yönlüdür. Bu bağlantılarla 1. otlaktan `N`. otlağa ve 2. otlaktan `N`. otlağa seyahat etmek her zaman mümkündür.

ÖRNEK GİRDİ
----
```
4 4 5 8 8
1 4 
2 3 
3 4 
4 7 
2 5 
5 6 
6 8 
7 8
``` 
ÇIKTI (piggyback.out adlı dosya oluştur ve ona yaz)
----

Benekli ve Pamuğun ahıra ulaşmak için birlikte harcamaları gereken minimum enerji miktarını belirten tek bir tam sayı.
Burada gösterilen örnekte, Benekli 1'den 4'e, Pamuk ise 2'den 3'e ve 4'e seyahat eder. Daha sonra birlikte 4'ten 7'ye ve 8'e seyahat ederler. 

ÖRNEK ÇIKTI
----
`22`

Çözümünü [derste](../../../dersler/d20260313.md) yaptık. 

