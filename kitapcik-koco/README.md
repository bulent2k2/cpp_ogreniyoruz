Programlamaya ve Algoritmalara Keyifli ve İşlevsel Bir Giriş
====

[`kitapcik/`](../kitapcik/) içindeki *Keyifli Bir Başlangıç*'ın kardeşi:
aynı kavramlar, bu sefer yalnızca [Koco](https://sites.google.com/view/koco-surum)
(Kojo'nun Türkçe sürümü) ve Scala ile. Bölümler bilerek paralel kuruldu;
iki kitapçık yan yana okunmak için yazıldı.

**Durum: ilk taslak.** Kod örnekleri **Türkçe anahtar sözcüklerle**
(`tanım`, `dez`, `den`, `eğer`, `yoksa`, `eşle`, `durum`, `tür`&hellip;)
yazıldı ve Koco'nun yamalı Scala derleyicisiyle (`bulent2k2/kojo` deposundaki
`scala-tr/build/pack/lib` jar'ları, 2.13.18) **derlenip çalıştırılarak
doğrulandı**: konsol örneklerinin kitapçıktaki çıktıları gerçek çıktılardır.
Kaplumbağa örnekleri aynı derleyiciyle derlendi ama çizimler başsız (GUI'siz)
ortamda görülemediği için görsel doğrulamaları Koco'nun kendisinde yapılmalı.
Komut/tür/yöntem adları Kojo kaynak kodundaki Türkçe API'den (`trInit.scala`
ve `tr/` dosyaları) birebir alındı.

Bölümler
--

| Bölüm | Konu |
|---|---|
| Kılavuz | Koco nedir, kurulum, çalışma yöntemi, içindekiler |
| I. İlk Adımlar | kaplumbağa komutları; değer, tür, işlev; tahmin oyunu |
| II. Veriyi Düzenlemek | dizin, küme, eşlem; `işle`, `ele`, `indirge`; `Belki` |
| III. Soyutlama | işlevi girdi alan işlevler; `belirt` ile sınama; ölçme |
| IV. Özyineleme | sarmal, ağaç, Koch tanesi; Hanoi; bellekle hızlandırma |
| V. Çizgeler | işlevsel derinlemesine/enlemesine gezi, bağlı parçalar |
| VI. Dinamik Programlama | ızgara yolları, bozuk para; Mandelbrot; yola devam |

Kitapçığı yapmak
--

Düzen, biçem ve betikler kardeş kitapçıkla ortak: `yap.py` biçemi
`../kitapcik/ortak.css`'ten okur, üstüne yalnızca vurgu rengini değiştiren
`ek.css`'i ekler. Görseller de `../kitapcik/resim/` içindeki `koco-*`
dosyalarıdır; bu dizinde resim kopyası tutulmaz.

```bash
cd kitapcik-koco
make            # html + pdf + epub
make html       # yalnızca cikti/*.html
make pdf        # kitap/...-Islevsel-Bir-Giris.pdf
make epub       # kitap/...-Islevsel-Bir-Giris.epub
make kapak      # kitap/kapak-koco.png (kapak-tasarim.html'den)
make denetle    # epubcheck ile doğrula
```

`baglantilar.txt` (henüz yok) bölümler çevrimiçi yayımlanınca adreslerini
tutacak; biçimi kardeş kitapçıktakiyle aynı.

Yazarken dikkat edilenler
--

+ **Alıştırmaların çözümü verilmedi.** Mandelbrot'un boyama adımı ve
  Dijkstra'nın Koco çevirisi bilerek okura bırakıldı.
+ **Öğrenci adları kullanılmadı.**
+ **Koco adları kaynaktan doğrulandı.** Komut, tür ve yöntem adları Kojo
  deposundaki Türkçe API tanımlarından (`net/kogics/kojo/lite/i18n/tr*`)
  birebir alındı: `yinele`, `yineleDoğruysa`, `satıryaz`, `sayıOku`,
  `belirt`, `Dizin`, `Küme`, `Eşlem`, `işle`, `ele`, `indirge`,
  `soldanKatla`, `Yığın`, `Kuyruk`, `ÖncelikSırası`, `buSaniye` vb.
  Anahtar sözcükler `scala-tr/turkish-keywords.patch`'ten alındı.
+ **Anahtar sözcük çakışmalarına dikkat.** `gizli`, `dene`, `bu`, `son`,
  `yeni`, `tür`, `yap` gibi sözcükler Koco'da anahtar sözcük olduğu için
  değişken/işlev adı olarak kullanılamaz; kitapçıkta bu yüzden `tutulan`,
  `denemeler`, `şimdiki` gibi adlar seçildi (ikisi metinde ders konusu da
  yapıldı).

Lisans
--

Metin [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/deed.tr),
örnek programlar MIT. Ayrıntılar kök dizindeki [LICENSE](../LICENSE) dosyasında.
