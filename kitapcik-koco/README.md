Programlamaya ve Algoritmalara Keyifli ve İşlevsel Bir Giriş
====

[`kitapcik/`](../kitapcik/) içindeki *Keyifli Bir Başlangıç*'ın kardeşi:
aynı kavramlar, bu sefer yalnızca [Koco](https://sites.google.com/view/koco-surum)
(Kojo'nun Türkçe sürümü) ve Scala ile. Kurulum istemeyenler örnekleri
tarayıcıda, Türkçe [iKojo](https://ikojo.fly.dev/) üzerinde çalıştırabilir.
Bölümler bilerek paralel kuruldu; iki kitapçık yan yana okunmak için yazıldı.

**Durum: ilk taslak.** Kod örnekleri **Türkçe anahtar sözcüklerle**
(`tanım`, `dez`, `den`, `eğer`, `yoksa`, `eşle`, `durum`, `tür`&hellip;)
yazıldı ve Koco'nun yamalı Scala derleyicisiyle (`bulent2k2/kojo` deposundaki
`scala-tr/build/pack/lib` jar'ları, 2.13.18) **derlenip çalıştırılarak
doğrulandı**: konsol örneklerinin kitapçıktaki çıktıları gerçek çıktılardır.
Kaplumbağa (çizim) örnekleri ise çevrimiçi
[iKojo](https://ikojo.fly.dev/) üzerinde tek tek çalıştırıldı; kitapçıktaki
çizim görselleri (`kitapcik/resim/koco-*.png`) o çıktıların ekran
görüntüleridir.
Komut/tür/yöntem adları Kojo kaynak kodundaki Türkçe API'den (`trInit.scala`
ve `tr/` dosyaları) birebir alındı; doğrulama hem `litan/kojo`'daki hem de
`bulent2k2/kojo`'daki (güncel) `tr/` dosyalarıyla ayrı ayrı yapıldı, ikisi de
aynı sonuçları verdi.

Kitapçığı okumak
--

**PDF (A4'e basmaya hazır):**
[kitap/Programlamaya-ve-Algoritmalara-Keyifli-ve-Islevsel-Bir-Giris.pdf](../kitap/Programlamaya-ve-Algoritmalara-Keyifli-ve-Islevsel-Bir-Giris.pdf)

**EPUB (telefon, tablet, e-kitap okuyucu):**
[kitap/Programlamaya-ve-Algoritmalara-Keyifli-ve-Islevsel-Bir-Giris.epub](../kitap/Programlamaya-ve-Algoritmalara-Keyifli-ve-Islevsel-Bir-Giris.epub)

Çevrimiçi bölümler
--

Kitapçık bölüm bölüm çevrimiçi sayfalar hâlinde de yayımlandı. Bağlantısı
olan herkes açabilir; telefondan okumak için elverişli. Her bölümün başındaki
şeritten kılavuza ve öbür bölümlere geçilebilir:

+ [Kapak ve kılavuz](https://claude.ai/code/artifact/ce43da09-9f13-46ae-bb18-57ba0bda0702) Koco nedir, kurulum, çalışma yöntemi, içindekiler
+ [I. İlk Adımlar](https://claude.ai/code/artifact/6a819623-8348-459b-8314-e9d143bf14a3) kaplumbağa komutları; değer, tür, işlev; tahmin oyunu
+ [II. Veriyi Düzenlemek](https://claude.ai/code/artifact/48f70cc7-3678-466e-8d71-7948182564ec) dizin, küme, eşlem; `işle`, `ele`, `indirge`; `Belki`
+ [III. Soyutlama Sanatı](https://claude.ai/code/artifact/1bff2e2b-9d1a-435e-901e-974e6acced99) işlevi girdi alan işlevler; `belirt` ile sınama; ölçme
+ [IV. Özyineleme ve Fraktallar](https://claude.ai/code/artifact/7d214fb0-5fd4-4074-a4ab-fe8ca99820dd) sarmal, ağaç, Koch tanesi; Hanoi; bellekle hızlandırma
+ [V. Çizgeler ve Gezintiler](https://claude.ai/code/artifact/d5817874-92b1-4750-a267-d646b4f7bf8c) işlevsel derinlemesine/enlemesine gezi, bağlı parçalar
+ [VI. Dinamik Programlama](https://claude.ai/code/artifact/cc64eaea-0d24-493a-a94d-b0cda5eb4cb9) ızgara yolları, bozuk para; Mandelbrot; yola devam

Adresler `baglantilar.txt` dosyasında; `yap.py` bunları bölümler arası
bağlantılara yerleştiriyor.


Gerekli araçlar
--

Kitapçığı yeniden üretmek için üç araç gerekiyor: **Python 3.10+**
(`yap.py`, `epub.py`), **Node.js 18+** ve **Playwright + Chromium**
(`pdf.mjs`, `kapak.mjs`). Playwright'ı depo kökünde bir kere kurmak
yeterli; betikler onu önce yerel `node_modules`'tan, bulamazsa bilinen
konumlardan arar.

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

Yazı tipleri (Bitter, IBM Plex Sans, IBM Plex Mono) `../kitapcik/yazitipi/`
dizininde, depoda duruyor; PDF ve kapak onları yerelden okur. Ağ bağlantısı
gerekmez, çıktı her makinede aynı olur. Çevrimiçi yayımlanan sayfalar ise
Google Fonts'u kullanmaya devam eder.

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

`baglantilar.txt` yayımlanan bölümlerin adreslerini tutuyor; biçimi kardeş
kitapçıktakiyle aynı, `yap.py` bunları bölümler arası bağlantılara
yerleştiriyor.

Bir bölüm çevrimiçi sayfada düzeltilip kaynağa işlenmezse PDF ile EPUB geride
kalır; kardeş kitapçıktaki `../kitapcik/geri_al.py` sayfayı kaynakla
karşılaştırır ve istenirse eşitler:

```bash
python3 kitapcik/geri_al.py kitapcik-koco 01-ilk-adimlar ~/indirilen/sayfa.html --yaz
```

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
