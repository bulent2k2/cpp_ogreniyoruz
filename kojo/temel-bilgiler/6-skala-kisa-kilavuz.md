Skala kısa kılavuzu
===================

> Kogics Foundation'ın Kojo belgelerindeki
> [Scala Quick Reference](https://docs.kogics.net/reference/scala-quick-reference.html)
> sayfasının çevirisi. Özgün metin: © 2010-2025 Kogics Foundation,
> CC BY-NC-SA. Çeviri de aynı lisansta; deponun CC BY-SA 4.0 lisansı bu
> dosyayı kapsamaz (bkz. [`LICENSE`](../../LICENSE), 3. bölüm).
> Kod örnekleri Koco'nun Türkçe adlarıyla yazıldı.


Aşağıdaki kısa kılavuzu en iyi anlamanız için şu fikirlere aşina olmanız
iyi olur:

+ [Bilişimin temelleri](3-bilisim-temelleri.md#bilişimin-temelleri)
+ [Yazılımın yapısı](3-bilisim-temelleri.md)
+ [Yazılımın çalışması](4-kavramsal-makine.md)
+ Yazılım geliştirme

Devam etmeden önce yukarıdaki bağlantılardaki fikirleri gözden geçirin.

Bu sayfayı tamamlaması (ve Scala'ya iyi bir giriş olması) için Cay
Horstmann'ın *Scala for the Impatient* kitabının ücretsiz sürümüne de bir
göz atın. Türkçe isteyenler için iKojo'nun içinde
[19 bölümlük bir Skala kılavuzu](https://ikojo.fly.dev/yardim/skala) var.

*Çevirmen notu:* özgün sayfa İngilizce Scala/Kojo adlarıyla yazılmış.
Burada bütün örnekler Koco'nun Türkçe adlarına çevrildi. Anahtar
sözcüklerin (`dez`/`val`, `den`/`var`, `tanım`/`def` ...) tam listesi
iKojo'nun [anahtar sözcükler bölümünde](https://ikojo.fly.dev/yardim/skala).

Örneklerdeki `//>` yorumları, kodun çalışma sayfası kipindeki çıktısını
gösteriyor; tür adlarını burada Türkçe yazdık (masaüstü Koco da böyle
gösteriyor). Tarayıcıdaki iKojo şimdilik İngilizce tür adları basıyor,
yani orada `Sayı` yerine `Int` görürsünüz.


1. Veri türleri
--

Bir yazılım verisi olmadan hiçbir şeydir. Elinde birkaç veri değeriyle
başlar ve çalışırken eski değerlerden yeni değerler hesaplar (başka
sayfalarda anlatıldığı gibi). Yani veriyi öğrenmek önemli.

Scala'daki farklı veri türlerine bakmadan önce biraz arka plan:

+ Tek bir veri parçasına **değer** denir.
+ Scala'da her değer bir **nesnedir**.
+ Bir nesne, veriyi işlevlerle/komutlarla birleştirir. Bir nesneye bağlı
  işlevlere/komutlara onun **yöntemleri** denir.
+ Her nesnenin bir **türü** vardır.
+ Bir tür, olabilecek değerler kümesini ve bu değerlerle yapılabilecek
  işlemleri belirler.
+ Türler **sınıflar** aracılığıyla betimlenir. Bir nesne, kendi
  türünün/sınıfının bir **örneğidir**.

Unutmayın — Scala bağlamında *veri*, *değer*, *nesne* ve *örnek* terimleri
birbirinin yerine kullanılabilir.

Scala'nın desteklediği veri türlerinden bazıları şunlar.

### 1.1 Sayı (*Int*)

+ `Sayı`lar tam veriyi temsil eder; ör. 1, 3, 5, -4, -9.
+ Alışılmış matematik işleçleri/işlevleri (`+`, `-`, `*`, `/`, `>`, `>=`,
  `<`, `<=`, `==`, `!=`) `Sayı`lar için desteklenir.
+ Dikkat: yukarıdaki işlevlerin bir kısmı `Sayı` döndürür, bir kısmı
  `İkil`.

`Sayı` kullanımına birkaç örnek:

```scala
2 + 3 //> res23: Sayı = 5
3 + (2 * 5) - (10 * 2) //> res24: Sayı = -7
2 > 10 //> res25: İkil = yanlış
```

Yukarıdaki kod, Kojo'da `Shift+Enter` ile *çalışma sayfası* (*worksheet*)
kipinde çalıştırıldıktan sonraki hâliyle tam sayı işlemlerini gösteriyor.
Koddaki her deyişin ardından `//>` ve sonra `ad: tür = değer` geliyor;
buradaki `ad`, deyişin değerine Kojo'nun taktığı addır.

### 1.2 Kesir (*Double*)

+ `Kesir`ler kesirli veriyi temsil eder; ör. 1.5, 3.2, 5.3, -4.1, -9.8.
+ Alışılmış matematik işleçleri/işlevleri (`+`, `-`, `*`, `/`, `>`, `>=`,
  `<`, `<=`, `==`, `!=`) `Kesir`ler için desteklenir.
+ Dikkat: yukarıdaki işlevlerin bir kısmı `Kesir` döndürür, bir kısmı
  `İkil`.

`Kesir` kullanımına birkaç örnek:

```scala
2.1 + 3.2 //> res40: Kesir = 5.300000000000001
3.1 + (2.2 * 5.05) - (10 * 2) //> res41: Kesir = -5.789999999999999
2.1 > 10 //> res42: İkil = yanlış
```

### 1.3 İkil (*Boolean*)

+ `İkil`ler bir yazılımdaki doğru ya da yanlış değerleri temsil eder.
+ Alışılmış işleçler/işlevler (`&&`, `||`, `==`, `!=`, `!`, `^`) `İkil`ler
  için desteklenir.

`İkil` kullanımına birkaç örnek:

```scala
2 > 10 //> res34: İkil = yanlış
(10 > 2) && (3 > 11) //> res35: İkil = yanlış
(10 > 2) && (3 > 11) || (4 < 5) //> res36: İkil = doğru
// ! değilleme (olumsuzlama) içindir
!doğru //> res37: İkil = yanlış
// ^ dışlayıcı-veya (xor) içindir
doğru ^ yanlış //> res38: İkil = doğru
doğru ^ doğru //> res39: İkil = yanlış
```

`İkil`ler önemlidir, çünkü **koşullarda** kullanılırlar.

### 1.4 Yazı (*String*)

`Yazı`lar, bir yazılıma metin bilgisi taşımak ve ondan metin bilgisi almak
için kullanılır. Örnekler: `"Merhaba Dünya"` ve `s"Puanınız $puan"`.

Bazı yararlı `Yazı` yöntemleri: `+`, `kısalt`, `büyükHarfe`,
`küçükHarfe`, `parçası` vb. Bir `Yazı` örneği/değeri üstünde kod
tamamlama yaparak `Yazı`lar için elinizin altındaki daha birçok yöntemi
keşfedebilirsiniz.

Bir yazılıma veri sokup çıkarmak için `Yazı` kullanımına bir örnek:

```scala
dez n = sayıOku("Bir sayı girin")
dez n2 = 2 * n
satıryaz(s"Girdiğiniz sayının iki katı $n2")
```

### 1.5 Renk (*Color*)

`Renk`ler; çizimlerdeki, oyunlardaki vb. görsel renkleri temsil etmek için
kullanılır; ör. `mavi`, `yeşil`, `kırmızı`.

`Renk` kullanımına bir örnek:

```scala
sil()
kalemRenginiKur(Renkler.kahverengi)
boyamaRenginiKur(Renkler.sarı)
yinele(4) {
    ileri(100)
    sağ(90)
}
```

Renkler üstüne daha çoğu [ayrı bir sayfada](5-renkler.md).

### 1.6 Resim (*Picture*)

`Resim`ler Kojo'nun tanımladığı bir veri türüdür. `Resim`ler; ötelenebilen,
büyütülebilen, döndürülebilen, uzamda dizilebilen görsel ögelerdir.

Çizim yaparken alışıldığı gibi, bir `Resim`in **dönüşümlerle** işlenmesine
bir örnek:

```scala
tanım r = Resim {
    yinele(4) {
        ileri(30)
        sağ(90)
    }
}

temizle()
eksenleriGöster()
dez resim1 = r
dez resim2 = öteleme(100, 0) * döndürme(45) * büyütme(2) -> r
çiz(resim1, resim2)
```

Bir oyunda alışıldığı gibi, bir `Resim`in **yöntemlerle** işlenmesine bir
örnek:

```scala
dez resim = Resim {
    yinele(4) {
        ileri(30)
        sağ(90)
    }
}

temizle()
eksenleriGöster()
çiz(resim)
canlandır {
    resim.taşı(1, 0)
    resim.döndür(1)
    resim.büyüt(1.001)
}
```

*Çevirmen notu:* özgün örnek burada `pic.translate(1, 0)` diyor.
Türkçesinde `taşı` seçtik: o dünya koordinatlarında kaydırıyor (resim
döndürülmüş olsa bile ekranda sağa gidiyor), hareket eden nesneler için
istenen davranış bu. Resmin kendi çerçevesinde kaydırma isterseniz
`taşınmış(...)` var.

### 1.7 Birim (*Unit*)

`Birim` türü çok ilginçtir. Yalnızca tek bir olası değeri vardır — birim
değeri `()`.

Bunu `İkil` ile karşılaştırın: onun iki olası değeri var, `doğru` ve
`yanlış`. Ya da `Sayı` ile: onun pek pek çok olası (artı ve eksi) değeri
var.

Elinizde bir `Sayı` değeri varsa, o birçok farklı bilgi taşıyabilir (yaş,
maaş, uzaklık, boy vb. vb.).

Elinizde bir `İkil` değeri varsa, o `doğru` ya da `yanlış` bilgisini
taşıyabilir.

Elinizde bir `Birim` değeri varsa, o **hiçbir** bilgi taşımaz (çünkü tek
bir olası değeri var — `()`).

`Birim`, **komutların** dönüş türüdür. Anımsayın: komutlar eylem yürütür
ama bilgi döndürmez. Bunu iş başında görelim:

```scala
dez a = ileri(100) //> dez a: Birim = ()
dez b = sağ(90) //> dez b: Birim = ()
```

Gördüğünüz gibi, `ileri` de `sağ` da `Birim` değerini — yani hiçbir bilgi
taşımayan `()`'ı — döndürüyor. Bu yüzden yukarıdaki kodu şöyle yazmak daha
iyi:

```scala
ileri(100)
sağ(90)
```

### 1.8 Kaplar (*Collections*)

Bir **kap**, yazılımınızdaki veriyi belli bir biçimde düzenlemenizi sağlar
(hangi biçimde olduğu kabın türüne bağlı). Yararlı kaplardan bazıları:

#### 1.8.1 Dizi (*Seq*)

Bir **dizi**, ögelerinin sırası iyi tanımlanmış olarak birbiri ardına
dizilmiş veri değerlerinden oluşan bir kaptır; ör. `Dizi(1, 5, 3)`.

Bir dizideki her öge, dizi içindeki konumuna ya da **dizinine** (*index*)
göre bulunabilir. Konumlar (ya da dizinler) 0'dan başlar ve
*dizi boyu - 1*'e kadar gider.

Yazılımınızdaki bir miktar veriyi bir dizi hâlinde düzenlemek istiyorsanız
ve dizi sabitse, diziyi kurmak için `Dizi` işlevini kullanabilirsiniz.

```scala
dez sayılar = Dizi(5, 9, 2, 3)
dez adlar = Dizi("ad1", "ad2", "ad3")
// resim1, resim2, resim3'ün yazılımınızda daha önce tanımlandığını varsayalım
dez resimler = Dizi(resim1, resim2, resim3)
```

Veriniz bir kez dizi hâline geldi mi, diziyle birçok şey yapabilirsiniz.
Bir dizi üstündeki en önemli üç işlem şunlar:

+ Dizinin her ögesiyle bir komut/deyim yürütmek (`herbiriİçin` ile).
+ Her ögeyi yeni bir ögeye eşleyen bir işlev kullanarak diziyi başka bir
  diziye çevirmek (`işle` ile).
+ Diziden, belli bir ölçüte uyan ögelerden oluşan bir alt dizi almak
  (`ele` ile).

Bu işlemleri iş başında gösteren kod:

```scala
çıktıyıSil()
dez sayılar = Dizi(5, 9, 2, 3)

// dizideki her öge için bir şey yap
sayılar.herbiriİçin { n =>
    satıryaz(n)
}

satıryaz("---")

// bir diziyi başka bir diziye çevirmek için işle
dez sayılar2 = sayılar.işle { n =>
    n * 2
}

// sonra yeni dizinin her ögesi için bir şey yap
sayılar2.herbiriİçin { n =>
    satıryaz(n)
}

satıryaz("---")

// alt dizi almak için bir diziyi ele
dez sayılar3 = sayılar.ele { n =>
    n > 4
}

// sonra yeni dizinin her ögesi için bir şey yap
sayılar3.herbiriİçin { n =>
    satıryaz(n)
}
```

Şu kodun (yukarıdan kopyalandı) ne yaptığını anlamaya çalışalım. Kod
`işle` işlevini kullanıyor:

```scala
dez sayılar2 = sayılar.işle { n =>
    n * 2
}
```

Bu kod şöyle de yazılabilir:

```scala
tanım iş1(n: Sayı): Sayı = {
    n * 2
}

dez sayılar2 = sayılar.işle(iş1)
```

Kodun ilk sürümü, `işle` çağrısının içinde yerinde tanımlanmış **adsız bir
işlev** kullanıyor; ikinci sürümü ise daha önce tanımlanıp sonra `işle`
çağrısında kullanılan **adlı bir işlev**.

Aynı alıştırmayı `ele` için de yapalım.

İşte yukarıdaki, yerinde tanımlı adsız işlevli sürüm:

```scala
dez sayılar3 = sayılar.ele { n =>
    n > 4
}
```

Ve işte adlı işlevli sürüm:

```scala
tanım iş2(n: Sayı): İkil = {
    n > 4
}

dez sayılar3 = sayılar.ele(iş2)
```

Gördüğünüz gibi `işle` ve `ele`, ikisi de girdi olarak bir işlev alıyor, o
işlevi dizinin her ögesine uyguluyor ve işlev çağrılarının sonuçlarına
dayanarak yeni bir dizi kuruyor.

Scala'nın birçok `Dizi` türü vardır — `Dizik` (*Array*), `EsnekDizik`
(*ArrayBuffer*), *ArrayDeque*, *Vector*, `Dizin` (*List*), `Aralık`
(*Range*) ve daha fazlası. Her birinin farklı güçlü yanları var; Scala,
belli bir duruma en uygun dizi türünü seçme olanağını size veriyor.

Sık kullanacağımız birkaç dizi türüne daha ayrıntılı bakalım.

##### 1.8.1.1 Dizik (*Array*)

Bir `Dizik`, var olan bir diziyi ögelerini değiştirerek değiştirebilmek
istediğinizde işe yarar. Sayılarla yüksek başarımlı kod yazmak
istediğinizde de işe yarar (çünkü Scala'da bir `Dizik`, Scala dizisi gibi
görülebilen, platformun kendi dizisidir).

Bir `Dizik` dizi gibi çalışır, yani bir diziyle yapabildiğiniz her şeyi
(önceki bölümdekiler dahil) bir `Dizik`le de yapabilirsiniz.

`Dizik`ler için örnek kod:

```scala
// önceden doldurulmuş bir dizik
dez d1 = Dizik(1, 2, 3) //> d1: Dizik[Sayı] = Dizik(1, 2, 3)

// dizik ögesine erişim
d1(1) //> res59: Sayı = 2

// sonra doldurulabilecek boş bir dizik
dez d2 = Dizik.boş[Sayı](3) //> d2: Dizik[Sayı] = Dizik(0, 0, 0)

// dizik ögesini güncelleme
d2(0) = 1
d2(1) = 2
d2(2) = 3

d1 //> res63: Dizik[Sayı] = Dizik(1, 2, 3)
d2 //> res64: Dizik[Sayı] = Dizik(1, 2, 3)

// boş bir iki boyutlu dizik (diziklerin diziği)
dez d3 = Dizik.boş[Sayı](2, 3) //> d3: Dizik[Dizik[Sayı]] = Dizik(Dizik(0, 0, 0), Dizik(0, 0, 0))

// dizik ögesini güncelleme
d3(0)(0) = 1
d3(1)(1) = 2
d3(1)(2) = 3
d3 //> res68: Dizik[Dizik[Sayı]] = Dizik(Dizik(1, 0, 0), Dizik(0, 2, 3))

// dizik ögesine erişim
d3(1)(1) //> res69: Sayı = 2
d3(1) //> res70: Dizik[Sayı] = Dizik(0, 2, 3)
```

*Çevirmen notu:* özgün kod boş dizik için `Array.ofDim[Int](3)` diyor;
Türkçesi `Dizik.boş[Sayı](3)`.

##### 1.8.1.2 EsnekDizik (*ArrayBuffer*)

Bir `EsnekDizik`, var olan bir diziyi ögelerini değiştirerek, ona yeni
ögeler ekleyerek ya da ondan öge çıkararak değiştirebilmek istediğinizde
işe yarar (gerçi çıkarma *ArrayDeque* ile çok daha verimli).

Bir `EsnekDizik` de bir dizidir, yani `Dizik`lerde olduğu gibi, bir
diziyle yapabildiğiniz her şeyi bir `EsnekDizik`le de yapabilirsiniz
(özellikle `herbiriİçin`, `işle` ve `ele`).

`EsnekDizik`ler için örnek kod:

```scala
// önceden doldurulmuş bir esnek dizik
dez ed = EsnekDizik(5, 3, 9) //> ed: EsnekDizik[Sayı] = EsnekDizik(5, 3, 9)

// öge güncelleme
ed(1) = 12
ed //> res51: EsnekDizik[Sayı] = EsnekDizik(5, 12, 9)

// öge ekleme
ed += 21
ed //> res53: EsnekDizik[Sayı] = EsnekDizik(5, 12, 9, 21)

// boş bir esnek dizik
dez ed2 = EsnekDizik.boş[Sayı] //> ed2: EsnekDizik[Sayı] = EsnekDizik()

// öge ekleme
ed2 += 11
ed2 += 2
ed2 //> res56: EsnekDizik[Sayı] = EsnekDizik(11, 2)
```

*Çevirmen notu:* özgün kod öge eklemek için `ab.append(21)` diyor.
Masaüstü Koco'da `ed.ekle(21)` de yazılabiliyor; iKojo'da şimdilik `+=`
işleci var, biz de onu kullandık.

##### 1.8.1.3 Aralık (*Range*)

Bir **aralık**, aralarındaki boşluk eşit olan, sıralı bir tam sayı
dizisidir. Örnekler:

```scala
1 |-| 5           // ya da Aralık.kapalı(1, 5)
Aralık.kapalı(0, 10, 2)
2 |- 6            // ya da Aralık(2, 6)
Aralık(1, 11, 3)
```

Gördüğünüz gibi tam sayı aralıklarına iki ayrı yoldan ulaşılıyor:

+ araya yazılan `|-|` / `|-` işleçleriyle — ör. `1 |-| 5`, `2 |- 6`
+ `Aralık.kapalı(...)` / `Aralık(...)` işlevleriyle — ör.
  `Aralık.kapalı(1, 5)`, `Aralık(2, 6)`

`|-|` son sayıyı **içine alır** (İngilizcesi `to`), `|-` ise **almaz**
(İngilizcesi `until`). İşleçlerin üstünlüğü daha kısa ve kolay
okunmalarında. İşlevlerin üstünlüğü ise `Kesir`lerle de çalışmaları —
ör. `Aralık.kesirdenKapalı(1, 2, 0.1)`.

Aralıklar iki ayrı durumda çok işe yarıyor.

Birincisi, döngülere sayaç olarak:

```scala
yineleİçin(1 |-| 5) { n =>
    satıryaz(s"$n, ${n * n}")
}
```

İkincisi, veri yapılarını doldurmak için:

+ Bir örüntüsü olan veriyle verimli biçimde bir `EsnekDizik` yaratmak:

```scala
EsnekDizik.diziden(Aralık(1, 11, 3))
```

+ Bir aralığı bir demet resme çevirmek için `işle` kullanmak (sonra da
  onları çizmek):

```scala
temizle()
dez resimler = (1 |-| 5).işle { n =>
    dez resim = Resim.dikdörtgen(30, 20 * n)
    resim.konumuKur(n * 40, 0)
    resim
}

//yineleİçin(resimler) { r =>
//    çiz(r)
//}
```

#### 1.8.2 Eşlek (*Map*)

Bir `Eşlek`, anahtar-değer ikililerinden oluşan bir kaptır. Bir `Eşlek`e
anahtar-değer ikilileri ekleyebilir ve verilen anahtarların değerlerini
hızla arayıp bulabilirsiniz.

Bir *(anahtar, değer)* bir `e` eşleğinin içine girdi mi, `e(anahtar)` ile
aranıp bulunabilir.

Anahtarın eşlekte olmaması ihtimali varsa, o anahtarın değerini bulmayı
denemek için `e.al(anahtar)` ya da `e.alYoksa(anahtar, bulunamazsaDeğer)`
kullanabilirsiniz.

+ `e.al(anahtar)` bir `Belki` döndürür.
+ `e.alYoksa(anahtar, bulunamazsaDeğer)`, ya verilen anahtarın değerini ya
  da anahtar eşlekte yoksa `bulunamazsaDeğer`i döndürür.

Bir örnek:

```scala
çıktıyıSil()
dez eşleğim = Eşlek(
    "anahtar1" -> "değer1",
    "anahtar2" -> "değer2",
    "anahtar3" -> "değer3",
) //> eşleğim: Eşlek[Yazı,Yazı] = Eşlek(anahtar1 -> değer1, anahtar2 -> değer2, anahtar3 -> değer3)

eşleğim("anahtar1") //> res1: Yazı = değer1
eşleğim.al("anahtar1") //> res2: Belki[Yazı] = Biri(değer1)
eşleğim.al("anahtar5") //> res3: Belki[Yazı] = Hiçbiri
eşleğim.alYoksa("anahtar5", "Bulunamadı") //> res4: Yazı = Bulunamadı
```

Bir başka örnek:

```scala
çıktıyıSil()
dez yaşDefteri = Eşlek(
    "Rahul" -> 10,
    "Avinash" -> 12,
    "Manya" -> 11
)

dez ad = satıroku("Kimin yaşını öğrenmek istiyorsun?")
// ad eşlekte yoksa bu bir kuraldışı durum bildirir. Burada aldırmıyoruz.
dez yaş = yaşDefteri(ad)
satıryaz(s"${ad} adlının yaşı $yaş")
```

##### 1.8.2.1 Eşlem (değişebilir eşlek, *HashMap*)

Tanımlandıktan sonra bir eşleği güncelleyebilmeniz gerekiyorsa `Eşlem`
kullanın:

```scala
temizle()
çizSahne(siyah)
dez resim1 = boyaRengi(kırmızı) -> Resim.dikdörtgen(40, 40)
dez resim2 = boyaRengi(kırmızı) -> Resim.daire(20)
çiz(resim1, resim2)

dez hızlar = Eşlem(
    resim1 -> Yöney2B(3, 2),
    resim2 -> Yöney2B(-2, 3)
)

dez resimler = Dizi(resim1, resim2)

canlandır {
    resimler.herbiriİçin { resim =>
        dez resminHızı = hızlar(resim)
        resim.taşı(resminHızı)
        eğer (resim.çarpışıyorMu(sahneKenarı)) {
            dez yeniHız = sahneKenarındanYansıtma(resim, resminHızı)
            hızlar.güncelle(resim, yeniHız)
        }
    }
}
```

*Çevirmen notu:* Koco'da iki kapı var — `Eşlek` değişmez `Map`,
`Eşlem` ise değişebilen (İngilizcesi *HashMap*/*mutable Map*). Özgün
sayfanın `HashMap`i burada `Eşlem`.

#### 1.8.3 Küme (*Set*)

Bir **küme**, dizi gibi, birçok ögesi olan bir kaptır. Küme diziden şu
yönlerden farklıdır:

+ Ögeler belli bir sırada değildir.
+ Yinelenen öge olamaz.

Bir küme dizilere benzer işlemleri destekler — `herbiriİçin`, `işle` ve
`ele` dahil. Kümeler ayrıca `içeriyorMu`, `bileşim`, `kesişim` ve `fark`
gibi kümeye özgü işlemleri de destekler.

```scala
dez k1 = Küme(1, 2, 3, 4) //> k1: Küme[Sayı] = Küme(1, 2, 3, 4)
dez k2 = Küme(3, 4, 5, 6) //> k2: Küme[Sayı] = Küme(3, 4, 5, 6)
k1.kesişim(k2) //> res5: Küme[Sayı] = Küme(3, 4)
```

##### 1.8.3.1 Değişebilir küme (*HashSet*)

Tanımlandıktan sonra bir kümeyi güncelleyebilmeniz gerekiyorsa, değişebilir
bir küme kullanın:

```scala
temizle()
çizSahne(siyah)
dez ts = tuvalSınırları

tanım yeniMermi = {
    boyaRengi(kırmızı) -> Resim.dikdörtgen(2, 5)
}

den mermiler = Küme[Resim]()

yineleSayaçla(1000) {
    dez m = yeniMermi
    mermiler = mermiler.ekli(m)
    çiz(m)
    m.konumuKur(ts.solu + 20, ts.altı + 5)
    m.açıyaDön(-rastgele(45))
}

canlandır {
    mermiler.herbiriİçin { m =>
        m.taşı(0, 5)
    }

    mermiler.herbiriİçin { m =>
        eğer (m.çarpışıyorMu(sahneKenarı)) {
            mermiler = mermiler.çıkarılmış(m)
            m.sil()
        }
    }
}
```

*Çevirmen notu:* Koco'nun `Küme`si değişmezdir ve değişebilir kümenin
(*HashSet*) henüz Türkçe adı yok. Yukarıdaki sürüm bu yüzden `den` ile
tanımlı bir değişmez `Küme` kullanıyor: eklemek `ekli`, çıkarmak
`çıkarılmış` — her seferinde yeni bir küme kurulup ada yeniden bağlanıyor.
İşleyişi aynı, ama çok öge varsa değişebilir küme daha hızlı olurdu.
`EsnekDizik` de bu işi görür.

#### 1.8.4 Belki (*Option*)

Bir **belki**, bir değerin var da olabileceği yok da olabileceği yerlerde
kullanılır. Örneğin, elinizde bir sayı dizisi varken dizideki 100'den
büyük ilk sayıyı arayabilirsiniz. Böyle bir sayı dizide olabilir de
olmayabilir de. Bunu kodda iş başında görelim:

```scala
dez sayılar = Dizi(90, 11, 21, 47)
dez sayılar2 = Dizi(90, 11, 121, 147)

tanım şundanBüyükİlki(d: Dizi[Sayı], n: Sayı): Belki[Sayı] =
    d.bul { e =>
        e > n
    }

tanım yanıtıYaz(y: Belki[Sayı]): Birim = {
    eğer (y.varMı) {
        satıryaz(y.al)
    }
    yoksa {
        satıryaz("Sayı bulunamadı")
    }
}

dez yanıt = şundanBüyükİlki(sayılar, 100)
dez yanıt2 = şundanBüyükİlki(sayılar2, 100)

yanıtıYaz(yanıt)
yanıtıYaz(yanıt2)
```

Yukarıdaki kod şunu yazar:

```
Sayı bulunamadı
121
```

Bir `b` belkisinin içinde `d` değeri varsa, bu `Biri(d)` diye gösterilir.
Belkinin değerini `b.al` ile alabilirsiniz.
`b`nin içinde değer yoksa, bu `Hiçbiri` diye gösterilir.

#### 1.8.5 İkili/Demet (*Tuple*)

Bir **demet**, birden çok değeri bir arada paketlemenin kolay yoludur.
Bunun güzel bir kullanımı, bir işlevden birden çok değer döndürmektir:

```scala
tanım böl(n1: Sayı, n2: Sayı) = {
    dez bölüm = n1 / n2
    dez kalan = n1 % n2
    (bölüm, kalan)
} //> böl: (n1: Sayı, n2: Sayı)(Sayı, Sayı)

dez yanıt = böl(11, 3) //> yanıt: (Sayı, Sayı) = (3,2)
yanıt._1 //> res1: Sayı = 3
yanıt._2 //> res2: Sayı = 2
```

`n` ögeli bir `d` demetinde *i*'inci ögeye şöyle erişirsiniz: `d._i`.
Bunun bir örneğini yukarıdaki kodun son iki satırında görebilirsiniz.

İki ögeli demete **ikili** (*pair*) denir.

Bir eşleği, *(anahtar, değer)* ikililerinden oluşan bir kap olarak
görebileceğinizi de unutmayın.


2. Akış denetimi
--

Bir yazılım çalışırken, eski veriden yeni veri hesaplar ve bu yeni veriyi
gerektiği gibi kullanıcıya gösterir — elinin altındaki işlevlerin ve
komutların yardımıyla. Bu işlevlerin ve komutların yazılımda birbirine
nasıl dizildiği, **akış denetiminin** konusudur.

Yukarıdan bakınca:

+ Bir yazılım çalıştığında, içindeki yönergeleri birbiri ardına, sırayla
  yürütür.
+ Şu yapılar yukarıdaki öntanımlı yürütme kipini değiştirir:
  - **Döngüler** (`yinele`, `yineleİçin`, `için`, `yineleDoğruKaldıkça`
    vb.) aynı şeyi çok kere yapmanızı sağlar.
  - **Seçim** (`eğer`-`yoksa` ya da `eşle`) değişik koşullar altında
    değişik şeyler yapmanızı sağlar.
  - **Çağrılar** (işlevlere ya da komutlara) soyutlamalardan
    yararlanmanızı sağlar.

Yukarıdakilere biraz daha ayrıntılı bakalım.

### 2.1 Sıralama

Bu, bir yazılımın öntanımlı yürütme kipidir — yönergeler birbiri ardına
çalıştırılır. Bir örnek:

```scala
sil()
ileri(100)
sağ(90)
dez x = 200
ileri(x)
```

### 2.2 Bloklar

Bir **blok** bir kod öbeğidir. Döngüde (çok kere ne yapılacağını
belirtmek için), seçimde (seçenek kod yollarını belirtmek için) ya da yeni
bir işlev/komut tanımlarken (işlevin/komutun gövdesi olarak)
kullanılabilir. Yani daha ileri gitmeden önce blokları öğrenmeniz önemli.

Blok, `{` ile `}` arasındaki herhangi bir koddur. Scala'da bir bloğun şu
önemli işlevleri vardır:

+ Tek bir deyişin (ya da deyimin) beklendiği her yere, onları bir bloğun
  içine alarak birbiri ardına birçok deyim (ya da deyiş)
  koyabilirsiniz. Bu bloğun değeri, bloktaki son deyişin değeridir.
  Anımsayın: deyimler, `()` değerine indirgenen deyişlerdir.

```scala
dez x = {
    dez a = 10
    dez b = a * 3
    b + 2
}
satıryaz(x)
```

Bu şunu yazar:

```
32
```

+ Bir blok, adlandırma için yeni bir **kapsam** açar. Bir blok içinde
  tanıtılan bir ad yalnızca o blok içinde görünür ve onu saran
  kapsamlardaki adları gölgeler.

```scala
dez x = 10

{
    dez x = 20
    satıryaz(x)
}

satıryaz(x)
```

Bu şunu yazar:

```
20
10
```

### 2.3 Döngüler

Bir **döngü** bir miktar kodu alıp onu tekrar tekrar çalıştırır. Birçok
döngü çeşidi var. Birkaçına bakalım.

#### 2.3.1 yinele (*repeat*)

`yinele(n) { kod }` — verilen kodu `n` kere yineler. Bu, aynı şeyi tekrar
tekrar yapmanıza yardım eder.

```scala
sil()
yinele(4) {
    ileri(100)
    sağ(90)
}
```

#### 2.3.2 yineleİçin (*repeatFor*)

`yineleİçin(dizi) { öge => kod }` — verilen kodu çok kere, verilen dizinin
her ögesi için bir kere yineler. Geçerli dizi ögesi kodunuzun elinin
altındadır — geçerli ögeye göre biraz farklı bir şey yapmanıza yardım
etmek için.

```scala
sil()
hızıKur(hızlı)
yineleİçin(10 |-| 100) { n =>
    // n, içinden geçmekte olduğun dizinin geçerli ögesi
    ileri(n)
    sağ(91)
}
```

Şimdi belli bir soruna ve onu çözmenin birçok yoluna bakalım (size
döngülerle ilgili fikirler üstüne daha derin bir kavrayış vermek için).
Diyelim beş dikdörtgen (en = 20, boy = 100) çizmek istiyoruz.

Sorunu çözmenin ilk yolunda, resimleri yaratıp çizmek için `yineleİçin`
kullanıyoruz:

```scala
temizle()
yineleİçin(0 |-| 4) { n =>
    dez resim = Resim.dikdörtgen(20, 100)
    resim.konumuKur(n * 50, 0)
    çiz(resim)
}
```

Sorunu çözmenin ikinci yolunda, istediğimiz resimleri yaratmak ve onları
bir `EsnekDizik`e eklemek için `yineleİçin` kullanıyoruz. Sonra da
`EsnekDizik`teki bütün resimleri çiziyoruz.

```scala
temizle()
dez resimler = EsnekDizik.boş[Resim]
yineleİçin(0 |-| 4) { n =>
    dez resim = Resim.dikdörtgen(20, 100)
    resim.konumuKur(n * 50, 0)
    resimler += resim
}
çiz(resimler)
```

Sorunu çözmenin üçüncü yolu yukarıdaki ikinciye çok benziyor. Yalnızca
`yineleİçin` yerine `herbiriİçin` kullanıyoruz.

```scala
temizle()
dez resimler = EsnekDizik.boş[Resim]
(0 |-| 4).herbiriİçin { n =>
    dez resim = Resim.dikdörtgen(20, 100)
    resim.konumuKur(n * 50, 0)
    resimler += resim
}
çiz(resimler)
```

İkinci ve üçüncü çözümlerden alınacak fikir şu: `yineleİçin` ile
`herbiriİçin` tamamen birbirinin yerine geçebilir. Birini
kullanabildiğiniz yerde ötekini de kullanabilirsiniz. Seçim sizin.

Sorunu çözmenin dördüncü ve son yolu `işle` kullanıyor ve tartışmasız en
iyisi, çünkü işlevlerle komutlar güzelce ayrılmış oluyor.

```scala
temizle()
dez resimler = (0 |-| 4).işle { n =>
    dez resim = Resim.dikdörtgen(20, 100)
    resim.konumuKur(n * 50, 0)
    resim
}
çiz(resimler)
```

Yukarıdaki üçüncü (`herbiriİçin` kullanan) ve dördüncü (`işle` kullanan)
örnekler, sonraki bölümün konusu olan `için` döngüleriyle ilişkili.

#### 2.3.3 için (*for*)

Scala'daki `için` döngüsü son derece güçlüdür ve gereksinimize göre
`herbiriİçin`, `işle` ve `ele`'nin bir bileşimini kullanmanıza izin verir.
Yukarıdaki `herbiriİçin` ve `işle` örneklerini `için` ile yazalım:

İşte `herbiriİçin` sürümü:

```scala
temizle()
dez resimler = EsnekDizik.boş[Resim]
(0 |-| 4).herbiriİçin { n =>
    dez resim = Resim.dikdörtgen(20, 100)
    resim.konumuKur(n * 50, 0)
    resimler += resim
}
çiz(resimler)
```

Ve işte `için` ile yeniden yazılmış sürümü:

```scala
temizle()
dez resimler = EsnekDizik.boş[Resim]
için (n <- 0 |-| 4) {
    dez resim = Resim.dikdörtgen(20, 100)
    resim.konumuKur(n * 50, 0)
    resimler += resim
}
çiz(resimler)
```

İşte `işle` sürümü:

```scala
temizle()
dez resimler = (0 |-| 4).işle { n =>
    dez resim = Resim.dikdörtgen(20, 100)
    resim.konumuKur(n * 50, 0)
    resim
}
çiz(resimler)
```

Ve işte `için` ile yeniden yazılmış sürümü:

```scala
temizle()
dez resimler = için (n <- 0 |-| 4) ver {
    dez resim = Resim.dikdörtgen(20, 100)
    resim.konumuKur(n * 50, 0)
    resim
}
çiz(resimler)
```

Yukarıdaki `ver` kullanımına dikkat. `için` döngüsünün `herbiriİçin`
yerine `işle` kullanmasını sağlayan şey odur.

Şuna da dikkat: `yinele` ve `yineleİçin`, Kojo'nun sağladığı döngü
yöntemleridir; `için` ise Scala'nın kendi içinde vardır. Scala,
`yineleDoğruKaldıkça` (*while*) ve `yap`-`yineleDoğruKaldıkça`
(*do-while*) gibi başka standart döngü yöntemlerini de destekler, ama
onları burada ele almayacağız.

### 2.4 Seçim

Seçim, komutları yürütmek ya da deyişleri değerlendirmek için birden çok
yürütme yolu arasından seçmeyi içerir.

#### 2.4.1 eğer-yoksa (*if-else*)

`eğer (koşul) yol1 yoksa yol2`

+ koşul doğruysa `yol1`, değilse `yol2` tutulur.
+ `yol1` ve `yol2`, bir bloğun içine alınmış birçok deyim/deyiş içerebilir.
+ `eğer` deyişinin tümü, `yol1`e ya da `yol2`ye indirgenir.

Birkaç örneğe bakalım:

Komuta yönelik örnek (yolların `()`'a indirgendiği durum):

```scala
tanım kare(n: Sayı): Birim = {
    eğer (n > 100) {
        kalemRenginiKur(sarı)
        boyamaRenginiKur(kahverengi)
    }
    yoksa {
        kalemRenginiKur(kahverengi)
        boyamaRenginiKur(sarı)
    }

    yinele(4) {
        ileri(n)
        sağ(90)
    }
}
```

Deyişe yönelik örnek:

```scala
tanım mutlak(n: Sayı) = {
    eğer (n < 0) -n yoksa n
}
```

`eğer`-`yoksa`yı etkili kullanmak için **koşulları** anlamak önemli, çünkü
`eğer`-`yoksa`da hangi yolun tutulacağını belirleyen şey bir koşuldur.

Koşul, `İkil` döndüren herhangi bir işlevdir. Böyle işlevlere örnekler:

+ Sayısal değerler için `>`, `>=`, `<`, `<=`, `==`, `!=`.
+ `İkil` döndüren, sizin yazdığınız herhangi bir işlev.
+ İki `İkil` alıp bir `İkil` döndüren ikili `İkil` işleçleri — `&&`, `||`,
  `==` ve `!=`. Bunlar, `eğer (koşul)` içinde `İkil`leri birleştirmenizi
  sağlar.
+ Bir `İkil` alıp bir `İkil` döndüren `İkil` işleçleri — `!` ve `^`.

Bir örnek daha:

```scala
dez n1 = 10
dez n2 = 20
dez n3 = 30

tanım büyükSayı(n: Sayı): İkil = n > 100

eğer ((n1 > 15) && (n2 < n1)) {
    satıryaz("1. koşul")
}
yoksa eğer (((n3 > n1) && (n2 > 17)) || (n1 > 25)) {
    satıryaz("2. koşul")
}
yoksa eğer (büyükSayı(n2)) {
    satıryaz("3. koşul")
}
yoksa {
    satıryaz("Eşleşme yok")
}
```

### 2.5 Çağrılar

Bir **çağrı**, yazılımınızın yeni bir yere atlamasını, orada tanımlı olanı
yapmasını, sonra geri dönüp atladığı yerden devam etmesini sağlar.

Çağrı bir komutaysa, çağırana bir `()` döndürülür ve o gönül rahatlığıyla
göz ardı edilebilir (çünkü hiç bilgi taşımaz).

Çağrı bir işlevse, işlevin çıktı değeri çağırana döndürülür. O zaman
çağıranın, bu değeri yazılımın devamında nasıl kullanacağını çözmesi
gerekir. Bunun bir yolu, dönüş değerini bir `dez`de saklamaktır.

Bir komuta yapılan çağrılara örnek:

```scala
tanım kare(): Birim = {
    yinele(4) {
        ileri(100)
        sağ(90)
    }
}

sil()
kare()
sağ(45)
kare()
```

Bir işleve yapılan çağrıya örnek:

```scala
sil()
tanım köşegen(t: Kesir, y: Kesir) =
    karekökü(t * t + y * y)

ileri(100)
sağ(90)
ileri(50)
noktayaDön(0, 0)
dez k = köşegen(50, 100)
ileri(k)
```


3. Soyutlama / Adlandırma
--

Yazılım yazarken **soyutlama** (ilkellerle ve bileşimle birlikte) çekirdek
bir fikirdir. Soyutlama, yazılımınızda çok kere kullanmanız gereken
yararlı şeylere ad vermenizi sağlar (yazılımınızı okumayı ve anlamayı
netleştiriyorsa, bir kere kullanacağınız şeylere de).

Scala şu soyutlama araçlarını sunuyor. Her biri bir anahtar sözcük
yönergesi (ya da deyimi) kullanıyor:

### 3.1 dez (*val*)

`dez` anahtar sözcüğü yönergesi, bir adı bir değerle ilişkilendirmenizi
sağlar.

`dez ad1 = değer1` — `ad1`i `değer1` ile ilişkilendirir. Sağ taraf bir
deyiştir; sol tarafta ise deyişin değeriyle ilişkilendirilecek ad vardır.

```scala
dez x = 10
dez y = "Merhaba"
```

### 3.2 den (*var*)

`den` anahtar sözcüğü yönergesi, bir adı bir değere bağlamanızı sağlar. Bu
ad, yazılımınızın devamında başka bir değere bağlanabilir.

`den ad2 = değer2` — `ad2`yi `değer2`ye bağlar. Sağ taraf bir deyiştir;
sol tarafta ise deyişin değerine bağlanacak ad vardır.

```scala
den sayaç = 0
yineleDoğruKaldıkça (sayaç < 10) {
    satıryaz(s"$sayaç, ${sayaç * sayaç}")
    sayaç += 1
}
```

### 3.3 tanım (*def*)

`tanım` anahtar sözcüğü yönergesi, yeni bir komut ya da işlev
tanımlamanızı sağlar.

`tanım yeniKomut(girdiler): Birim = { kod }` — belirtilen girdileri alan
ve verilen kod bloğunda belirtilen komutları yürüten yeni bir komut
yaratır.

Girdiler sıfır ya da daha çok `ad: tür` ikilisi olabilir (birden çok
girdi varsa virgülle ayrılır); burada `ad` bir girdinin adı, `tür` ise
onun türüdür.

Bazı yeni komutların tanımlanmasına ve kullanılmasına bir örnek:

```scala
tanım kare1(): Birim = {
    yinele(4) {
        ileri(100)
        sağ(90)
    }
}

tanım kare2(boy: Sayı): Birim = {
    yinele(4) {
        ileri(boy)
        sağ(90)
    }
}

tanım dikdörtgen(b: Sayı, e: Sayı): Birim = {
    yinele(2) {
        ileri(b)
        sağ(90)
        ileri(e)
        sağ(90)
    }
}

sil()
hızıKur(hızlı)
kare1()
kare2(50)
kare2(25)
dikdörtgen(200, 75)
```

`tanım yeniİşlev(girdiler) = { kod }` — belirtilen girdileri alan, verilen
kod bloğunda belirtilen deyimleri yürüten ve kod bloğundaki son deyişin
değerini döndüren yeni bir işlev yaratır.

Girdiler sıfır ya da daha çok `ad: tür` ikilisi olabilir (birden çok
girdi varsa virgülle ayrılır); burada `ad` bir girdinin adı, `tür` ise
onun türüdür.

Bazı yeni işlevlerin tanımlanmasına ve kullanılmasına bir örnek:

```scala
tanım ikiKatı(n: Sayı) = n * 2
tanım biraziUzunHesap(n1: Sayı, n2: Sayı) = {
    dez a1 = n1 * n2
    dez a2 = karekökü(a1)
    a2 / 2
}

ikiKatı(4) //> res4: Sayı = 8
biraziUzunHesap(10, 20) //> res5: Kesir = 7.0710678118654755
```

*Çevirmen notu:* özgün sayfa komutları `def square1() { ... }` diye, yani
eşittir işaretsiz yazıyor. O yazım Scala 2.13'te eskitildi, Scala 3'te
kaldırıldı; onun için burada `: Birim = { ... }` biçimini kullandık.

### 3.4 sınıf (*class*)

`sınıf` anahtar sözcüğü yönergesi yeni bir sınıf yaratmanızı sağlar. Bir
sınıf, yeni bir nesne türünün betimlemesidir. Sınıf `dez`ler, `den`ler ve
`tanım`lar içerebilir.

Sınıfın arkasındaki temel fikir, yararlı bir soyutlama yaratmak için
yazılımınızdaki ilişkili veriyle davranışı bir araya getirmektir.
Yazılımınızı yazmayı ve okumayı kolaylaştırıyorsa bunu yapmak
istersiniz. İyi bir soyutlamaya sahip olduğunuzda, yazılımınızın geri
kalanı onu nasıl gerçeklendiğine kafa yormadan güzelce kullanabilir. En
iyi durumda yazılımınız, içindeki soyutlamaların bir korosu hâline gelir.

Bir sınıf, yazılımınızdaki etkin bir varlığı temsil etmek için
kullanılabilir. Sınıflar özellikle oyun ve benzetim gibi durumlarda işe
yarar.

Bir kere bir sınıf yarattınız mı, diyelim `X`, `X` türünde bir nesne (`X`in
bir **örneği** de denir) şöyle yaratabilirsiniz: `yeni X()` ya da
`yeni X(girdiler)`.

Bir örnek:

```scala
sil()
çizSahne(Renkler.siyah)

sınıf SekenDikdörtgen(x: Sayı, y: Sayı) {
    dez resim = Resim.dikdörtgen(40, 40)
    resim.boyamaRenginiKur(kırmızı)
    resim.konumuKur(x, y)
    den hız = Yöney2B(2, 10)
    dez yerçekimi = Yöney2B(0, -0.2)

    tanım çiz(): Birim = {
        resim.çiz()
    }

    tanım adımla(): Birim = {
        hız = hız + yerçekimi
        resim.taşı(hız)
        eğer (resim.çarpışıyorMu(sahneKenarı)) {
            hız = sahneKenarındanYansıtma(resim, hız)
        }
    }
}

dez sd = yeni SekenDikdörtgen(-100, -100)
sd.çiz()

canlandır {
    sd.adımla()
}
```

### 3.5 durum sınıf (*case class*)

**Durum sınıf**, yazılımınızda yararlı bir şeyi temsil etmek için bir
demet veri değerini bir araya koymanın kolay yoludur.

`durum sınıf Ad(değerAdlarıVeTürleri)` — verilen türlerdeki verilen
değerlere sahip, `Ad` adlı bir durum sınıf tanımlar.

`değerAdlarıVeTürleri` (genellikle) virgülle ayrılmış iki ya da daha çok
`ad: tür` ikilisidir.

Sınıfın yeni bir örneği şöyle yaratılabilir: `Ad(değerler)`; burada
`değerler`, doğru sayıda ve uygun türde, virgülle ayrılmış bir değer
listesidir. Bir durum sınıfın örneğini yaratmak için `yeni`ye gerek
olmadığına dikkat edin. Bu, durum sınıfları içsel veri türleri kadar
kullanışlı yapıyor.

Hızlı bir örnek:

```scala
durum sınıf Kişi(adı: Yazı, soyadı: Yazı, yaşı: Sayı)

dez k1 = Kişi("Rahul", "Agarwal", 21)
dez k2 = Kişi("Sanjay", "Pandey", 35)
```

Ve işte daha uzun bir örnek:

```scala
// Şuradaki fikirlerden esinlendik: https://generativeartistry.com/tutorials/tiled-lines/
temizle()
artalanıKur(Renk.kym(60, 63, 65))
dez ts = tuvalSınırları
dez n = 20
dez deltax = ts.eni / n
dez deltay = ts.boyu / n

durum sınıf Çizgi(x: Kesir, y: Kesir, e: Kesir, b: Kesir)

tanım çizgiYap(x: Kesir, y: Kesir, e: Kesir, b: Kesir) = {
    dez soldanSağa = rastgeleSeçim
    eğer (soldanSağa) Çizgi(x, y, e, b) yoksa Çizgi(x, y + b, e, -b)
}

// çizimin veri yapısını bellekte kuralım
dez çizgiler = EsnekDizik.boş[Çizgi]
yineleİçin(0 |- n) { nx =>
    dez x = ts.solu + nx * deltax
    yineleİçin(0 |- n) { ny =>
        dez y = ts.altı + ny * deltay
        çizgiler += çizgiYap(x, y, deltax, deltay)
    }
}

// veri yapısını çizelim
yineleİçin(çizgiler) { ç =>
    dez resim = Resim.çizgi(ç.e, ç.b)
    resim.konumuKur(ç.x, ç.y)
    resim.kalemKalınlığınıKur(2)
    resim.kalemRenginiKur(beyaz)
    çiz(resim)
}
```

*Çevirmen notu:* son örnekte `cb.x` / `cb.y` yerine
`tuvalSınırları.solu` / `.altı`, `cb.width` / `cb.height` yerine
`.eni` / `.boyu` var; `cm.rgb(60, 63, 65)` ise `Renk.kym(60, 63, 65)`.
