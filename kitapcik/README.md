Programlamaya ve Algoritmalara Keyifli Bir Başlangıç
====

İki dönemlik ders notlarımızdan damıtılmış, altı bölümlük bir giriş kitapçığı.
Amacı öğrencilere programlamayı anlatmak değil, kendi kendilerine
öğrenebileceklerini &mdash; ama ikili üçlü küçük takımlarla daha hızlı yol
alacaklarını &mdash; hissettirmek.

Kitapçığı okumak
--

**PDF (63 sayfa, A4):**
[kitap/Programlamaya-ve-Algoritmalara-Keyifli-Bir-Baslangic.pdf](../kitap/Programlamaya-ve-Algoritmalara-Keyifli-Bir-Baslangic.pdf)

**Çevrimiçi bölümler:**

+ [Kapak ve kılavuz](https://claude.ai/code/artifact/5636245b-1b09-4b69-be33-a0cf21566a63) nasıl çalışalım, ikili programlama, tezgâh kurulumu
+ [I. İlk Adımlar](https://claude.ai/code/artifact/8f21bd01-d69e-4e83-bb53-60b5d594e4f7) değer, değişken, tür, işlev; taşma; kapsam; sayı tahmin oyunu
+ [II. Veriyi Düzenlemek](https://claude.ai/code/artifact/998f8f77-ca22-4e95-83a3-bbc71464b43f) dizi, eşlem, küme, yığın, kuyruk; kendi türlerimiz; kalıplar
+ [III. Programcının Zanaatı](https://claude.ai/code/artifact/6a403229-5395-4258-adc4-496f5c79a5a1) derleme, `make`, altın dosya testleri, `gdb`, hız ölçümü
+ [IV. Özyineleme ve Arama](https://claude.ai/code/artifact/baab8280-db12-4152-8fba-702522ffdeff) Hanoi, memoizasyon, geri dönüşlü arama, sekiz vezir, budama
+ [V. Çizgeler ve Gezintiler](https://claude.ai/code/artifact/011ec142-ce1d-4a00-9c0a-2b37b47054cc) derinlemesine/enlemesine gezi, Dijkstra, Floyd&ndash;Warshall, Bellman&ndash;Ford
+ [VI. Dinamik Programlama](https://claude.ai/code/artifact/82baa360-2ba8-4f7e-b3a9-68a7c3705aeb) beş adımlık reçete, ızgara yolları, bozuk para soruları

Örnek programlar
--

`kod/` dizinindeki **24 programın hepsi derlenip çalıştırıldı**; kitapçıktaki
çıktılar gerçek çıktılardır. Hepsini bir kerede sınamak için:

```bash
cd kitapcik/kod
make          # hepsini derle
make calistir # girdi istemeyenleri çalıştır
make temizle
```

`kod/asal-projesi/` ise kitapçığın üçüncü bölümünde anlatılan çok dosyalı
proje düzeninin çalışan hâli: `Makefile` + başlık dosyası + `assert`
denemeleri + altın dosya testi.

```bash
cd kitapcik/kod/asal-projesi
make        # derle ve çalıştır
make test   # altın dosyayla karşılaştır
make temizle
```

Kitapçığı yeniden yapmak
--

Bölümlerin metni `bolumler/*.html` dosyalarında (yalnızca gövde), ortak biçem
`ortak.css` içinde. `yap.py` ikisini birleştirip iki çıktı üretiyor:

+ `cikti/<bölüm>.html` &mdash; her biri tek başına yayımlanabilir sayfa
+ `cikti/kitapcik-tam.html` &mdash; hepsi bir arada, PDF için

```bash
python3 kitapcik/yap.py     # html'leri üret
node kitapcik/pdf.mjs       # PDF'i üret (kitap/ dizinine yazar)
```

`baglantilar.txt` yayımlanan bölümlerin adreslerini tutuyor; `yap.py` bunları
bölümler arası bağlantılara yerleştiriyor. Bölüm eklerseniz `yap.py` içindeki
`BOLUMLER` listesine de eklemeyi unutmayın.

Yazarken dikkat edilenler
--

+ **Alıştırmaların çözümü verilmedi.** Ders notlarındaki gibi, ipucu var ama
  yanıt yok. `ileri/dp/README.md` içinde yarım bırakılmış `bul2()` işlevi
  kitapçıkta da yarım duruyor &mdash; kasıtlı.
+ **Öğrenci adları kullanılmadı.** Ders notlarında geçen adlar yerine
  &ldquo;bir arkadaşınız&rdquo;, &ldquo;sınıftan biri&rdquo; dendi.
+ **Bütün kod çıktıları gerçek.** Uydurma çıktı yok; her biri bu depoda
  derlenip çalıştırıldı.
