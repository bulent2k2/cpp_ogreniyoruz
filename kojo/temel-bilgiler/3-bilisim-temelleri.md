Koco için bilişim temelleri
===========================

> Kogics Foundation'ın **Fundamentals** dizisindeki
> [Computing essentials for Kojo](https://docs.kogics.net/concepts/computing-essentials.html)
> sayfasının çevirisi. Özgün metin: © 2010-2025 Kogics Foundation,
> CC BY-NC-SA. Çeviri de aynı lisansta; deponun CC BY-SA 4.0 lisansı bu
> dosyayı kapsamaz (bkz. [`LICENSE`](../../LICENSE), 3. bölüm).
> Kod örnekleri Koco'nun Türkçe adlarıyla yazıldı; özgün sayfadaki üç
> şekil yerine sade metin şemaları çizildi.


Kaplumbağa çizimlerinin ötesine geçip ilginç programlar yazmak için
bilmeniz gereken **en az** miktarda programlama kuramı ve Scala bilgisi
burada.


Bilişimin temelleri
--

*Bilgisayar nedir?*

Sözlük yanıtı şu: hesaplama yapan bir aygıt.

*Hesaplama da nedir?*

Hesaplama, bilgi alır ve yeni bilgi verir:

```
    bilgi  ──▶  [ hesaplama ]  ──▶  yeni bilgi
```

Soyut fikir bu. Gerçek fiziksel hesaplamaları ise elektronik bir
bilgisayar yapar. İdealleştirilmiş görünüşü şöyle:

```
   girdi aygıtı ──▶ ┌───────────────────────┐ ──▶ çıktı aygıtı
                    │   ana bellek ↔ İMB    │
                    └───────────┬───────────┘
                                ▼
                          ikincil saklama
```

Yani elektronik bir bilgisayar, üstünde çalışan programa göre şunları
yapar:

1. Bir girdi aygıtından ana belleğe bilgi alır.
2. İMB'ye (işlemci, *CPU*) bu girdi bilgisi üstünde çalıştırıp yeni bilgi
   ürettirir; yeni bilgi ana belleğe geri konur. Yeni bilgi iki türlü
   olur: ara hesaplar (daha çok hesaplamaya girdi olarak geri beslenir) ve
   çıktı bilgisi.
3. Çıktı bilgisini ana bellekten alıp bir çıktı aygıtına yazar.
4. Çıktı bilgisinin bir kısmını (bilgisayar yeniden başlayınca da kalması
   gerekenleri) ikincil saklamaya kaydeder.
5. Yukarıdaki adımların bir ya da birkaçını, söylendiği kadar yineler.

Şimdi İMB ile ana belleğe yakınlaşalım:

```
   ┌── ana bellek ───────────────┐        ┌──── İMB ────┐
   │  KOD                        │◀───────│ komut       │
   │    program komutları        │        │ göstergesi  │
   ├─────────────────────────────┤        │      │      │
   │  VERİ                       │◀──────▶│   saat      │
   │    yığın (yerel değişkenler)│        │   çevrimi   │
   │    öbek  (nesneler/veri)    │        └─────────────┘
   └─────────────────────────────┘
```

+ Bellek (bilgisayar programları için) iki bölüme ayrılır: **kod** ve
  **veri**.
+ Bir programı çalıştırdığınızda, programın komutları kod bölümüne
  yüklenir.
+ İMB'nin bir **komut göstergesi** var; çalıştıracağı sıradaki komutu
  gösterir. Program yüklendikten sonra gösterge programdaki ilk komutu
  gösterir.
+ Bilgisayardaki saat çevrimi İMB'yi ileri sürdükçe, İMB programdaki
  komutları birbiri ardına çalıştırır. Komutlar sırayla çalışır, ama
  programınızdaki özel komutlar İMB'ye şunları da yaptırır: **döngü**
  (`yinele` ile), **seçim** (`eğer`/`yoksa` ile) ve **çağrı** (bir
  işlev/komut kullanımıyla).
+ Kod, veri üstünde çalışır (veriyi girdi olarak alır, veri üretir).
+ Bir programı çalıştırdığınızda içindeki veri, veri bölümüne yüklenir.
  Program çalışırken bir girdi aygıtından veri bölümüne başka veri de
  okunabilir.
+ Veri bölümü ikiye ayrılır: **yığın** (yerel değişkenlerin yaşadığı yer)
  ve **öbek**, verinin/nesnelerin yaşadığı yer. Şimdilik bunu
  kafanıza takmayın.
+ (Scala'da) her veri değeri bir **nesnedir** — kendisiyle çalışabilen
  koda bir başvuru içerir.

Bilgisayar programları işte bu fiziksel düzende çalışır.


Programın yapısı
--

+ Program, metin satırlarından oluşan bir dizidir.
+ Her satır bilgisayar için komutlar içerir. Bu komutlar şu türden
  olabilir:
  - **Komutlar** — dış dünyada sezilebilen çıktı eylemleri almanızı
    (örneğin `ileri(100)`, `satıryaz(10)`) ya da sonraki eylemleri
    dolaylı etkilemenizi (örneğin `kalemRenginiKur(mavi)`) sağlar.
    - `ileri(100)` içindeki `100` sayısının/değerinin, `ileri` komutuna
      geçirilen bir girdi olduğuna dikkat edin. Benzer biçimde `10`
      yukarıdaki `satıryaz`ın girdisi, `mavi` de `kalemRenginiKur`un
      girdisidir.
    - Komutlar için başka iki ad daha kullanıldığını bilin:
      *deyim* (*statement*) ve *yordam* (*procedure*).
  - **Deyişler** (*expression*) — programınızın, bir değer üretmek üzere
    değerlendirilebilen parçaları. İki türü var:
    - **İşlevler** — girdi değerleri alıp bunlardan çıktı (ya da dönüş)
      değeri hesaplayanlar (örneğin `yakın(11.1)`, `kuvveti(2, 3)`).
    - **Yalın değerler** (*literal*) — kendi kendilerine
      değerlenenler (örneğin `9`, `7.1`, `mavi`, `"merhaba"`,
      `Dizin(1, 2, 3)`).
  - **Anahtar sözcük komutları** — Scala'da özel anlamı olan, var olan
    komutları birleştirerek programlarınızı yapılandırmanızı sağlayanlar
    (örneğin `dez`, `den`, `tanım`). Günün sonunda anahtar sözcük
    komutları çoğunlukla komut gibi davranır (ve bu bağlamda *deyim*
    denir).
  - **Sorgular** — programın ortamındaki (değişebilen) değerlere
    erişmenizi sağlar (örneğin `konum`, `doğrultu`,
    `sayıOku("Bir sayı gir")`, `rastgele(10)`). Sorgu, bir değer
    döndürmesiyle işleve benzer; ama aynı girdiyle her kullanımda başka
    bir çıktı verebilmesiyle işlevden ayrılır. Sorguyu *arı olmayan
    işlev* diye düşünebilirsiniz.

Notlar:

+ Programınızdaki komutlar, işlerini yapmak için veri değerlerini
  kullanır. Bunun ayrıntısı aşağıdaki *programın çalışması* bölümünde.
+ Bir komutu ya da işlevi programınızda, (isteğe bağlı) girdi verisiyle
  **çağırarak** kullanırsınız. Komut ya da işlev bitince, çağıran
  komuttan sonraki komuta döner.
+ İşlevler, yaptıkları hesabın sonucu olan çıktı değerlerini döndürür. Bu
  çıktı değerleri, işlev çağrısından sonraki komutun kullanımına açıktır.
+ Komutlar da çıktı değeri döndürür! Sadece her komut tam olarak aynı
  çıktı değerini döndürür: **birim** (`()` diye yazılır). Bu birim
  değerinin `()` türü `Birim`dir. `()`'yi hiç bilgi içermeyen bir değer
  diye düşünebilirsiniz.
+ Bir önceki olgu göz önüne alınırsa, bir Scala programı deyişler
  dizisinden başka bir şey değildir. Sadece bu deyişlerin bir kısmına
  (`()` döndürenlere) komut ya da deyim diyoruz.
+ Şunu hatırlamak iyi olur: deyişler kaynak kodda, değerler bellekte
  yaşar.


Programın çalışması
--

Bir program veri ve koddan yapılmıştır. Kod, programı oluşturan komutlar
demek. Bir program, başlarken ve çalışırken şunları yapar:

1. Program bir miktar **ilk veri değeriyle** başlar.
   - Bu ilk değerler programın içine gömülü olabilir, ya da bir sorguyla
     dışarıdan okunabilir.
2. Sonra (isteğe bağlı olarak) elindeki değerlerden **yeni değerler
   hesaplar**.
   - Bu hesap işlevlerle yapılır.
3. Sonra (yeni) değerlerine dayanarak **çıktı üretir**.
   - Çıktılar, programın kullanıcılarının görmesi/kullanması içindir.
     Çıktılar komutlarla üretilir.
4. Sonra (isteğe bağlı olarak) yukarıdaki 2. adıma geri döner.

Şu basit program yukarıdaki 1., 2. ve 3. adımları iş başında gösteriyor:

```scala
dez s1 = sayıOku("Bir sayı gir")
dez s2 = sayıOku("Bir sayı daha gir")
dez toplam = s1 + s2
satıryaz(s"$s1 ile $s2'nin toplamı $toplam")
```


Program geliştirme
--

Program yazarken üç önemli fikir kullanırsınız:

+ **İlkeller** (*primitive*) — programlama dilinizin/ortamınızın size
  verdiği komutlar, işlevler ve veri türleri.
+ **Bileşim** (*composition*) — programlama dilinizin, ilkelleri yararlı
  işler yapmak üzere birleştirmenize izin verdiği yollar.
+ **Soyutlama** (*abstraction*) — yararlı bileşimlere ad verme süreci;
  böylece onlar da programınızda birer ilkel hâline gelir.

Kojo'da program yazarken bu fikirlerin nasıl işlediğine bakalım.


### Koco'nun ilkelleri

Kojo'daki ilkellerin bir kısmı şu başlıklar altında: kaplumbağa çizimi,
resim çizimi, oyun, veri türleri, yardımcı komutlar ve işlevler. Türkçe
listeleri [komut kılavuzunda](https://ikojo.fly.dev/yardim/komutlar).


### Bileşim

**Komutlar/deyimler.** Komutlar şu yollarla bileştirilebilir:

+ **Sıralama** — komutları programınızda birbiri ardına koyarsınız, onlar
  da sırayla, yukarıdan aşağı, satır satır çalışır.
+ **Döngü** — bir komut dizisinin birden çok kere çalışmasını istediğiniz
  durum için. Bunun için `yinele` ve `yineleİçin` gibi şeyleri
  kullanabilirsiniz. Oyunlardaki canlandırmalar için
  `canlandır { kod }` komutunu kullanabilirsiniz. `canlandır`la,
  verdiğiniz kod, canlandırmayı durdurana kadar saniyede yaklaşık elli
  kere çağrılır.
+ **Seçim** — bir koşulun sonucuna göre iki ayrı kod yolundan birini
  seçmek için `eğer`/`yoksa` kullanabilirsiniz. Bu da bir bileşim
  yöntemidir.
  - Koşul, bir `İkil`e (`doğru` ya da `yanlış`) değerlenen bir deyiştir.

**İşlevler.** İşlevler, birinin çıktısını ötekine girdi olarak vererek
bileştirilir. Bu iki ayrı yolla yapılabilir:

İşlev çağrılarını **iç içe koyarak ya da zincirleyerek**:

```scala
// 1. örnek
tanım ikiKatı(s: Sayı) = s * 2
tanım üçKatı(s: Sayı) = s * 3
satıryaz(ikiKatı(üçKatı(4)))            // 24

// 2. örnek
satıryaz((1 |-| 10).ele(s => s % 2 == 0).işle(s => s * 2))
// Dizi(4, 8, 12, 16, 20)
```

Ara sonuçları `dez`lerde **saklayıp** işlevleri sırayla çağırarak:

```scala
// 1. örnek
tanım ikiKatı(s: Sayı) = s * 2
tanım üçKatı(s: Sayı) = s * 3
dez üçle = üçKatı(4)                    // 12
satıryaz(ikiKatı(üçle))                 // 24

// 2. örnek
dez çiftler = (1 |-| 10).ele(s => s % 2 == 0)   // Dizi(2, 4, 6, 8, 10)
dez çiftlerinİkiKatı = çiftler.işle(s => s * 2) // Dizi(4, 8, 12, 16, 20)
```

Komut ve işlev bileşimi, **denetim akışı** fikriyle sıkı sıkıya
ilgilidir.

**Scala'nın anahtar sözcük komutları.** Komutların ve işlevlerin nasıl
bileştirildiğini yukarıda gördünüz. Şunu akılda tutun: Scala'nın anahtar
sözcük komutları, komutları/işlevleri/veriyi belirli kullanımlar için
bileştirmenin ek yollarını verir. Bu komutları yol aldıkça (ve
gerektikçe) öğreneceksiniz.

**Veri.**

+ Scala'nın kapları (`Dizin`, `Küme`, `Eşlem` ...), bilinen durumlar için
  önceden tanımlanmış veri bileştirme araçlarıdır.
+ **Durum sınıfları** (`durum sınıf`) veriyi kendi gereksinimlerinize göre
  bileştirmenizi sağlar.


### Soyutlama

Soyutlama, yararlı bir bileşime ad verme sürecidir (süreç diyoruz, çünkü
programınızı iyileştirdikçe soyutlamalar da değişir). Kojo/Scala'da
soyutlamaları şu yollarla yaratabilirsiniz:

+ **`dez`** anahtar sözcük komutu bir adı bir değerle ilişkilendirmenizi
  sağlar; örneğin `dez x = 10`. Bu bir soyutlama biçimidir.
+ **`den`** anahtar sözcük komutu bir adı bir değere bağlamanızı sağlar;
  örneğin `den x = 10`. Bu ad, programınızın ilerisinde başka bir değere
  bağlanabilir. Bu da bir soyutlama biçimidir.
+ **`tanım`** anahtar sözcük komutu yeni bir komut ya da işlev
  tanımlamanızı sağlar. Bu bir soyutlama aracıdır.
+ **`sınıf`** anahtar sözcük komutu yeni bir sınıf yaratmanızı sağlar.
  Sınıf, yeni bir nesne türünün tarifidir. Sınıfın içinde `dez`ler,
  `den`ler ve `tanım`lar olabilir. Bu güçlü bir soyutlama aracıdır.
  - Bir sınıf yarattıktan sonra, diyelim `X`, `X` türünde bir nesne (`X`in
    yeni bir *örneği* de denir) şöyle yaratabilirsiniz: `yeni X()`, ya da
    `X` girdi alıyorsa `yeni X(girdiler)`.
+ **`durum sınıf`** anahtar sözcük komutu, bir veri bileşimini tarif eden
  bir durum sınıfı yaratmanızı sağlar.


Bir örnek
--

Bu fikirlerin çoğunu bir araya getiren bir program:

```scala
sil()
çizSahne(Renkler.siyah)
dez ts = tuvalSınırları

sınıf Şekil(xKayması: Sayı, yKayması: Sayı) {
    dez resim = Resim {
        boyamaRenginiKur(kırmızı)
        yinele(4) {
            ileri(40)
            sağ(90)
        }
    }
    resim.konumuKur(ts.solu + xKayması, ts.altı + yKayması)
    den hız = Yöney2B(2, 10)
    dez yerÇekimi = Yöney2B(0, -0.2)

    tanım çiz(): Birim = {
        resim.çiz()
    }

    tanım adımla(): Birim = {
        hız = hız + yerÇekimi
        resim.taşı(hız)
        eğer (resim.çarpışıyorMu(sahneKenarı)) {
            hız = sahneKenarındanYansıtma(resim, hız)
        }
    }
}

dez şekil = yeni Şekil(20, 20)
şekil.çiz()

canlandır {
    şekil.adımla()
}
```


İçindekiler listesindeki iki bölüm daha
--

Özgün sayfanın içindekiler listesinde iki başlık daha var —
**Scala Quickref** ve **How-tos**. İkisi de ayrı sayfalara bağlanıyor.
Onları da çevirdik:

+ [Skala kısa kılavuzu](6-skala-kisa-kilavuz.md) — türler, akış denetimi,
  soyutlama; bol örnekle.
+ [Oyun tarifleri](7-oyun-tarifleri.md) — oyun yazarken sık gereken altı
  küçük yazılımcık.

Daha geniş bir Türkçe Skala anlatımı isterseniz iKojo'nun içindeki
[19 bölümlük kılavuza](https://ikojo.fly.dev/yardim/skala) bakın.
