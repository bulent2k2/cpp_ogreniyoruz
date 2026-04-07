
Geçen derste yazdığımız algoritma neden doğru?

`a` ile `b` şehirleri arasındaki en kısa yollardan birinin uzunluğunu `k`'nin fonksiyonu olarak `f(a,b,k)` diye yazalım ama bir koşulla: Yoldaki şehirler illa şu kümenin içinde olsunlar: 
```
K = {1, 2, ..., k},
1 <= k <= n
```
O halde, `f(a,b,n)` bize en kısa uzunluğu verecek.  

İki şehir arasındaki hat ya da direk yolun (*edge*) uzunluğunu da `h(a,b)` diye yazalım. Arada hat yoksa, değeri sonsuz olsun. `k=0` yani `K` boş küme olunca `f(a,b,0) = h(a,b)`, `k=1` olduğunda da şu doğru olur:
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

Bu özyineleyen fonksiyon bize dinamik program (DP) yapabileceğimizi gösteriyor. Daha önce gördüğümüz DP örneklerinde olduğu gibi yukarıdan aşağıya (YA) tanımlamak, anlamak ve kanıtlamak daha kolay oldu. **c++** diliyle de aşağıdan yukarı (AY) yazmak hiç zor olmadı. 

kullanarak `k=1` ile başlayıp `k=n` olana kadar devam eden döngüyle herhangi iki şehir arasındaki en kısa yolun uzunluğunu bulabiliyoruz.

> [Esin kaynağı burada](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm), wiki sağolsun.  
> [İlk kanıtın ve yazarının kısa hikayesi de burada](https://en.wikipedia.org/wiki/Stephen_Warshall#). Sanırım 1960 yılında yazılmış ilk defa.  
> [StackEdit](https://stackedit.io/) ile yazdım.  