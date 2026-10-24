Keyifli Alıştırmalar · Koco cildi
====

[`alistirma/`](../alistirma/) içindeki C++ cildinin kardeşi: Koco kitapçığına
(*Programlamaya ve Algoritmalara Keyifli ve İşlevsel Bir Giriş*,
[`kitapcik-koco/`](../kitapcik-koco/)) eşlik eden alıştırma defteri. Aynı
düzen: her konuda dört basamak (Isınma / Alıştırma / Zorlayıcı / Keşif), her
konunun başında yanıt yerine ders notlarına ve kitapçığa bağlantılar.
Çözüm yok; ipucu var.

Alıştırmalar [iKojo](https://ikojo.fly.dev/)'da ya da masaüstü Koco'da çalışır.
İki tür alıştırma var:

+ **Çizenler:** başlangıç dosyasını yapıştırıp çalıştırın; defterdeki
  "Tuvalde:" satırı ne görmeniz gerektiğini söylüyor. Beklenen çıktıları yok.
+ **Konsola yazanlar:** `beklenen-cikti` var; çıktı penceresindekiyle satır
  satır karşılaştırın. Kap ve İkil gösterimi ortama göre değiştiğinden
  (iKojo `List(1, 2)` / `true`, Koco `Dizin(1, 2)` / `doğru`) alıştırmalar
  kapları `yazıYap` ile, İkil'leri `evet/hayır` ile yazdırıyor.

Bölümler
--

| | Bölüm | Konu | Alıştırma |
|---|---|---|---|
| Hazırlık | [iKojo'da, hiçbir şey yüklemeden](https://bulent2k2.github.io/cpp_ogreniyoruz/alistirma-koco/00-hazirlik.html) ([kaynak](bolumler/00-hazirlik.html)) | 1 | 5 |
| I | [Kaplumbağayla İlk Adımlar](https://bulent2k2.github.io/cpp_ogreniyoruz/alistirma-koco/01-ilk-adimlar.html) ([kaynak](bolumler/01-ilk-adimlar.html)) | 4 | 19 |
| II | [Veriyi Düzenlemek](https://bulent2k2.github.io/cpp_ogreniyoruz/alistirma-koco/02-veri.html) ([kaynak](bolumler/02-veri.html)) | 4 | 19 |
| III | [Soyutlama Sanatı](https://bulent2k2.github.io/cpp_ogreniyoruz/alistirma-koco/03-soyutlama.html) ([kaynak](bolumler/03-soyutlama.html)) | 4 | 18 |
| IV | [Özyineleme ve Fraktallar](https://bulent2k2.github.io/cpp_ogreniyoruz/alistirma-koco/04-ozyineleme.html) ([kaynak](bolumler/04-ozyineleme.html)) | 4 | 18 |
| V | [Çizgeler ve Gezintiler](https://bulent2k2.github.io/cpp_ogreniyoruz/alistirma-koco/05-cizgeler.html) ([kaynak](bolumler/05-cizgeler.html)) | 4 | 18 |
| VI | [Dinamik Programlama](https://bulent2k2.github.io/cpp_ogreniyoruz/alistirma-koco/06-dp.html) ([kaynak](bolumler/06-dp.html)) | 4 | 19 |

Bağlantısı olan herkes sayfaları açabilir; aynı sayfalar GitHub Pages aynasında:
[bulent2k2.github.io/cpp_ogreniyoruz/alistirma-koco/](https://bulent2k2.github.io/cpp_ogreniyoruz/alistirma-koco/00-hazirlik.html).
Adresler `baglantilar.txt`'de, `yap.py` ilk adresi bölümler arası gezinmeye
yerleştiriyor.

Basılı ve e-kitap
--

Defterin tamamı tek dosyada da duruyor; tıklayınca iner:

+ [PDF](https://raw.githubusercontent.com/bulent2k2/cpp_ogreniyoruz/main/kitap/Keyifli-Alistirmalar-Koco.pdf) &mdash; A4'e basılmak üzere
  düzenlendi. Kâğıtta tıklanacak bir şey olmadığı için üç kademeli ipuçları
  (Düşünce / Yaklaşım / İlk satır) açık basılır: takılmadan okumayın, bir
  kâğıtla örtün. Çevrimiçi sayfada ipuçları kapalı gelir, tıklayınca açılır.
+ [EPUB](https://raw.githubusercontent.com/bulent2k2/cpp_ogreniyoruz/main/kitap/Keyifli-Alistirmalar-Koco.epub) &mdash; telefon, tablet ve
  e-kitap okuyucular için; ipuçları orada da açık kutular.

Kitapçıktaki gibi yeniden üretmek için `make pdf epub` (araçlar için
[`../kitapcik/yapim.md`](../kitapcik/yapim.md)); kapak resmi `make kapak`.

Dizin yapısı
--

+ `bolumler/*.html` — bölüm metinleri; `yap.py` ile `cikti/`'ya üretilir
  (biçem: `../kitapcik/ortak.css` + `../alistirma/ek.css` +
  `../kitapcik-koco/ek.css` + `ek.css`).
+ `kod/<id>/` — her alıştırmanın dizini: `ana.kojo` başlangıç dosyası, varsa
  `girdi` (oyun alıştırmaları `satıroku` ile okur) ve `beklenen-cikti`.
  Kimlikler C++ cildininkilerden `K` ile ayrılıyor: `KI-3-A1` = Koco, Bölüm I,
  3. konu, 1. Alıştırma.
+ `konsol/` — konsol alıştırmalarını makinede sınayan düzenek: Koco'nun Türkçe
  anahtar sözcüklü Scala derleyicisi ve Türkçe API'nin standart kütüphaneyle
  çalışan parçaları. `./kur.sh` bir kere, sonra `make -C kod test`. Ayrıntısı
  [`konsol/README.md`](konsol/README.md). Beklenen çıktılar bu düzenekle
  üretildi; kitapçığın konsol örneklerini birebir veriyor.

Bazı başlangıç dosyaları bilerek derlenmiyor ya da bitmiyor (`KI-2-Z1` değişmezi
değiştiriyor; `KI-4-A1` ve `KI-4-Z2`'nin döngüleri siz bitirene kadar
dönüyor). Süre ölçen iki alıştırmanın (`KIII-4-A1`, `KIII-4-Z1`) beklenen
çıktısı yok: kendi sayılarınızı üretin. Koco'da `üst`, `son`, `yeni`, `bu`,
`dene`, `doğru`, `yanlış` gibi sözcükler
anahtar sözcük olduğu için ad olarak kullanılamaz; takıldığınız yerde
derleyicinin iletisini okuyun, defter de o yerlerde uyarıyor.

Lisans
--

Metin CC BY-SA 4.0, kod MIT; bkz. kök dizindeki [LICENSE](../LICENSE).
