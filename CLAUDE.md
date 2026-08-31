# CLAUDE.md

Bu dosya, bu depoda çalışan yapay zeka asistanları (Claude Code vb.) için
yönergeler içerir. Amaç: deponun yapısını hızlıca kavramak ve ders
malzemesinin bütünlüğünü bozmadan katkı yapmak.

## Depo Ne İşe Yarıyor?

`cpp_ogreniyoruz`, bir Fen Lisesi öğrenci grubuna verilen **C++ ve algoritma
dersleri**nin notlarını, örnek kodlarını ve kaynaklarını barındırır. Bir
kütüphane ya da uygulama projesi **değildir**; bir *ders tabanıdır*.

Öne çıkan özellikler:

- **Dil Türkçedir.** Ders notları, kod içindeki yorumlar, değişken/işlev
  isimleri, hatta `make` hedefleri bile Türkçedir (`derle`, `çalıştır`,
  `temizle`). Türkçe karakterler (ç, ğ, ı, ö, ş, ü, İ) hem dosya
  adlarında hem tanımlayıcılarda kullanılır. Dosyalar UTF-8'dir.
- **Öğretim odaklıdır.** Kodların bir kısmı **kasıtlı olarak eksik ya da
  hatalıdır** (öğrenciye alıştırma bırakmak için). Bkz. `baslayalım`
  ("Kasıtlı!") ve `ileri/dp/README.md` içindeki yarım bırakılmış
  `bul2()` işlevi.
- **Çevrimiçi derleyiciler merkezîdir.** Notlar sololearn, onlinegdb,
  coliru bağlantılarıyla örülüdür. Bu bağlantılar içeriğin bir parçasıdır.

## Ders Tabanının Yapısı

### İki ayrı müfredat, iki ayrı adlandırma düzeni

| Dönem | Konu | Dosyalar |
|---|---|---|
| 2024-25 | C++'a giriş (ders 1-23) | `ileri/dersNN.md` (ör. `ileri/ders9.md`) |
| 2025-26 | Algoritmalar / rekabetçi programlama (ders 1-30) | `ileri/dersler/dYYYYMMDD.md` (ör. `ileri/dersler/d20260514.md`) |
| ~2022 | Mustafa Tacettin Hoca'nın algoritma notları (ders 1-10) | `2022/dersN.../` (pdf + cpp) |

**`ileri/icindekiler.md` bu ders tabanının tek gerçek dizinidir.** Her ders
orada numarası ve tek satırlık konu özetiyle listelenir. Kök `README.md` de
ilk on dersi ve genel kaynakları (kitaplar, yarışma siteleri, çevrimiçi
dersler) tanıtır.

### Gezinme (navigation) kuralı

Her ders notu dosyası, **hem ilk hem son satırında** aynı gezinme çubuğunu
taşır:

```markdown
> [Önceki](d20260508.md) [Hepsi](../icindekiler.md) [Sonraki](d20260522.md)
```

Serinin ilkinde `Önceki`, sonuncusunda `Sonraki` yoktur. Yeni bir ders
eklerken zincirin **iki ucunu da** (önceki dersin `Sonraki` bağlantısını ve
yeni dersin `Önceki` bağlantısını) güncellemek zorunludur.

### Diğer dizinler

- `ileri/` — güncel ders notları ve konu yazıları
  (`sınıf-yapı-kavramı.md`, `neden-namespace-kullanırız.md`,
  `yasam-oyunu.md`, `hiz-olcumu.md` ...).
- `ileri/dersler/` — tarihli algoritma dersleri; `resim/` (png görseller),
  `usaco/bronz|gumus/` (USACO soru çözümleri), `dp-sade.md`,
  `floyd-warshall.md`.
- `ileri/dp/` — dinamik programlama: `README.md` (konu anlatımı),
  `dag.cpp`, `ortak_altdiziler/`, `patikalar/`.
- `ileri/generic-containers/` — dizi/bellek/dizin (`vector`, `list`
  benzeri) kalıp örnekleri, `dizin_golden.out` ile testli.
- `ileri/segment-trees/`, `ileri/ai/` — henüz taslak hâlinde konu yazıları.
- `sablon/` — **yeni bir alıştırma dizini için şablon**: `Makefile` +
  `ana.cpp` + `beklenen-cikti`. Yeni bir çalışma dizini açarken buradan
  kopyalayın.
- `e1/`, `e2/`, `e3/`, `gun-sayimi/`, `dogrusal-cebir/` — sınıfta yazılan
  küçük programlar; her biri kendi `Makefile`'ıyla.
- `notlar/` — kopya sayfaları (*cheatsheet*), terminal komutları, çizge
  kuramı, pdf'ler.
- `kitapcik/` — **Giriş kitapçığı** (*Programlamaya ve Algoritmalara Keyifli
  Bir Başlangıç*): `bolumler/*.html` bölüm metinleri, `ortak.css` ekran
  biçemi, `epub.css` e-kitap biçemi, `yap.py` (html), `pdf.mjs` (pdf),
  `epub.py` (epub), `kapak.mjs` (kapak resmi -> `kitap/kapak.png`), `kod/` 24 örnek program.
  Üretilen `cikti/` dizini `.gitignore`'dadır.
- `kitapcik-koco/` — **Koco kitapçığı** (*Programlamaya ve Algoritmalara
  Keyifli ve İşlevsel Bir Giriş*): `kitapcik/`'in Koco (Kojo) + Scala ile
  yazılmış kardeşi. Biçemi `../kitapcik/ortak.css` + `ek.css`'ten,
  görselleri `../kitapcik/resim/`'den alır; kendi `yap.py`, `pdf.mjs`,
  `epub.py`, `kapak.mjs` betikleri vardır. Koddaki Türkçe komut/tür adları
  Kojo'nun Türkçe API'sinden (`TurkishAPI`/`tr` paketinden) gelir;
  uydurma ad eklemeyin.
- `kitap/` — Rekabetçi Programlama El Kitabı (TR ve EN pdf) ve iki
  kitapçığın PDF/EPUB sürümleri ile kapak resimleri.
- `mp4ler/gorsel-kayitlar.md` — derslerin Google Drive video kayıt
  bağlantıları.
- `python/`, `kojo/` — yan diller/ortamlar için giriş yazıları.

## Geliştirme İş Akışları

### Derleme ve çalıştırma

Depo genelinde **tek bir yapı sistemi yoktur**. Her çalışma dizininin kendi
`Makefile`'ı vardır ve tek dosyayı doğrudan `g++` ile derler. Kök dizindeki
`Makefile` yalnızca `ilkProgram.cpp`'yi derler.

İki üslup bir arada yaşıyor:

```make
# Türkçe hedefler (yeni dosyalar; sablon/, gun-sayimi/, dogrusal-cebir/, e3/)
hedef: derle calistir
derle:
	g++ -std=c++23 ana.cpp -o prog

# İngilizce hedefler (eski dosyalar; kök, e1/, e2/, ileri/generic-containers/)
all: build run
$(CODE): $(CODE).cpp
	g++ -std=c++11 $(CODE).cpp -o bin/$@
```

- **Yeni kod için `-std=c++23` kullanın.** Eski dosyalarda `-std=c++11`
  var; onları kendiliğinizden yükseltmeyin (`ders5`-`ders10` notlarındaki
  komut satırlarıyla tutarlı kalmaları gerekiyor).
- Çıktı ikili dosyası ya `prog` ya da `bin/<isim>`'dir.
- `ileri/dp/Makefile` ayrık derleme (`.o` → bağlama) örneğidir;
  `dogrusal-cebir/Makefile` çok dosyalı derleme + başlık bağımlılığı
  örneğidir. Bunlar **ders malzemesidir**, "sadeleştirmek" için
  değiştirmeyin.

### Test etme: altın dosya (*golden file*) karşılaştırması

Tek test yöntemi budur; kurulu bir test çatısı yoktur:

```make
test:
	./prog 1969 09 02 > test-ciktisi
	diff beklenen-cikti test-ciktisi
	rm -rf test-ciktisi
```

Beklenen çıktı dosyalarının adları dizine göre değişir: `beklenen-cikti`
(`sablon/`, `gun-sayimi/`, `dogrusal-cebir/`), `golden` (`e3/`,
`ileri/dp/ortak_altdiziler/`), `<isim>_golden.out`
(`ileri/generic-containers/`). `ileri/dp/patikalar/` ise girdi dosyalarını
(`test1`..`test4`) `./prog < testN` ile besler.

Bir kodu değiştirdiyseniz `make test` çalıştırın; çıktı bilinçli olarak
değiştiyse altın dosyayı da güncelleyin ve bunu commit mesajında belirtin.

Dikkat edilecek iki nokta:

- **Çoğu `test` hedefi derlemeye bağımlı değildir.** `gun-sayimi/` ve
  `sablon/` içinde önce `make derle` (ya da `make`), sonra `make test`
  çalıştırın; yoksa `./prog: not found` alırsınız. Yalnızca
  `dogrusal-cebir/Makefile` `test: derle` bağımlılığını doğru kurar.
- **`gun-sayimi/` testi bugünün tarihine bağlıdır** (doğum gününden bu yana
  geçen günü sayar), bu yüzden `beklenen-cikti` ile farkı normaldir.
  Buradaki `diff` farkını "hata" sanıp altın dosyayı güncellemeyin.

`temizle`/`clean` hedefi her dizinde yoktur (`gun-sayimi/` içinde yok).
Yoksa `prog`, `bin/`, `*.o` ve `test-ciktisi` dosyalarını elle silin.

### Sürüm kontrolü

- Ana dal `main`. Çalışmayı size verilen özellik dalında yapın.
- Commit mesajları kısa ve çoğunlukla Türkçedir ("Ders notları neredeyse
  hazır", "Update d20260508.md").
- `.gitignore` ikili çıktıları dışlar: `*.o`, `bin/`, `**/prog`, `*~`,
  `*.dSYM/`. **Derlenmiş ikili dosya commit etmeyin.**
  (`dogrusal-cebir/prog` `.gitignore`'dan önce eklendiği için hâlâ
  izleniyor — bilinen bir istisna; temizlemek gerekirse önce sahibine
  sorun.)
- Sürekli tümleştirme (CI) yoktur; `.github/` dizini yoktur.

### Lisans

Kök dizindeki `LICENSE` dosyası iki lisans tanımlıyor:

- **Yazılar** (`.md`, `.html`, kitapçık metinleri, kitapçığın PDF ve EPUB
  sürümleri): CC BY-SA 4.0.
- **Kod** (`.cpp`, `.h`, `.py`, `.mjs`, `.css`, `Makefile`): MIT.

Üçüncü taraflara ait malzeme (`kitap/` içindeki el kitapları, `2022/`
dizininin tamamı, `notlar/*.pdf`) bu lisansların **dışındadır**; `LICENSE`
dosyasında tek tek sayılmıştır. Depoya yeni bir dış kaynak eklerseniz o
listeye de ekleyin. Yeni yazdığınız dosyalara ayrı lisans başlığı koymaya
gerek yok; kök `LICENSE` kapsıyor.

## Kod Üslubu

C++ dosyalarında ders malzemesine özgü bir üslup var:

```cpp
using Düğüm = char;                    // node/vertex
using Bağ = std::pair<Düğüm, Uzunluk>; // directed edge
using Çizge = std::map<Düğüm, Bağlar>; // Komşuluk Kümesi

Küme komşular(const Çizge& c, Düğüm d) { ... }
```

- **Tanımlayıcılar Türkçedir**, İngilizce karşılığı yan yorumda verilir
  (`Düğüm // node`, `yaz()`, `bul()`, `dene()`, `gez()`).
- Tür takma adları için hem `using X = ...` (yeni) hem `typedef` (eski)
  görülür; yeni kodda `using` tercih edilir.
- Girinti 2 ya da 4 boşluk — **bulunduğunuz dosyanın düzenine uyun**.
- Bazı dosyalarda `using namespace std;`, bazılarında seçici
  `using std::cout, std::endl;` var. Dosyadaki mevcut tercihi koruyun;
  `neden-namespace-kullanırız.md` bu ayrımı ders konusu yapıyor.
- Testler `assert()`/`dene()` yardımcılarıyla, kodun içinde yazılır.

## Yapay Zeka Asistanları İçin Temel Kurallar

1. **Türkçe yazın.** Ders notu, README, yorum, commit mesajı — hepsi
   Türkçe. İngilizce teknik terimi ilk geçtiğinde parantez içinde ve
   *italik* verin: "özyineleme (*recursion*)", "enlemesine gezi (*BFS*)".
   Yerleşik Türkçe karşılıkları kullanın: dizi (*array*), akıllı dizi
   (*vector*), dizin (*list*), eşlem (*map*), çizge (*graph*), düğüm
   (*node*), yığın (*stack*), kuyruk (*queue*), kütüp (*library*),
   işlev (*function*), kalıp (*template*), tür (*type*).
2. **Hocanın sesini taklit etmeyin, koruyun.** Notlar birinci tekil
   şahısla, öğrencilere hitaben, sıcak bir üslupla yazılmıştır
   ("Bir deneyin isterseniz.", "Çekinmeyin."). Mevcut metni yeniden
   yazmayın; sadece istenen yeri değiştirin.
3. **Alıştırmaların çözümünü kendiliğinizden vermeyin.** Yarım bırakılmış
   işlevler, kasıtlı hatalar ve "size bırakıyorum" denen yerler
   pedagojiktir. Tamamlamanız açıkça istenmedikçe tamamlamayın.
4. **Bağlantıları kırmayın.** Ders notları yoğun biçimde birbirine ve
   çevrimiçi derleyicilere bağlıdır. Dosya taşır ya da yeniden
   adlandırırsanız `ileri/icindekiler.md`, kök `README.md`,
   `mp4ler/gorsel-kayitlar.md` ve komşu derslerin gezinme çubuklarını
   güncelleyin.
5. **Yeni ders eklerken sırayla:** (a) `ileri/dersler/dYYYYMMDD.md`
   dosyasını açın, (b) baş ve son gezinme çubuklarını koyun, (c) bir
   önceki dersin `Sonraki` bağlantısını ekleyin, (d)
   `ileri/icindekiler.md`'ye numaralı satırı ekleyin, (e) görsel kayıt
   varsa `mp4ler/gorsel-kayitlar.md`'ye işleyin.
6. **Yeni alıştırma dizini açarken `sablon/`'u kopyalayın**
   (`Makefile` + `ana.cpp` + `beklenen-cikti`), Türkçe `make` hedeflerini
   ve `-std=c++23`'ü koruyun.
7. **Derlenebilirliği doğrulayın.** Bir `.cpp` dosyasına dokunduysanız o
   dizinde `make` (ve varsa `make test`) çalıştırın. Yalnızca `.md`
   değiştirdiyseniz derlemeye gerek yok.
8. **Kişisel bilgi eklemeyin.** Notlarda öğrenci adları geçiyor; yeni
   isim, e-posta, telefon ya da WhatsApp bilgisi eklemeyin.
9. **Büyük ikili dosya eklemeyin.** pdf, mp4, png yalnızca gerçekten
   gerekliyse ve doğru dizine (`kitap/`, `notlar/`,
   `ileri/dersler/resim/`) konur.
10. **Markdown düzenine uyun.** Başlıklar `#` yerine alt çizgi biçimiyle
    yazılır (`Başlık` altına `====` ya da `--`), satır sonu iki boşlukla
    kırılır, kod blokları ```` ```c++ ```` ile etiketlenir.
