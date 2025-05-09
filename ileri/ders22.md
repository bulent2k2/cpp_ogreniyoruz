[Görsel kayıt burada](https://drive.google.com/file/d/1BqPO1LdeO2QKx5f7PIpSJKULmhdRQWKL) ve bir saat 12 dakika uzunluğunda.

Bir önceki dersten kalan dengeli parantez alıştırmasını sadece `(` ve `)` için çözdük. 
Hem de *yığın* (`std::stack`) kullanmaya gerek kalmadı. [Kodu burada](https://onlinegdb.com/oxLeBEsTo).  

Köşeli parantezleri (`[` ve `]`) eklersek iş biraz karışıyor. Ama ikinci bir sayı değişkeni (`int k2`) ekleyerek çözmeyi deneyin. 
Faydalı bir alıştırma olur.

Derste daha da genel bir problemi *yığın* kalıbı kullanarak çözdük: Hem normal ve köşeli hem de `{` ve `}` yani kıvrık parantezler de olsun dedik. [Kodu burada](https://onlinegdb.com/3CEV8lKuz). Dersten sonra biraz daha denedim ve iki büyük hata buldum. Siz de bulabilir misiniz? Biraz bakın. Biri 14. satırda ortaya çıkıyor (testlerin önemini de daha iyi anlıyoruz!) Öbürü de 36. satırda. Bu hatayı şu [küçük yazılım](https://sololearn.com/compiler-playground/cSj3MEfvalRK) daha iyi açıklayabilir. Onarılmış haliyle [yazılım burada](https://onlinegdb.com/UiXEBVov8b).  Ya bu doğru mu sizce? Birkaç `assert` ekleyerek biraz daha test etmek ve emin olmakta fayda var.  

[*Project Euler*](https://projecteuler.net/)'den 11. ve 13. problemlere giriş yaptık. `ifstream` kullanarak dosyadan veri okumayı gördük. İkisi için de veri dosyaları ve verileri dosyadan okuyup dizilere yazan [kod hazır ve burada](https://onlinegdb.com/kFwoPnvGaW). İlki [*PE 11*](https://projecteuler.net/problem=11) 20x20'lik bir tablodan 4 uzunluğundaki bütün dizileri (yukarı, aşağı, sağa, sola ve çaprazlar dahil) kodla bulmak gerekiyor. İkincisi [*PE 13*](https://projecteuler.net/problem=13)'te de bilgisayara çok büyük sayıları toplamayı öğretiyoruz. Çünkü sayıların hepsi 50 basamaklı yani ne `int` ne de `long` yetiyor. Devamını getirmek de yine sizlere alıştırma olsun.

Aşama sınavı bir hafta sonra (17 Mayıs Cumartesi sabahı) olacakmış. Hepinize başarılar diliyorum. Kolay gelsin, keyifli ve öğretici olsun inşallah.
