Önce Talha kardeşimizin sarmal çizen kodunu satır satır okuduk ve bir kaç değişiklik yaptık. Tasarımı anladık, yorumladık. Hepimiz için epey öğretici oldu. Sağol Talha!

[Kodun en son hali burada](https://onlinegdb.com/fC4ztk-lF).   

Dersten sonra önemli bir değişiklik daha yaptım bu kodun icinde. Derste **işlev kalıbını** yazarken derleyici hata verince şöyle bir numara yapmıştık:
```c++
template <typename T>
T girdi(T geçici, string, string);
```

Ama daha iyi bir çözüm de mümkün. Önce ilk yazdığımız sade kalıba geri dönüyoruz:
```c++
template <typename T>
T girdi(string, string);
```

Sonra kalıbı somutlaştırmak için gerekli tür değerini belirtmek için şöyle yapıyoruz:

```c++
const int kolSayisi{girdi<int>(soru, hataDurumundaSoru)};
```

Bu tekniğe kalıbı özelleştirmek (*template specialization*) deniyor.    

Şu proje bir kaç örnek daha veriyor:  [girdi okuma kalıbı](https://onlinegdb.com/LzdD5FHnz).  

Daha sonra eski bir olimpiyat sorusuna baktık: Bir sayı dizisin en iri ve en küçük ögelerini en az sayıda karşılaştırma yaparak bulmak. *DeepSeek* adlı yapay beyin (*YB*) tarafından yazılmış algoritmayı inceledik. Sonra benim eklediğim Sayı adlı türle karşılaştımaları nasıl sayabiliriz onu gördük. [Kodun hepsi burada] 
(https://onlinegdb.com/Hrd-T3H1S).  

Çıkardığımız dersler: *YB*'ye danışmak faydalı ama yanıtlarına çok güvenmek doğru değil. Kendi araştırmamızı yapmamızda çok fayda var. Ayrıca kodu doğru yazmaya öncelik vermek ve ancak daha sonra hızlandırmaya çalışmak da önemli (programcıların meşhur atasözü: *sırasız yapılan optimizasyon baş belalarının kaynağıdır.*)

En sonda da genel yazı düzenleme bulmacasına tekrar baktık. [Kod burada](https://onlinegdb.com/rtMQs6sLO).

Ben birkaç küçük ekleme yaptım. Size kalan şu üç yöntem üzerinde düşünmek ve fırsat bulursanız yazıvermek. Birkaç satırda hallederbilirsiniz!

```c++
operator<<(std::ostream&, Yazi);
Yazi::yana(Yazi);
Yazi::alta(Yazi);
```

[Görsel kayıt bir saat 10 dakika](https://drive.google.com/file/d/1ERTPOKKvDge97CBYOmcR-KbCJdx0gtCM).