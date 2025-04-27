Çizgelerde Gezintiler
====

[Geçen dersimizde](ders19.md) iki boyutlu bir diziyle komşuluk matrisi yazmış ve böylece [çizgelerle](../notlar/cizge-kurami.md) kodlamaya giriş yapmıştık. Bu dersimizde de eşlem ve küme kalıbı ile çizge tanımlamayı ve kodlamayı gördük:

```c++
using Düğüm = int;  // Düğüm kimlik no.su
using Küme = std::set<Düğüm>;  // Komşuluk kümesi
using Çizge = std::map<Düğüm, Küme>;

Çizge çizge { // yönlü çizge örneği
    {2, Küme{3, 4, 5}},
    {3, Küme{4, 6}},
    {4, Küme{5, 6, 2}} // ...
}; 
```

İki düğüm arasında yönlü bir bağ eklemek için de bir işlev gördük: 
```c++
void bağla(Çizge & çizge, Düğüm d1, Düğüm d2) {
    çizge[d1].insert(d2);
}
```

Bir dizi bağı kolaylıkla tanımlamak için `std::pair<Düğüm, Düğüm>` dizisi kullandık.

Çizgelerde gezinerek arayış yapmanın çok kullanılan ve faydalı olan iki meşhur türü var. Dersin çoğunu onları anlamaya ve kodlamaya adadık: 
- Enine gezi (*BFS: breadth-first search/traversal*), ve
- Derinine gezi (*DFS: depth-first search/traversal*).

İkisi için tek bir işlev türü tanımlamak yetti:
```c++
// en başa öge eklemek ve en baştaki ögeyi silmek kolay olsun diye vector yerine list kullandık:
using std::list<Düğüm> Gezi; 
// sıra girdisiyle gezinin en başında olmasını istediğimiz düğümleri belirliyoruz.
// atla girdisi de varsa gezmek istemediğimiz düğümleri belirliyor.
Gezi gez(bool enine, const Çizge&, Gezi sıra, Küme atla = Küme{});
```

Özyineleyen bir işlevle bu iki tür arama ve gezi türünün nasıl çalıştığını iyice inceledik, daha iyi anladık. Tek taşla iki kuş vurduk. Ayrıca çizgeleri ve gezileri kolayca ekrana yazmayı da gördük.
 
[Kodun hepsi burada](https://onlinegdb.com/y6uXvw2dE).

[Dersimizin görsel kaydı burada](https://drive.google.com/file/d/15w5yM379blFVbCNRIAL2IcGaW0i3Lc-3). Süresi yaklaşık bir saat.

