
[Görsel kayıt](https://drive.google.com/file/d/1ERTPOKKvDge97CBYOmcR-KbCJdx0gtCM) bir saat 10 dakika.  

Sarmal Çizimi 
----

Önce Talha kardeşimizin sarmal çizen kodunu satır satır okuduk ve bir kaç değişiklik yaptık. Tasarımı anladık, yorumladık. Hepimiz için epey öğretici oldu. Sağol Talha! Kodun en son hali [burada](https://onlinegdb.com/fC4ztk-lF).   Dersten sonra önemli bir değişiklik daha yaptım bu kodun içinde. Derste **işlev kalıbını** yazarken derleyici hata verince *tür değişkeni* türünde gereksiz bir girdi eklemiştik:
```c++
template <typename T>
T girdi(T gereksiz, string, string);
```

Ama daha iyi bir çözüm de mümkün. Önce ilk yazdığımız sade kalıba geri dönüyoruz:
```c++
template <typename T>
T girdi(string g1, string g2);
```

Burada önemli nokta şu: **tür değişkeni** olan `T`, sadece çıktının türü. Onun için derleyici kalıbı girdilerin türüne bakarak somutlaştıramıyor ve hata veriyor. Çözüm de çok kolay:

```c++
const int kolSayisi{girdi<int>(soru, hataDurumundaSoru)};
```

Yani kalıbın adından sonra `<int>` diyerek tür değişkeninin yani `T`nin değerini belirliyoruz, çünkü işlevin girdilerinin hiç birinin türü `T` değil. Bu tekniğe kalıbı somutlaştırmak ya da özelleştirmek (*template specialization*) deniyor. Şu küçük projeyle bir kaç örnek daha görelim:  [girdi okuma kalıbı](https://onlinegdb.com/LzdD5FHnz).  

Olimpiyat Sorusu, Yapay Beyin ve bir Sayaç
----

Daha sonra eski bir olimpiyat sorusuna baktık: Bir sayı dizisin en iri ve en küçük ögelerini en az sayıda karşılaştırma yaparak bulmak. *DeepSeek* adlı yapay beyin (*YB*) tarafından yazılmış algoritmayı inceledik. Sonra `Sayı` adlı yeni bir tür tanımlayarak  karşılaştımaları programa saydırdık. [Kodun hepsi burada](https://onlinegdb.com/Hrd-T3H1S).  

Çıkardığımız dersler: *YB*'ye danışmak faydalı ama yanıtlarına çok güvenmek doğru değil. Kendi araştırmamızı yapmamızda çok fayda var. Ayrıca kodu doğru yazmaya öncelik vermek ve ancak daha sonra hızlandırmaya çalışmak da önemli (programcıların meşhur atasözü: *bütün baş belalarının kaynağı sırasız yapılan iyileştirmelerdir!*)

Yazım Çizim Düzenleme
----
En sonda da genel yazı düzenleme bulmacasına tekrar baktık. Ben dersten sonra da birkaç yapıcı ekledim, `+` ve `/` işlemcilerini tanımladım. [Kod burada](https://onlinegdb.com/wfhQZ81l-). Gelecek derste devam ederiz inşallah. Arada size kalan şu üç yöntem üzerinde düşünmek ve fırsat bulursanız yazıvermek. Birkaç satırda halledebilirsiniz!

```c++
operator<<(ostream&, Yazı);
Yazı::yana(Yazı);
Yazı::alta(Yazı);
```

Bu sayede yazı ve çizimleri düzenlemek iyice kolaylaşacak. Örneğin:
```c++
Yazı köşe("+");
Yazı yatay('-', 10, 1);
Yazı dikey('|', 1, 10);
Yazı y1 = köşe + yatay + köşe, 
     y2 = köşe / dikey / köşe;
cout << y1 / (y2 + y2) / y1;
```
