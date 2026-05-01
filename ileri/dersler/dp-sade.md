Daha önce Dinamik Programlamaya giriş yaptığımız ilk dersimizin [notları burada](../dp/README.md).  

Bu haftaki dersimizde ([o da burada](d20260424.md)) daha önce görmediğimiz dört tane sade ve temel DP sorusuna baktık:

[Zar dizilerini sayalım (CSES DP1)](https://cses.fi/problemset/task/1633)
---
Bir zarı bir çok kere atarak bir dizi elde ediyoruz. Yani dizimizin sayıları hep 1, 2, 3, 4, 5 ya da 6. Bir de bize bir hedef toplam veriliyor: `n`. Kaç değişik zar dizisi bu toplamı verir acaba? 

Aradığımız bu sayıyı matematiksel bir fonksiyon olarak $f(n)$ diye yazalım. Bunu daha küçük değerlerini kullanarak nasıl yazarız? Önce toplamı sıfır olan tek dizimiz var, boş dizi, onun için: 
```math 
f(0) = 1
```
olsun. Örnek olarak $n=3$ yani toplamı üç olan dizilerin sayısını, toplamı iki, bir ve sıfır olan dizilerin sayılarını kullanarak bulalım:
```math
f(3) = f(0) + f(1) + f(2)
``` 
Neden? Çünkü boş diziden sonra zar 3 gelmeli, `{1}` dizisinden sonra 2 gelmeli ve, `{1,1}` veya `{2}` dizilerinden sonra da 1 gelmeli, değil mi? Bu arada,
```math
f(1) = 1
```
ve
```math
f(2) = 2 
``` 
olduğu için:
```math 
f(3) = 1 + 1 + 2 = 4
```
Bunun genel tümevarım formülü de şöyle olur, değil mi?
```math
f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6)  
```
Elbette, sıfırdan küçük girdiler için fonksiyonumuzun hep sıfır verdiğini varsaymış oluyoruz, eğer bu formülün bütün sayılar için doğru olmasını istiyorsak.

Bunun kodunu nasıl yazarız? O da gelecek derse kaldı. Umarım arada siz de yazarsınız.

[En az sayıda bozuk para kullanarak hedefe varalım (CSES DP2)](https://cses.fi/problemset/task/1634)
---

Bozuk paralarımız 1, 5 ve 7 kuruş olsun. 11 kuruş için en iyi çözüm $5 + 5 + 1$ yani 3 bozuk parayla olur. Aceleci (İngilizcede *greedy* denen) bir çözüm 7 ile başlardı, değil mi? O zaman çözüm $7 + 1 + 1 + 1 + 1$ olur ve 5 bozuk para gerekirdi. Onun için, acele etmeyelim ve bu soruyu da yine daha küçük sorulara bölelim.   

$f(n)$, $n$ toplamı için en iyi çözümdeki bozuk para sayısı olsun. Örneğimiz için şunu yazabiliriz:
```math
f(11) = 1 + min \{f(11-7), f(11-5), f(11-1)\}
```
Yani en iyi çözüm içinde 7 kuruştan bir tane varsa, ki 11 için daha çok olamaz zaten,
o zaman $1 + f(11-7=4)$ tane bozuk para kullanması gerek. Ama 7 kuruş kullanmak zorunda değiliz elbet. Yani en iyi çözümde 7 olup olmadığını bilmiyoruz. 
5 kuruş kullanmayı da denemeliz. Onun için de bozuk para sayısı $1 + f(11-5=6)$ olmalı. 
Elbette bir de 1 kuruş için de aynı şey geçerli. O zaman da $1 + f(11-1=10)$ oluyor. 
Yani en iyi çözüm: 
```math
f(11) = 1 + min \{f(4) + f(6) + f(10)\}
```
Benzer şekilde 
$f(10)$, $f(6)$ ve $f(4)$ değerlerini indirgeyen eşitlikleri de yazabiliriz elbet. Yani genel tümevarım formülümüzü şöyle yazabiliriz (sağol Arhan!):
```math
f(x) = 1 + min \{ f(x - b1),  
            f(x - b2),  
            ...,  
            f(x - bn)\}  
```
Burada `n` tane bozuk para değeri var ve bu değerler: `b1, b2, ... bn`. Başlangıç değerimiz olarak hedef sıfır. O da sıfır tane bozuk para gerektiriyor:
```math
f(0) = 0
```
ve:
```math
f(x) = \infty, \forall x \lt 0
```
yani sıfırdan küçük her $x$ için de fonksiyonun değeri sonsuz olsun diyoruz. Neden? Toplamı eksi olan bir dizi mümkün değil de ondan. Mantıklı değil gibi ama sonsuz kavramı burada formülümüzün bütün hedef ve bozuk para değerleri için çalışmasını sağlıyor. Yoksa, sadece hedeften büyük olmayan bozuk para değerleri için çalışır diye bir koşul belirtmemiz gerekirdi. Örneğimiz için bir kaç değeri aşağıdan yukarı hesaplayalım:
```math
f(1) = 1 + min \{ f(1-1), f(1-5), f(1-7) \} = 1 + f(0) = 1 + 0 = 1
```
```math
f(2) = 1 + min \{ f(2-1), f(2-5), f(2-7) \} = 1 + f(1) = 1 + 1 = 2
```
```math
...
```
```math
f(5) = 1 + min \{ f(5-1), f(5-5), f(5-7) \} = 1 + min \{ f(4), 0 \} = 1 + 0 = 1
```
```math
...
```
$min$ sayesinde sonsuz olan değerlerin bir etkisi olmuyor elbet.

Bozuk paralarla bir hedefe varmanın bütün yollarını sayalım!
---
Önceki soruda olduğu gibi yine bozuk paralarımız var. Ama bu sefer hedef miktara varan bütün dizilerin sayısını bulmak istiyoruz:  
[CSES DP 3](https://cses.fi/problemset/task/1635): $fp(x)$ bize toplamı $x$ olan dizilerin yani bütün permütasyonların sayısını versin.  
Ama ya sıraya önem vermiyorsak? Örneğin `{1, 2, 2}` ve `{2, 1, 2}` ayrı ayrı sayılmasın diyoruz. `std::multiset` kavramını anımsatmış olabilir:  
[CSES DP 4](https://cses.fi/problemset/task/1636): $fk(x)$ bize toplamı $x$ olan kombinasyonların sayısını versin. 

Tümevarım formülleri gelecek derse kaldı. Ama arada kağıt ve kalem alıp düşünmekte çok fayda var! 
