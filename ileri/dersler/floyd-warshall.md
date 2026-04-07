
Geçen derste yazdığımız algoritma neden doğru? Önce problemi tekrar gözden geçirelim: `n` tane şehir ve bazı şehirler arasında ikişer ikişer olmak üzere `m` tane yol var. Yolların uzunluğunu da biliyoruz. `a` ve `b` şehirleri arasındaki yolun uzunluğunu $h(a,b)$ diye yazalım. Bunu seyahat süresi olarak da düşünebiliriz. Her şehir için $h(a,a) = 0$ ve aralarında yol olmayan şehirler için $h(a,b) = \infty$ olsun. Herhangi iki şehir arasında seyahat etmek isteyebiliriz. Mümkün olan en kısa seyahat süresini bulmak istiyoruz.

`a` şehrinden `b` şehrine seyahat süresini bir `k` sayısının fonksiyonu olarak $f(a,b,k)$ diye yazalım ama bir koşulla: Seyahatte ziyaret edilen şehirler illa şu kümenin içinde olsunlar:
```math
K = \{1, 2, ..., k\}
```
```math
1 \le k \le n
```
Yani, bu küme içinde olmayan şehirlerden geçmek yok. `a` ve `b` için bu koşul geçerli değil elbet. 

Öte yandan, $k=n$ olunca $f(a,b,n)$ bize `a`'dan `b`'ye seyahat için mümkün olan en kısa süreyi verecek.  

Başlangıçta $k=0$ yani $K=\emptyset$ olunca tek seçenek var: 
```math
f(a,b,0) = h(a,b)
```
$k=1$ olunca sadece iki seçenek var. Aralarından küçük olanı seçiyoruz:  
```math
f(a,b,1) = min( h(a,b), h(a,1)+h(1,b) )
```    
Her `k` için şu da hep doğru: 
```math
f(a,b,k) \le f(a,b,k-1)
```
Çünkü, `k`'inci şehre uğramayan bir seyahat daha kısa olamaz, değil mi? Ama `k`'den geçen bir seyahat bir ihtimal daha kısa olabilir. O zaman, şu da doğru olmalı: 
```math
f(a,b,k) = min( f(a,b,k-1), f(a,k,k-1)+f(k,b,k-1) )
```  
Neden? Çünkü, `a` şehrinden `b` şehrine seyahat ediyorsak, sadece iki olasılık var: ya `k` şehrini ziyaret edeceğiz ya da etmeyeceğiz.

Bu özyineleyen fonksiyon bize dinamik program (DP) yazabileceğimizi apaçık gösteriyor: problemi daha küçük problemlere bölmeyi becerdik. Küçük problemleri bir kere çözüp birleştirerek büyük problem için de doğru hızı bulabiliriz. Daha önce gördüğümüz [DP örneklerinde (3.ders)](d20251010-1128.md) olduğu gibi *yukarıdan aşağıya* (YA) yani özyineleyerek tanımlamak, anlamak ve kanıtlamak daha kolay oldu. **C++** diliyle de *aşağıdan yukarı* (AY) yazmak hiç zor olmadı. `k=0` için ilk değerleri belirledik. Sonra $k=1$ ile başlayıp $k=n$ olana kadar devam eden döngüyle bütün şehirler arasındaki en kısa seyahat süresini bulduk.

> [Esin kaynağı burada](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm), wiki sağolsun.  
> [İlk kanıtın ve yazarının kısa hikayesi de burada](https://en.wikipedia.org/wiki/Stephen_Warshall#). Sanırım 1960 yılında yazılmış ilk defa.  
> [StackEdit](https://stackedit.io/) ile yazdım.  
