
Geçen derste yazdığımız algoritma neden doğru?

`f(a,b,k)`, `a` ile `b` arasındaki en kısa yollardan birinin (*path*) uzunluğu olsun, ama bir koşulla: Yoldaki şehirler illa şu kümenin içinde olsun: 
```
K = {1, 2, ..., k}
```
`h(a,b)` iki şehir arasındaki hat ya da direk yolun (*edge*) uzunluğu olsun. Arada hat yoksa, sonsuz olsun.  `k=0` yani `K` boş küme olunca `f(a,b,0) = h(a,b)`, `k=1` olduğunda da şu doğru olur:
```
f(a,b,1) = min(
    h(a,b),
    h(a,1) + h(1,b)
)
```
Her `k` için şu da hep doğru:
```
f(a,b,k) <= f(a,b,k-1)
```
Çünkü, `k` şehri yolda olmazsa, toplam uzunluk da daha az olamaz, değil mi? Ama `k` sayesinde uzunluk azalabilir. O zaman, şu da doğru olmalı: 
```
f(a, b, k) = min( 
    f(a, b, k-1), 
    f(a, k, k-1) + f(k, b, k-1)
)
``` 
Neden? Çünkü, `a` şehrinden `b` şehrine giden yolda `k` şehri ya ara duraklardan biri olacak, ya da olmayacak.

Onun için bu son eşitliği kullanarak `k=1` ile başlayıp `k=n` olana kadar devam eden döngüyle herhangi iki şehir arasındaki en kısa yolun uzunluğunu bulabiliyoruz.

> [Esin kaynağı](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) wiki sağolsun.
> [Kanıtın ve yazarının kısa hikayesi](https://en.wikipedia.org/wiki/Stephen_Warshall#) yaklaşık 1960'larda yapılmış bu kanıt.
> [StackEdit](https://stackedit.io/) ile yazdım.