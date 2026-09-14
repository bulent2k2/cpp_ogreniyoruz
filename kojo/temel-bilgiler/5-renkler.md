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

Önceden tanımlı bütün renkler `Renkler` nesnesinin içinde. Düzenleyicide
`Renkler.` yazıp `Ctrl+Boşluk`'a basarak listeyi açabilirsiniz.

Aşağıdaki tablo **çeviriye ek**: özgün sayfa bu listeyi ayrı bir sayfaya
bağlıyor ve İngilizce adları veriyor. Türkçe adları Koco'nun kaynağından
çıkardık (`kojo/tr/renk.scala`), RGB değerlerini de renklerin tanımından
(`kojo/doodle/CommonColors.scala`). Altmış iki ad var.

**Doğrudan** sütunundaki ✓, o adın `Renkler.` öneki olmadan da
yazılabildiğini gösterir: `boyamaRenginiKur(mavi)` gibi. Öneksiz
yazılamayanlar için `Renkler.turkuaz` demek gerekir.

### Temel renkler

| Türkçe | İngilizce | RGB | Doğrudan |
|---|---|---|---|
| `mavi` | `blue` | `#0000FF` | ✓ |
| `kırmızı` | `red` | `#FF0000` | ✓ |
| `sarı` | `yellow` | `#FFFF00` | ✓ |
| `yeşil` | `green` | `#008000` | ✓ |
| `mor` | `purple` | `#800080` | ✓ |
| `pembe` | `pink` | `#FFC0CB` | ✓ |
| `kahverengi` | `brown` | `#A52A2A` | ✓ |
| `siyah` | `black` | `#000000` | ✓ |
| `beyaz` | `white` | `#FFFFFF` | ✓ |
| `gri` | `gray` | `#808080` | ✓ |
| `koyuGri` | `darkGray` | `#A9A9A9` | ✓ |
| `açıkGri` | `lightGray` | `#D3D3D3` | ✓ |
| `turuncu` | `orange` | `#FFA500` | ✓ |
| `morumsu` | `magenta` | `#FF00FF` | ✓ |
| `camgöbeği` | `cyan` | `#00FFFF` | ✓ |

### Adlandırılmış öbür renkler

| Türkçe | İngilizce | RGB | Doğrudan |
|---|---|---|---|
| `altınbaşak` | `goldenrod` | `#DAA520` |  |
| `altın` | `gold` | `#FFD700` |  |
| `yeşilimsiSarı` | `greenYellow` | `#ADFF2F` |  |
| `zeytin` | `olive` | `#808000` |  |
| `orkidePembesi` | `orchid` | `#DA70D6` |  |
| `somon` | `salmon` | `#FA8072` |  |
| `denizYeşili` | `seaGreen` | `#2E8B57` |  |
| `kurşunMavisi` | `slateBlue` | `#6A5ACD` |  |
| `kurşunGrisi` | `slateGray` | `#708090` |  |
| `turkuaz` | `turquoise` | `#40E0D0` |  |
| `menekşe` | `violet` | `#EE82EE` |  |
| `haki` | `khaki` | `#F0E68C` |  |
| `mercan` | `coral` | `#FF7F50` |  |
| `gökMavisi` | `skyBlue` | `#87CEEB` |  |
| `çelikMavisi` | `steelBlue` | `#4682B4` |  |
| `beyazlatılmışBadem` | `blanchedAlmond` | `#FFEBCD` |  |

### Koyu aile

| Türkçe | İngilizce | RGB | Doğrudan |
|---|---|---|---|
| `koyuMavi` | `darkBlue` | `#00008B` | ✓ |
| `koyuCamgöbeği` | `darkCyan` | `#008B8B` | ✓ |
| `koyuAltınbaşak` | `darkGoldenrod` | `#B8860B` |  |
| `koyuKlasikGri` | `darkGrayClassic` | `#404040` |  |
| `koyuYeşil` | `darkGreen` | `#006400` | ✓ |
| `koyuHaki` | `darkKhaki` | `#BDB76B` |  |
| `koyuMorumsu` | `darkMagenta` | `#8B008B` | ✓ |
| `koyuZeytinYeşili` | `darkOliveGreen` | `#556B2F` |  |
| `koyuTuruncu` | `darkOrange` | `#FF8C00` | ✓ |
| `koyuOrkidePembesi` | `darkOrchid` | `#9932CC` |  |
| `koyuKırmızı` | `darkRed` | `#8B0000` | ✓ |
| `koyuSomon` | `darkSalmon` | `#E9967A` |  |
| `koyuDenizYeşili` | `darkSeaGreen` | `#8FBC8F` |  |
| `koyuKurşunMavisi` | `darkSlateBlue` | `#483D8B` |  |
| `koyuKurşunGrisi` | `darkSlateGray` | `#2F4F4F` |  |
| `koyuTurkuaz` | `darkTurquoise` | `#00CED1` |  |
| `koyuMenekşe` | `darkViolet` | `#9400D3` |  |

### Açık aile

| Türkçe | İngilizce | RGB | Doğrudan |
|---|---|---|---|
| `açıkMavi` | `lightBlue` | `#ADD8E6` |  |
| `açıkMercan` | `lightCoral` | `#F08080` |  |
| `açıkCamgöbeği` | `lightCyan` | `#E0FFFF` |  |
| `açıkAltınbaşakSarısı` | `lightGoldenrodYellow` | `#FAFAD2` |  |
| `açıkYeşil` | `lightGreen` | `#90EE90` |  |
| `açıkPembe` | `lightPink` | `#FFB6C1` |  |
| `açıkSomon` | `lightSalmon` | `#FFA07A` |  |
| `açıkDenizYeşili` | `lightSeaGreen` | `#20B2AA` |  |
| `açıkGökMavisi` | `lightSkyBlue` | `#87CEFA` |  |
| `açıkKurşunGrisi` | `lightSlateGray` | `#778899` |  |
| `açıkÇelikMavisi` | `lightSteelBlue` | `#B0C4DE` |  |
| `açıkSarı` | `lightYellow` | `#FFFFE0` |  |

İki ad daha var, ikisi de rengi olmayan renk: `renksiz` ve eşanlamlısı
`saydam` — saydam siyah, yani `rgba(0, 0, 0, 0)`. İkisi de öneksiz
yazılabilir.

`koyuMor` adı da çalışır ama **eskimiştir** (*deprecated*); masaüstü
Koco'yla aynı ad olan `koyuMorumsu` kullanılmalı.

Renk üstünde çalışan yöntemler: `soluk(oran)` ve `belirgin(oran)`
saydamlığı azaltıp artırır, `çevir(açı)` rengi renk çemberinde döndürür,
`dahaAçıkYap(açıklık)` ve `dahaKoyuYap(koyuluk)` da adları gibi.


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
