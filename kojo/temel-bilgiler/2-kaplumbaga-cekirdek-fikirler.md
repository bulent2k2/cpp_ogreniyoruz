Kaplumbağayla çizim — çekirdek fikirler
=======================================

> Kogics Foundation'ın **Fundamentals** dizisindeki
> [Turtle Graphics - Core Ideas](https://docs.kogics.net/concepts/turtle-core-ideas.html)
> sayfasının çevirisi. Özgün metin: © 2010-2025 Kogics Foundation,
> CC BY-NC-SA. Çeviri de aynı lisansta; deponun CC BY-SA 4.0 lisansı bu
> dosyayı kapsamaz (bkz. [`LICENSE`](../../LICENSE), 3. bölüm).
> Kod örnekleri Koco'nun Türkçe adlarıyla yazıldı.


Kojo'da kaplumbağanın yardımıyla çizim ve sanat yapmak kolay. Şu çekirdek
fikirlere aşina olmanız yeter:

+ Programınız (bir çizim yapmak için) komutlar içeren satırlardan oluşur.
  Programı çalıştırdığınızda işini satır satır yapar; komutları programın
  tepesinden başlayıp aşağı doğru yürütür.
+ Programınız (satır satır, yukarıdan aşağı) çalışırken kaplumbağaya komut
  vererek tuvale bir şeyler çizer.
+ **`sil()`** komutu, tuvale çizmeye başlamadan önce onu temizlemek için
  programın başında kullanılır.
+ Tuvaldeki bütün düz çizgiler **`ileri(kaçAdım)`** komutuyla yapılır; bu
  komut kaplumbağanın burnunun baktığı yönde (düz) bir çizgi çizer.
+ **`sağ(açı)`** ve **`sol(açı)`** komutları kaplumbağanın burnunun yönünü
  değiştirir.
+ Tuvaldeki bütün eğri çizgiler **`sağ(açı, yarıçap)`** ve
  **`sol(açı, yarıçap)`** komutlarıyla yapılır.
+ Kaplumbağayı tuvalde çizgi çizmeden dolaştırmak istiyorsanız şu
  seçenekler var:
  - **`zıpla(kaçAdım)`** komutunu kullanın.
  - **`kalemiKaldır()`** deyin, istediğiniz kadar `ileri`, `sağ` vb. yapın,
    sonra **`kalemiİndir()`** deyin.
  - **`konumuKur(x, y)`** deyin (`atla(x, y)` de aynı işi görür).
+ Harika çizimler yapmak için bir tutam kaplumbağa komutu bilmeniz yeter.
  Bu komutlar komut kılavuzunda listeli:
  [iKojo'nun Türkçe komut kılavuzu](https://ikojo.fly.dev/yardim/komutlar).
+ Bir sürü komutu çok kere çalıştırmak için **`yinele`** komutunu
  kullanabilirsiniz. Bu, programlarınızı kısaltır ve anlaşılır kılar.
+ Programınız belli bir şeyi çok kere yapıyorsa, o şeye bir ad verip
  Kojo'ya o adla yeni bir komut öğretebilirsiniz — **`tanım`**
  komutuyla.
+ Renkli çizgiler çizmek için **`kalemRenginiKur(renk)`** komutunu
  kullanın.
+ Renkli dolu alanlar çizmek için **`boyamaRenginiKur(renk)`** komutunu
  kullanın.
+ Yukarıdaki iki komut, girdi olarak sizden renk ister. Kojo'da renkler
  [ayrı bir sayfada](5-renkler.md) daha ayrıntılı anlatılıyor; işte kısa
  özeti:
  - Kojo'nun sizin için rastgele bir renk seçmesi için **`rastgeleRenk`**
    ya da **`rastgeleRenk.soluk(oran)`** işlevlerini kullanın.
  - **`Renkler`** nesnesini şöyle kullanın: programınızda bir renk gereken
    yere düzenleyicide `Renkler.` yazıp `Ctrl+Boşluk`'a basın. Önceden
    tanımlı renklerin listesi açılır; birini seçip `Enter`'a basın, renk
    programınıza girsin.
  - Programınızdaki herhangi bir renge `Ctrl+Tık` yaparak renk seçicisini
    açın. Renk seçicisinin içinde bir rengi gözle seçebilir, ya da
    istediğiniz rengin tonunu, doygunluğunu, açıklığını ve/veya
    saydamlığını elle değiştirebilirsiniz.
+ Kalın ya da ince çizgi çizmek için **`kalemKalınlığınıKur(kalınlık)`**
  komutunu kullanın.

Yukarıdaki fikirlerin bir kısmını iş başında gösteren bir örnek:

```scala
sil()
tanım kare(): Birim = {
    yinele(4) {
        ileri(100)
        sağ(90)
    }
}

sil()
hızıKur(hızlı)
kalemRenginiKur(Renkler.siyah)
yinele(20) {
    boyamaRenginiKur(rastgeleRenk.soluk(0.5))
    kare()
    sağ(18)
}
```

Çıktı: siyah kenarlı, içleri yarı saydam rastgele renklerle boyanmış,
18 derecelik aralıklarla dönmüş yirmi kareden oluşan bir çiçek deseni.
