Keyifli Alıştırmalar
====

[Giriş kitapçığının](../kitapcik/README.md) yanına bir alıştırma defteri.
Kitapçığın her bölümünün her konusu için sıra sıra zorlaşan alıştırmalar;
yanıt anahtarı yok, yanıt yerine o tekniği anlatan ders notuna bağlantı var.

Nasıl çalışılır
--

Her konuda aynı merdiven, dört basamak:

+ **Isınma** &mdash; kitapçıktaki örneği çalıştırıp bir satırını değiştirin.
+ **Alıştırma** &mdash; aynı kalıpla yeni, küçük bir iş.
+ **Zorlayıcı** &mdash; iki kavramı birleştiren ya da bir tuzağı olan soru.
+ **Keşif** &mdash; açık uçlu: Project Euler sorusu ya da küçük bir proje.

Her alıştırmanın `kod/` altında kendi dizini var (`kod/I-3-Z2/` gibi):
başlangıç dosyası `ana.cpp`, girdi gerekiyorsa `girdi`, bir de
`beklenen-cikti`. Çözümünüz doğruysa `make test` &ldquo;Doğru!&rdquo; der;
değilse `diff` farkı gösterir. Keşif alıştırmalarının beklenen çıktısı yok.

```bash
cd alistirma/kod/I-3-Z2
make          # derle ve çalıştır
make test     # beklenen çıktıyla karşılaştır
```

Bölüm III'ten itibaren bir terminal gerekir (kitapçığın kapağındaki *Tezgâhınızı kurun*). Ondan öncesi için tarayıcıda çalışıyorsanız ([OnlineGDB](https://www.onlinegdb.com/online_c++_compiler))
`ana.cpp`'yi yapıştırın, `girdi` dosyasının içeriğini *Input* kutusuna yazın,
çıktıyı gözle karşılaştırın.

Bölümler
--

Çevrimiçi sayfalar bağlantısı olan herkese açık; telefondan da okunur. Aynı
sayfalar GitHub Pages aynasında: [bulent2k2.github.io/cpp_ogreniyoruz/alistirma/](https://bulent2k2.github.io/cpp_ogreniyoruz/alistirma/00-hazirlik.html).

| | Bölüm | Konu | Alıştırma |
|---|---|---|---|
| Hazırlık | [Tarayıcıda, hiçbir şey yüklemeden](https://claude.ai/artifact/XKDtPcu8csxWMu6YZULS3A) ([kaynak](bolumler/00-hazirlik.html)) | 3 | 12 |
| I | [İlk Adımlar](https://claude.ai/artifact/Bhazr8dwrYRPikNxW9X9Yv) ([kaynak](bolumler/01-ilk-adimlar.html)) | 6 | 29 |
| II | [Veriyi Düzenlemek](https://claude.ai/artifact/TV31hBhhNsFsufpMdGeb1w) ([kaynak](bolumler/02-veri.html)) | 7 | 35 |
| III | [Programcının Zanaatı](https://claude.ai/artifact/4SQxFr36xx7nHEiqpTWF3S) ([kaynak](bolumler/03-zanaat.html)) | 6 | 25 |
| IV | [Özyineleme ve Arama](https://claude.ai/artifact/1CZqZ1HJC1WQneFCw6qyDJ) ([kaynak](bolumler/04-ozyineleme.html)) | 6 | 29 |
| V | [Çizgeler ve Gezintiler](https://claude.ai/artifact/FJjmyqnb9eYtXs1FC3Hte9) ([kaynak](bolumler/05-cizgeler.html)) | 9 | 40 |
| VI | [Dinamik Programlama](https://claude.ai/artifact/YaxiipjtgYnrsTgEh6EXxC) ([kaynak](bolumler/06-dp.html)) | 6 | 28 |

Bölüm metinleri `bolumler/*.html` dosyalarında, kitapçıkla aynı düzende;
`make html` ile `cikti/` altında yayımlanabilir sayfalar üretilir. Biçem
kardeş kitapçıktan (`../kitapcik/ortak.css`) gelir, `ek.css` yalnızca vurgu
rengini ve basamak rozetlerini ekler. PDF ve EPUB, bölümler çoğalınca.

Yazarken dikkat edilenler
--

+ **Çözüm yok, çıktı var.** Depoda hiçbir alıştırmanın çözümü yok;
  `beklenen-cikti` dosyaları çalıştırılmış gerçek çıktılardır.
+ **Kasıtlı hatalar kasıtlıdır.** Hazırlık'taki &ldquo;Hata iletisini
  okumak&rdquo; dizinlerinin bir kısmı bilerek derlenmez; `make -C kod derle`
  onları &ldquo;derlenmedi&rdquo; diye listeler, sorun değil.
+ **Öğrenci adı yok.** Kitapçıktaki gibi &ldquo;bir arkadaşınız&rdquo;,
  &ldquo;takımınız&rdquo;.

Lisans
--

Metin [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/deed.tr),
kod MIT; ayrıntısı kök dizindeki [LICENSE](../LICENSE) dosyasında.
