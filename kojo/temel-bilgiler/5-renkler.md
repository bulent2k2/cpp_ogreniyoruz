Renkler
=======

> Kogics Foundation'ın **Fundamentals** dizisindeki
> [Colors](https://docs.kogics.net/concepts/colors.html) sayfasının
> çevirisi. Özgün metin: © 2010-2025 Kogics Foundation, CC BY-NC-SA.
> Çeviri de aynı lisansta; deponun CC BY-SA 4.0 lisansı bu dosyayı
> kapsamaz (bkz. [`LICENSE`](../../LICENSE), 3. bölüm).
> Kod örnekleri Koco'nun Türkçe adlarıyla yazıldı; özgün sayfadaki üç
> ekran görüntüsü alınmadı.


Kojo'da renkleri şu yollarla kullanabilirsiniz:

+ Rastgele renkler
+ Önceden tanımlı renkler
+ Kendi renkleriniz
+ Renk geçişleri


Rastgele renkler
--

Programınızda bir renk gereken her yerde `rastgeleRenk` işlevini
kullanabilirsiniz. Örneğin:

```scala
sil()
hızıKur(hızlı)
yinele(10) {
    boyamaRenginiKur(rastgeleRenk)
    yinele(4) {
        ileri(100)
        sağ(90)
    }
    sağ(36)
}
```

Üst üste binen şekiller yapıyorsanız (yukarıdaki çizimde olduğu gibi),
rastgele renklerinizi `rastgeleRenk.soluk(oran)` işleviyle saydam
yapabilirsiniz. Solma oranı 0.0 ile 1.0 arasında bir değerdir. 1.0 solma,
rastgele rengin tamamen saydam olduğu; 0.0 solma ise tamamen donuk olduğu
anlamına gelir. Aradaki değerler istediğiniz etkiyi ayarlamanızı sağlar:

+ 0.9 solma çok saydam bir renk verir
+ 0.1 solma azıcık saydam bir renk verir
+ 0.5 solma orta saydamlıkta bir renk verir

```scala
sil()
hızıKur(hızlı)
yinele(10) {
    boyamaRenginiKur(rastgeleRenk.soluk(0.5))
    yinele(4) {
        ileri(100)
        sağ(90)
    }
    sağ(36)
}
```


Önceden tanımlı renkler
--

Önceden tanımlı bütün renklerin listesi `Renkler` nesnesinin içinde.
Düzenleyicide `Renkler.` yazıp `Ctrl+Boşluk`'a basarak listeyi
açabilirsiniz. En çok kullanılanlar doğrudan da yazılabiliyor: `siyah`,
`beyaz`, `kırmızı`, `mavi`, `yeşil`, `sarı`, `mor`, `turuncu`,
`kahverengi`, `camgöbeği`, `koyuMavi` ...

Türkçe adların tam listesi
[komut kılavuzunda](https://ikojo.fly.dev/yardim/komutlar); özgün
İngilizce liste ise Kojo belgelerindeki *predefined ColorMaker colors*
sayfasında.


Kendi renkleriniz
--

Önceden tanımlı bir renk düzenleyicide bir kere kullanıldıktan sonra,
üstüne `Ctrl+Tık` yaparak renk seçicisini açabilirsiniz. Renk
seçicisinde, istediğiniz rengin tonunu, doygunluğunu, açıklığını ve
saydamlığını ayarlayabilirsiniz:

+ Temel rengi **Ton** (*hue*) kaydıracıyla seçin (0 ile 360 arası bir
  sayı). 0 kırmızı, 120 yeşil, 240 mavi, 360 yine kırmızı.
+ Bu renge **Doygunluk** (*saturation*) kaydıracıyla gri katın. 100 arı
  renk; 50 yarı renk yarı gri; 0 tamamen gri.
+ Renge **Açıklık** (*lightness*) kaydıracıyla beyaz ya da siyah katın.
  50 arı renk; 50'den büyük sayılar giderek daha çok beyaz katar;
  50'den küçük sayılar giderek daha çok siyah katar.
+ Rengin saydamlığını **Saydamlık** kaydıracıyla artırın.

*Çevirmen notu:* renk seçicisi masaüstü Koco'nun özelliğidir; tarayıcıda
çalışan iKojo'da bulunmayabilir. Orada rengi elle yazmak için `ada(ton,
doygunluk, açıklık)` işlevini kullanabilirsiniz.


Renk geçişleri
--

Yapılacak. *(Özgün sayfada da bu bölüm "Todo" diye duruyor.)*
