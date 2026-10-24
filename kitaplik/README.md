Keyifli Kitaplık
====

İki kitapçığı, iki alıştırma defterini ve ders notlarını bir bütün olarak
sunan üç sayfa:

+ [Keyifli Kitaplık](https://bulent2k2.github.io/cpp_ogreniyoruz/)
  neden yazıldı, neler sunuyor, bölüm haritası; altı okur tipi için (hiç
  programlamamış, Python ya da C bilen, geçen yıl C++ alan, bu yıl algoritma
  alan, öğretmen) nereden başlanır, nasıl çalışılır.
+ [Keyifli Kavram Dizini](https://bulent2k2.github.io/cpp_ogreniyoruz/dizin.html)
  300 kavram A'dan Z'ye, Türkçe ve İngilizce adlarıyla; her kavramda onu
  anlatan kitapçık bölümü, onu çalıştıran alıştırmalar ve ders notu. "English
  A–Z" düğmesiyle İngilizce sıraya geçer; alıştırma bağlantıları doğrudan
  soruya, kitapçık bağlantıları altbölümün başlığına iner.
+ [Keyifli Kitaplık İncelemesi](https://bulent2k2.github.io/cpp_ogreniyoruz/inceleme.html)
  pedagog, editör ve bilgisayar uzmanı gözüyle eksikler, öneriler ve yerini
  söyleyen düzeltme listesi.

Üçü de, dört eserin bütün bölümleriyle birlikte, GitHub Pages'ten sunulur; kaynağı
depodaki `docs/` dizinidir. Aynı sayfalar claude.ai'de de yayımlı
([Kitaplık](https://claude.ai/artifact/2HmYGoMWQRpLJ6siGq7qxY),
[dizin](https://claude.ai/artifact/6eAAQywvrczgppTggZMNHT),
[inceleme](https://claude.ai/artifact/Kcz4QboYQ7KUwpkNi1T1GW)); iki adres aynı
içeriği taşır, biri açılmazsa öteki.

Dosyalar
--

`kitaplik.html`, `dizin.html` (verisi `dizin-veri.js`) ve `inceleme.html`
yayımlanan sayfaların kaynağıdır. Kitapçıkların `bolumler/` dosyaları gibi
bunlar da `<title>` ve `<style>` ile başlar; `<html>`, `<head>` ve `<body>`
sarmalayıcısı yayım sırasında eklenir. Yayım adresleri `baglantilar.txt`'de.

Sayfaları yerelde açmak ya da başka bir yerde yayımlamak için:

```sh
python3 yap.py    # cikti/kitaplik.html, cikti/dizin.html, cikti/inceleme.html
```

`cikti/` dizini `.gitignore`'dadır.

GitHub Pages aynası
--

`ayna.py` dört eserin bölümlerini (her eserin kendi `yap.py`'sini çağırarak) ve
bu üç sayfayı tam HTML olarak depo kökündeki `docs/` dizinine yazar:

```sh
make ayna         # python3 ayna.py -> ../docs/
```

Aynada bölümler arası bağlantılar claude.ai adresleri yerine göreli yollara gider
(`baglantilar.txt`'deki ilk sütundan `docs/` içindeki dosyaya); resimler gömülmez,
deponun ham GitHub adresinden okunur. Betik bitince göreli bağlantıları ve
`#çapa`ları denetler; kırık varsa adlarını basar ve 1 ile çıkar.

`docs/` üretilmiş dosyadır ve depoya işlenir (GitHub Pages oradan sunar); elle
düzenlemeyin, kaynağı değiştirip `make ayna` deyin ve `docs/`'u da commit edin.
Sayfaların adresi `baglantilar.txt` dosyalarının ikinci sütununda. Ayrıntı:
`../kitapcik/yapim.md`, "GitHub Pages aynası".

Dizine kavram eklemek
--

`dizin-veri.js` içindeki `girdiler` listesine bir satır ekleyin; biçim
dosyanın başında anlatılıyor: Türkçe ad, İngilizce ad, bir cümlelik
açıklama, alan, kitapçık bölümleri, alıştırma kimlikleri ve ders notları.
Alıştırma kimlikleri (`IV-3-Z1`, `KII-2-A1`) defterlerdeki `section id`
değerleriyle aynı olmalı; sayfa bağlantıyı bu kimlikten kurar. Kitapçık
altbölümü `"I|Değer, ad, tür|deger-ad-tur"` biçiminde yazılır: üçüncü parça,
yayımlanan bölüm sayfasındaki başlık kimliğidir (`kitapcik*/cikti/*.html`
içindeki `h2`/`h3` `id`'si; `yap.py` başlıktan türetir) ve bağlantıyı
altbölümün başlığına indirir; boş bırakılırsa bağlantı bölümün başına gider.
`"S"` bölüm kodu Küçük Sözlük sayfasıdır. Sıralama ve harf gruplama sayfada
kendiliğinden olur.
