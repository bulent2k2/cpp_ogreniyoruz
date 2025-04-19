Dizi analizi, Çizgeler ve Ağlar
----

Dersimizin [görsel kayıdı burada](https://drive.google.com/file/d/1Vh9RPK3vkrsmIxbi4M3nUWiMstfS2T08). Bir saat beş dakika sürmüş.  

Bir dizi sayı içinde tekrar var mı yok mu? Bir dizinin *alt dizilerini* nasıl bulabiliriz? Bu soruları yanıtlamak için beraber yazdığımız [kodlar burada](
https://onlinegdb.com/FXZNCCrMb
). Alt dizi tanımımız: dizinin başı ve sonu aynı sayı olan parçaları. 

Talha arkadaşınız [Project Euler'in 52. sorusunu](https://projecteuler.net/problem=52) çok güzel programlayarak çözmüş. Derste üzerinden geçtik. [Kodu burada](https://www.onlinegdb.com/fUk6rwipq).  

Çizgeler ve ağlar hakkında konuştuk ve geçen yılın çizge kuramından gelen sorularına baktık. Onları programlamak için çok kullanılan komşuluk matrisi kodunun üzerinden geçtik. 

```c++
const int N=10; // en çok 10 düğüm olsun
bool km[N][N];
// ikinci düğümden birinci düğüme yönlü bir bağ:
km[1][0] = true;
```

Yönsüz bağ istersek, yukardakine bir de ters yönde bir bağ ekliyoruz:
```c++
km[0][1] = true;
```

Basit bir çizge yerine iki düğüm arasında birden çok bağ olursa, o zaman `bool` yerine `unsigned int` kullanabiliriz: 
```c++
unsigned int km[N][N];
// 0 ve 1 arasında iki yönsüz bağ için:
km[0][1] = 3; // iki kıyı arasında
km[1][0] = 3; // üç köprü olsun
```

Bağların değişik kapasitelere sahip olduğu çizgelere *ağ* da deniyor. Ağları kodlamak için de `double` kullanabiliriz:
```c++
double km[N][N];
km[3][5] = 2.5; // gidiş kapasitesi büyük 
km[5][3] = 0.5; // geliş küçük 
```

Derste üzerinden geçtiğimiz komşuluk matrisi oluşturup ekrana yazan [kodumuz da burada](https://onlinegdb.com/qph9rcrQE).

Çizgeler ve Ağlar hakkında [bilgiler de burada](../notlar/cizge-kurami.md).  
