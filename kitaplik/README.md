Keyifli Kitaplık
====

İki kitapçığı, iki alıştırma defterini ve ders notlarını bir bütün olarak
sunan üç sayfa:

+ [Keyifli Kitaplık](https://claude.ai/artifact/2HmYGoMWQRpLJ6siGq7qxY)
  neden yazıldı, neler sunuyor, bölüm haritası; altı okur tipi için (hiç
  programlamamış, Python ya da C bilen, geçen yıl C++ alan, bu yıl algoritma
  alan, öğretmen) nereden başlanır, nasıl çalışılır.
+ [Keyifli Kavram Dizini](https://claude.ai/artifact/6eAAQywvrczgppTggZMNHT)
  300 kavram A'dan Z'ye, Türkçe ve İngilizce adlarıyla; her kavramda onu
  anlatan kitapçık bölümü, onu çalıştıran alıştırmalar ve ders notu. "English
  A–Z" düğmesiyle İngilizce sıraya geçer; alıştırma bağlantıları doğrudan
  soruya iner.
+ [Keyifli Kitaplık İncelemesi](https://claude.ai/artifact/Kcz4QboYQ7KUwpkNi1T1GW)
  pedagog, editör ve bilgisayar uzmanı gözüyle eksikler, öneriler ve yerini
  söyleyen düzeltme listesi.

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

Dizine kavram eklemek
--

`dizin-veri.js` içindeki `girdiler` listesine bir satır ekleyin; biçim
dosyanın başında anlatılıyor: Türkçe ad, İngilizce ad, bir cümlelik
açıklama, alan, kitapçık bölümleri, alıştırma kimlikleri ve ders notları.
Alıştırma kimlikleri (`IV-3-Z1`, `KII-2-A1`) defterlerdeki `section id`
değerleriyle aynı olmalı; sayfa bağlantıyı bu kimlikten kurar. Sıralama ve
harf gruplama sayfada kendiliğinden olur.
