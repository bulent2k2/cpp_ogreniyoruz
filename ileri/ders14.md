Önce Talha kardeşimizin sarmal çizen kodunu satır satır okuduk ve bir kaç değişiklik yaptık. Tasarımı anladık, yorumladık. Hepimiz için epey öğretici oldu. Sağol Talha!

[Kodun en son hali burada](https://onlinegdb.com/fC4ztk-lF).   

Derste yaptığımız değişiklikler dışında tek önemli değişiklik `girdi` adlı işlev kalıbı. Derste şöyle bir numara yapmıştık:
```c++
template <typename T>
T girdi(T geçici, string, string);
```

Ama daha iyi bir çözüm de mümkün. Önce ilk yazdığımız sade kalıba geri dönüyoruz:
```c++
template <typename T>
T girdi(string, string);
```

Sonra kalıbı somutlaştırmak için şöyle yapıyoruz:

```c++
const int kolSayisi{girdi<int>(soru, hataDurumundaSoru)};
```

Kodun hepsi yukarıdaki linkte.  
