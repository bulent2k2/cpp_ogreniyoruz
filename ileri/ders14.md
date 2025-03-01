
[Görsel kayıt bir saat 10 dakika](https://drive.google.com/file/d/1ERTPOKKvDge97CBYOmcR-KbCJdx0gtCM).  

Önce Talha kardeşimizin sarmal çizen kodunu satır satır okuduk ve bir kaç değişiklik yaptık. Tasarımı anladık, yorumladık. Hepimiz için epey öğretici oldu. Sağol Talha!

[Kodun en son hali burada](https://onlinegdb.com/fC4ztk-lF).   

Dersten sonra önemli bir değişiklik daha yaptım bu kodun içinde. Derste **işlev kalıbını** yazarken derleyici hata verince *tür değişkeni* türünde gereksiz bir girdi eklemiştik:
```c++
template <typename T>
T girdi(T gereksiz, string, string);
```

Ama daha iyi bir çözüm de mümkün. Önce ilk yazdığımız sade kalıba geri dönüyoruz. Önemli nokta şu: **tür degiskeni** olan `T`, sadece çıktının türü. 
```c++
template <typename T>
T girdi(string g1, string g2);
```

Sonra kalıbı somutlaştırmak için gerekli tür değerini belirtmek için, ki bizim için o değer `int`, şöyle yapıyoruz:

```c++
const int kolSayisi{girdi<int>(soru, hataDurumundaSoru)};
```

Bu tekniğe kalıbı somutlaştırmak ya da özelleştirmek (*template specialization*) deniyor: kalıbın adından sonra `<int>` diyerek türün değerini biz belirliyoruz,  çünkü işlevin girdilerinin hiç birinin türü `T` değil. Şu küçük proje bir kaç örnek daha veriyor:  [girdi okuma kalıbı](https://onlinegdb.com/LzdD5FHnz).  

Daha sonra eski bir olimpiyat sorusuna baktık: Bir sayı dizisin en iri ve en küçük ögelerini en az sayıda karşılaştırma yaparak bulmak. *DeepSeek* adlı yapay beyin (*YB*) tarafından yazılmış algoritmayı inceledik. Sonra `Sayı` adlı yeni bir tür tanımlayarak  karşılaştımaları programa saydırdık. [Kodun hepsi burada](https://onlinegdb.com/Hrd-T3H1S).  

Çıkardığımız dersler: *YB*'ye danışmak faydalı ama yanıtlarına çok güvenmek doğru değil. Kendi araştırmamızı yapmamızda çok fayda var. Ayrıca kodu doğru yazmaya öncelik vermek ve ancak daha sonra hızlandırmaya çalışmak da önemli (programcıların meşhur atasözü: *bütün baş belalarının kaynağı sırasız yapılan iyileştirmelerdir!*)

En sonda da genel yazı düzenleme bulmacasına tekrar baktık. [Kod burada](https://onlinegdb.com/rtMQs6sLO).

Ben birkaç küçük ekleme yaptım. Size kalan şu üç yöntem üzerinde düşünmek ve fırsat bulursanız yazıvermek. Birkaç satırda halledebilirsiniz!

```c++
operator<<(ostream&, Yazı);
Yazı::yana(Yazı);
Yazı::alta(Yazı);
```

Ondan sonra şöyle çizimleri kolaylıkla  yapabileceğiz: 
```c++
Yazı y1{"+"};
Yazı y2{"----"};
Yazı y3 = y1 + y2 + y1;
cout << y3/y2/y3;
```
