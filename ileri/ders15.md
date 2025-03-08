[Görsel kayıt burada](https://drive.google.com/file/d/1QVIXkgY4_82bnhnCnjpk2D50BjXFn3DA). Süresi bir saat 16 dakika.

Kodlar: 
1) [Kağıt katlama](https://onlinegdb.com/tQoReRxKL),  
2) [Büyük ödüllü tv yarışması](https://onlinegdb.com/uKpzahF_x),
3) [Çizim projesinden alıştırmalar](https://onlinegdb.com/QmJYoa6Z0).

Epey okuduk ve yazdık. Daha önce görmediğimiz birkaç yeni becerinin üzerinde duralım:

```c++
bool yaz = false; // yazmak için true
ostream nout{nullptr};
ostream & dout = yaz ? cout : nout;
dout << "istersek yazar, istemezsek yazmaz";
```

Programların içinde bol bol `cout` kullanıyoruz. Bu `dout` (*debug out*), hepsini birden kapatıp açmak için kullanışlı bir yöntem. 

```c++
vector<int> dizi{2, 4, 6, 8};
int i = 2;
try {
  if (i >= dizi.size()) throw i;
  cout << dizi[i];
  i = 4;
  if (i >= dizi.size()) throw i;
} catch(int n) {
  cerr << n << " dizinin dışına taştı";
} 
``` 

Çizim projesine bakarken, `throw` anahtar sözcüğünü de ilk defa gördük. Beklemediğimiz, kuraldışı ya da istisnai (*exception*) durumlarda programı durdurmaya yarar. Projede  girdi olarak bilgi veren bir yazı kullandık. Ama her tür değer kullanılabilir. Burada da sayı kullandık `throw 4;`. İşlevler gibi parantezle de kullanılabilir: `throw("bilgi");`

Eğer yukarıda gördüğümüz gibi bir `try` yani deneme kapsamı içinde kullanırsak, arkadan gelen bir `catch` komuduyla istisnayı ele alıp gerekli bilgiyi yazabiliriz. Program, oradan devam eder. Büyük uzman profesyonel projelerde çok faydalı bir yapıdır. İngilizce adını da bilmenizde fayda var: *exception handling*.

Şu örnek koda bakıp bunları pekiştirmeniz iyi olur: [dout, throw-try-catch ve durgun yerel değişken](https://onlinegdb.com/mmWkdwbUY).

Bu örnekte bir de daha önce görmediğimiz durgun (`static`) yerel değişken kullandım. Bir işlevi birden çok çağırdığımızda, değerini koruyan, yani ilk değere geri dönmeyen yerel bir değişken faydalı olabilir. Ona da dikkat edin. Anlaşılmazsa bir sonraki derse üzerinden geçeriz. 
