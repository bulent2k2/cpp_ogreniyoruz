Dinamik Programlama (Dynamic Programming, DP)
=======

Bir problemi küçük parçalarına bölerek çözme yöntemine DP deniyor. Küçük parçalar daha da küçük parçalara bölünüyor. Bu yinelenen bölme ve parçalama işlemi çözümünü bildiğimiz küçüklüğe varana kadar devam ediyor. 

En basit örnek, Fibonaççi fonksiyonu:  

```
Fib(n) = Fib(n-1) + Fib(n-2) 
n ≥ 0 
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

1. [CSES.fi sitesinden](https://cses.fi/problemset/) Dynamic Programming kısmına bakın. Örneğin [**Longest Common Subsequence** yukarıda görüğümüz iki yazı kesişimi problemine denk ](https://cses.fi/problemset/task/3403).  
2. [SPOJ - Sphere Online Judge sitesinden DP problemleri](https://www.spoj.com/problems/tag/dynamic-programming). En popüler problem [**ALPHACODE** burada](https://www.spoj.com/problems/ACODE/) ve faydalı bir alıştırma olur.  

Önerilen okuma: [Algoritma kitabından DP bölümü](https://people.eecs.berkeley.edu/~vazirani/algorithms/chap6.pdf). Bu kitap üniversitelerde bilgisayar mühendisliğinde okunan güzel ve ileri derece kitaplardan. Herşeyi anlamasak bile şöyle bir karıştırmak faydalı olabilit. Takıldığınız birşey olursa WhatsApp'tan bana direk yazabilirsiniz. Çekinmeyin.

Derste baktığımız sorular
----

[Project Euler'den 15. problem](https://projecteuler.net/problem=15) ızgara üzerindeki patikaları saydık. [Çözüm burada](https://www.onlinegdb.com/rLWkHMxGu5). Bu çözümde DP YA, yani yukarıdan aşağı arama yöntemini kullandık. Bellek ekledik ki 20x20'lik ızgarayı da çözebilsin. Derste bir arkadaşınız güzel bir soru sordu. Daha küçük bir bellek kullansak olur mu? Emin değilim. Bir de aşağıdan yukarı yöntemiyle çözebilir miyiz dersiniz?  

[AtCoder.jp sitesinden engelli sahada yolları sayma problemi](https://atcoder.jp/contests/dp/tasks/dp_h). [Çözüm burada](https://www.onlinegdb.com/BJ7qjYXnN). Bir önceki problemin daha genel hali, çünkü engeller ve veri girdisi var. Ama yine bellek ekleyerek DP YA yöntemiyle güzel bir çözüm oldu. Sahanın kutularını sol üst köşeye `(1, 1)` konumunu vererek çözdük. Sağ alt köşe `(H, W)` konumunda oldu, yani satır ve sütun sayıları. Genel haliyle problemimiz `(r, c)` kutusundan `(H, W)` kutusuna giden yolların sayısını bulmak. Alt problemleri de `(r+1, c)` yani aşağıya giden patikalar ve `(r, c+1)` yani sağa giden patikaların sayısı olarak ifade ettik. Konumlamayı başka türlü yapmanın da mümkün olduğunu gördük. Örneğin `(1, 1)` sağ alt kutu olsun ve sola ve yukarı doğru satır ve sütun sayıları artsın da diyebilirdik. Öyle yapınca kodumuz daha da doğal oldu: Alt problemleri bu sefer de `(r-1, c)` ve `(r, c-1)` olarak oluşturduk. Görünen o ki önemli olan alt problemleri nasıl ifade ettiğimiz değil, alt problemlerin ana problemden daha küçük olması. [İkinci çözüm de burada](https://www.onlinegdb.com/19X5NIcu7).  

İki dizinin ortak altdizilerinden en uzununu bulma problemine de giriş yaptık. [Yarım çözüm burada](https://www.onlinegdb.com/UEyDuzjdfB). Bu problemi seçme nedenim çizelge kullanan DP AY, yani aşağıdan yukarıya arama yöntemine güzel bir örnek olması. Önce birim denemeler (unit testing) ile başlamakta fayda var:  
```c++
using yazı=std::string;
void dene(yazı y1, yazı y2, yazı ortak) {
    assert(bul2(y1, y2) == ortak);
}
dene("abca", "daxbcby", "bc");
dene("abc", "xyz", "");
dene("xyabc", "xydabca", "abc");
dene("abcdxyad", "xyabcdxyb", "abcdxy");
dene("1234", "567", "");
dene("123", "345", "3");
// https://www.spoj.com/problems/SBSTR1/
dene("1010110010","10110", "10110");
dene("1110111011","10011", "011");
```
Bunu çözmek için de ana problemi iki boyutlu bir çizelge kullanarak ifade edilebiliriz: `tane[k1][k2]` yani `y1` yazısının `k1` konumunda biten ve `y2` yazısının `k2` konumunda biten ortak altdizinin içinde kaç tane harf olduğunu kaydedelim. `(k1, k2)` konumlarındaki harfler farklı olduğunda sıfır olacak. Yani çoğu sıfır olabilir. Onun ilk değeri için de iki boyutlu akıllı dizi kullandık:
```std::vector<std::vector<int>> tane(y1.size()+1, std::vector<int>(y2.size()+1, 0));```

Gerisi epey kolay:
```c++
// uzunluğu bulduktan sonra ortak altdiziyi bulmak da kolay
yazı bul2(const yazı& y1, const yazı& y2);  // bu genel çözüm olsun
int bul(yazı y1, yazı y2) {
    yazı o = bul2(y1, y2);
    return o.size();
}
yazı bul2(const yazı& y1, const yazı& y2){
    const int boy1 = y1.size(), boy2 = y2.size();
    int max=0, k=0; // şu ana kadar bulduğumuz en uzun ortak altdizinin uzunluğu ve y1'de bittiği konum
    std::vector<std::vector<int>>  // iki boyutlu sayı dizisi  == tane[boy1+1][boy2+1]
		tane ( boy1 + 1, std::vector<int> ( boy2 + 1, 0) );
    for(int k1=0; k1 < boy1; ++k1) {
        for(int k2=0; k2 < boy2; ++k2) {
            if (y1[k1] == y2[k2]) {
                int m = tane[k1+1][k2+1] = tane[k1][k2] + 1;
                // ...
            }
        }
    }
    if (max > 0) return y1.substr(k+1-max, max);
    else return std::string{""};
}
```
`bul2()` işlevini tamamlamayı size bırakıyorum. Bir deneyin isterseniz. Gerekirse gelecek derste birlikte tamamlarız.
