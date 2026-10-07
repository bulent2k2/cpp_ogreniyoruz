Kitapçığın yapımı
==================

Kitapçığı yeniden üretmek, bölüm eklemek ya da betiklerini kurcalamak
isteyenler için: kaynak dosyaların düzeni, gerekli araçlar, yapım adımları
ve iki küçük yardımcı. Kitapçığın kendisi ve okuma bağlantıları
[README](README.md) dosyasında.


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

Kod bloklarındaki &ldquo;Hepsini seç&rdquo; düğmesi
--

Kod bloklarının sağ üst köşesinde bir düğme var: tıklayınca bloğun tamamını
seçip panoya kopyalıyor, örneği çevrimiçi bir derleyiciye yapıştırmak kolay
olsun diye. Kodu `kopyala.js` içinde; `yap.py` sayfaların içine gömüyor,
`epub.py` de EPUB paketine dosya olarak koyuyor.

Yapıştırılacak bir betik olmayan bloklar düğme almıyor: program çıktısı,
uçbirim dökümü, derleyici hatası, izleme, tümevarım formülü. Bunlar
`<figure class="kod kopyalanmaz">` diye işaretli &mdash; **yeni bir çıktı bloğu
yazarken sınıfı koymayı unutmayın.** Eskiden başlıktaki ada (`çıktı`)
bakılıyordu; adlar çeşitlenince (`terminal`, `izleme`, `çalışırken`,
`tümevarım`, `derleyici` ...) eleme sessizce eskiyordu.

Düğme HTML'e yazılmıyor, betik ekliyor. Böylece betiğin çalışmadığı yerde ölü
bir düğme görünmüyor: baskıda `ortak.css` zaten gizliyor, betik çalıştırmayan
e-kitap okuyucularında ise düğme hiç oluşmuyor. Kâğıtta panosu olmadığı için
PDF'te düğme yok. Aynı düğme Koco kitapçığında da var; betik ikisi için ortak.

Çevrimiçi sayfa ile kaynak ayrışırsa
--

Bir bölüm çevrimiçi sayfada düzeltilip yeniden yayımlanır ama kaynak dosya
depoya işlenmezse PDF ile EPUB geride kalır (bir kere oldu). `geri_al.py`
yayımlanan sayfayı alıp `yap.py`'nin dönüşümlerini tersine çevirir ve kaynakla
karşılaştırır; resimleri bayt bayt denetler:

```bash
# sayfayı tarayıcıdan kaydedin (ya da artifact'in ham HTML'ini alın), sonra:
python3 kitapcik/geri_al.py kitapcik 02-veri ~/indirilen/sayfa.html         # farkı göster
python3 kitapcik/geri_al.py kitapcik 02-veri ~/indirilen/sayfa.html --yaz   # kaynağı sayfaya eşitle
```

Çıkış kodu 0 ise aynı, 1 ise farklı. Aynı betik Koco kitapçığı için de
çalışır: ilk bağımsız değişkeni `kitapcik-koco` yapın.
