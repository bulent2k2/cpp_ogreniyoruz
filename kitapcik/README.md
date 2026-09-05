Programlamaya ve Algoritmalara Keyifli Bir Başlangıç
====

İki dönemlik ders notlarımızdan damıtılmış, altı bölümlük bir giriş kitapçığı.
Amacı öğrencilere programlamayı anlatmak değil, kendi kendilerine
öğrenebileceklerini &mdash; ama ikili üçlü küçük takımlarla daha hızlı yol
alacaklarını &mdash; hissettirmek.

Kitapçığı okumak
--

**PDF (64 sayfa, A4'e basmaya hazır):**
[kitap/Programlamaya-ve-Algoritmalara-Keyifli-Bir-Baslangic.pdf](../kitap/Programlamaya-ve-Algoritmalara-Keyifli-Bir-Baslangic.pdf)

**EPUB (telefon, tablet, e-kitap okuyucu):**
[kitap/Programlamaya-ve-Algoritmalara-Keyifli-Bir-Baslangic.epub](../kitap/Programlamaya-ve-Algoritmalara-Keyifli-Bir-Baslangic.epub)

İkisi de bu depoda duruyor; herkes indirip okuyabilir, basabilir.

Çevrimiçi bölümler
--

Kitapçık bölüm bölüm çevrimiçi sayfalar hâlinde de yayımlandı. Bağlantısı
olan herkes açabilir; telefondan okumak için elverişli. Ders sırasında hızlıca
bir bölüme bakmak isteyenler için:

+ [Kapak ve kılavuz](https://claude.ai/code/artifact/5636245b-1b09-4b69-be33-a0cf21566a63) nasıl çalışalım, ikili programlama, tezgâh kurulumu
+ [I. İlk Adımlar](https://claude.ai/code/artifact/8f21bd01-d69e-4e83-bb53-60b5d594e4f7) değer, değişken, tür, işlev; taşma; kapsam; sayı tahmin oyunu
+ [II. Veriyi Düzenlemek](https://claude.ai/code/artifact/998f8f77-ca22-4e95-83a3-bbc71464b43f) dizi, eşlem, küme, yığın, kuyruk; kendi türlerimiz; kalıplar
+ [III. Programcının Zanaatı](https://claude.ai/code/artifact/6a403229-5395-4258-adc4-496f5c79a5a1) derleme, `make`, altın dosya testleri, `gdb`, hız ölçümü
+ [IV. Özyineleme ve Arama](https://claude.ai/code/artifact/baab8280-db12-4152-8fba-702522ffdeff) Hanoi, memoizasyon, geri dönüşlü arama, sekiz vezir, budama
+ [V. Çizgeler ve Gezintiler](https://claude.ai/code/artifact/011ec142-ce1d-4a00-9c0a-2b37b47054cc) derinlemesine/enlemesine gezi, Dijkstra, Floyd&ndash;Warshall, Bellman&ndash;Ford
+ [VI. Dinamik Programlama](https://claude.ai/code/artifact/82baa360-2ba8-4f7e-b3a9-68a7c3705aeb) beş adımlık reçete, ızgara yolları, bozuk para soruları

Resimler
--

`resim/` dizinindeki görseller kitapçığın son bölümünde, &ldquo;Yola devam&rdquo;
başlığı altında kullanılıyor: Koch tanesi (özyineleme), Mandelbrot kümesi
(karmaşık sayılar), çokgen çerçeve ve üç cisim probleminin üç ayrı
çalıştırması. Hepsi Koco ortamında yazılmış programların çıktısı.

Bölüm metinlerinde `../resim/<ad>` diye anılıyorlar. Bu yol PDF için
doğrudan çalışıyor; `yap.py` tek başına yayımlanan sayfalarda onları data
URI olarak gömüyor, `epub.py` de EPUB paketinin içine `resim/` altına
kopyalayıp bildirime ekliyor.

Kapaktaki kolaj ise `ileri/dersler/resim/` dizinindeki, derste elle çizilmiş
çizge şekillerinden oluşuyor. Aynı kapak üç yerde birden görünüyor: PDF'in ilk
sayfası, EPUB'ın kapağı ve çevrimiçi kapak sayfasının başındaki görsel. Bu
sonuncusu yalnızca ekran içindir; baskıda ve EPUB'da gizlenir, çünkü oralarda
kapak zaten var.

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


Gerekli araçlar
--

Kitapçığı yeniden üretmek için üç araç gerekiyor: **Python 3.10+**
(`yap.py`, `epub.py`), **Node.js 18+** ve **Playwright + Chromium**
(`pdf.mjs`, `kapak.mjs`). Playwright'ı depo kökünde bir kere kurmak
yeterli; betikler onu önce yerel `node_modules`'tan, bulamazsa bilinen
konumlardan arar.

Yazı tipleri (Bitter, IBM Plex Sans, IBM Plex Mono) `yazitipi/` dizininde,
depoda duruyor; PDF ve kapak onları yerelden okur, ağ bağlantısı gerekmez ve
çıktı her makinede aynı olur. (Eskiden Google Fonts'tan yükleniyordu; ağ
yoksa Chromium sessizce sistem yazı tipine düşüyor, PDF başka görünüyordu.)
Çevrimiçi yayımlanan sayfalar Google Fonts'u kullanmaya devam eder. Yazı
tiplerini yenilemek gerekirse `python3 kitapcik/yazitipi/indir.py`.

**macOS** ([Homebrew](https://brew.sh) ile):

```bash
brew install python3 node
cd <depo-kökü>
npm install playwright
npx playwright install chromium
```

**Windows** (PowerShell; `winget` yerine [python.org](https://python.org) ve
[nodejs.org](https://nodejs.org) kurucuları da olur):

```powershell
winget install Python.Python.3.12 OpenJS.NodeJS.LTS
cd <depo-kökü>
npm install playwright
npx playwright install chromium
```

**Linux** (Debian/Ubuntu):

```bash
sudo apt install python3 nodejs npm
cd <depo-kökü>
npm install playwright
npx playwright install chromium
npx playwright install-deps chromium   # tarayıcının sistem bağımlılıkları
```

EPUB doğrulaması için (isteğe bağlı): `pip install epubcheck`.
`npm install`'ın depo köküne bıraktığı `node_modules/`, `package.json` ve
`package-lock.json` sürüm denetiminin dışındadır (`.gitignore`).

Kitapçığı yeniden yapmak
--

Bölümlerin metni `bolumler/*.html` dosyalarında (yalnızca gövde), ortak biçem
`ortak.css` içinde. `yap.py` ikisini birleştirip iki çıktı üretiyor:

+ `cikti/<bölüm>.html` &mdash; her biri tek başına yayımlanabilir sayfa
+ `cikti/kitapcik-tam.html` &mdash; hepsi bir arada, PDF için

```bash
cd kitapcik
make            # html + pdf + epub
make html       # yalnızca cikti/*.html
make pdf        # yalnızca PDF
make epub       # yalnızca EPUB
make denetle    # epubcheck ile doğrula
```

Betikleri tek tek de çağırabilirsiniz:

```bash
python3 kitapcik/yap.py     # html'leri üret
node kitapcik/pdf.mjs       # PDF'i üret  (kitap/ dizinine yazar)
python3 kitapcik/epub.py    # EPUB'ı üret (kitap/ dizinine yazar)
```

EPUB için ayrı bir biçem dosyası var (`epub.css`): e-kitap okuyucularda
akışkan olsun diye ızgara düzeni ve kareli defter zemini yok, kod blokları
da açık zeminli. Kapak resmi (`kitap/kapak.png`) `kapak-tasarim.html` sayfasının ekran
görüntüsü; yeniden üretmek için `node kitapcik/kapak.mjs`. Kapaktaki kolaj
`ileri/dersler/resim/` dizinindeki, derste elle çizilmiş çizge şekillerinden
oluşuyor. Aynı kapak PDF'in de ilk sayfası.

Üretilen EPUB, `epubcheck` doğrulamasını hatasız ve uyarısız geçiyor:

```bash
pip install epubcheck
python3 -m epubcheck kitap/Programlamaya-ve-Algoritmalara-Keyifli-Bir-Baslangic.epub
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

Lisans
--

Kitapçığın **metni** [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/deed.tr),
içindeki **örnek programlar** MIT lisansı altında. Ayrıntılar ve depodaki
üçüncü taraf malzemenin dökümü kök dizindeki [LICENSE](../LICENSE) dosyasında.
