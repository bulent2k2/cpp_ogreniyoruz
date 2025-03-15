Çizim Projesi, İşlevsel Programlama ve Grafik Kütüphanesiyle Yazılıma Giriş 
----

[Görsel kayıt](https://drive.google.com/file/d/17cazkcCEq1kCGr9qp7sQTMNrlPpmZEhD)
bir saat 27 dakika uzunluğunda.

[Çizim projesi kodunu](https://onlinegdb.com/hT4HTDvwG)  okuduk. Çok güzel, renkli ve çeşitli çizimler yapan epey gelişmiş bir yazılım. Yazan ve bizimle paylaşan arkadaşınız Talha'ya çok teşekkür ediyoruz. Bu koddan öğrenilebilecek çok şey var. Bir tanesi de karakterlerin sayı olup olmadığını bulma: 

```c++
// rakam karakterleri ASCII'de peşpeşe kodlanmış, onun için: 
bool rakamMı(char k) {
  return k >= '0' && k <= '9';
}

bool sayıMı(std::string yazı) {
  for (auto k : yazı)
    if (!rakamMı(k)) return false;
  return true;
}
```

Burada da [kodun hepsi](https://onlinegdb.com/jAaKQESar) var.

Dikkat ederseniz, çizimleri yan yana ve alt alta çizen iç içe **yedi tane** `for` döngüsü var. Talha arkadaşınız çok emek vermiş ve güzel çalışan bir teknik bulmuş. Sonra da bu başarılı tekniği üç dört farklı yerde aynı şekilde kullanmış.   
 
Talha'nın kodunu şöyle bir kalıp oluşturmak için kullanabiliriz:
```c++
template <typename İşlev>
void oluşturVeYaz(İşlev çizim, int w, int l, int sayi, int k) {
  string alan[w][l];
    
  // istenilen çizimi alana yaz:
  çizim(alan, w, l);
  
  // sonra onu ekrana yaz:

  // Önce yanyana k tane sonra da alta olmak 
  // üzere verilen sayi kadar yaz çizimi
  // (kutucuk/sarmal/üçgen veya emoji) 
  for(int sayac=sayi/k;sayac>0;sayac--) {
    for(int y=0;y<l;y++) {
      for(int s=k;s>0;s--) { 
        cout << "  ";
        for(int x=0;x<w;x++) 
          cout << alan[x][y];
      }
      if(y==l-1) cout << endl;
      cout << endl;
    }
  }
  // Eğer tam bölünmüyorsa kalanları en alta yan yana ekle
  if(sayi%k!=0)
    for(int y=0;y<l;y++) {
      for(int s=sayi%k;s>0;s--){
        cout << "  ";
        for(int x=0;x<w;x++) 
          cout << alan[x][y];
      }
      if(y==l-1) cout << endl;
      cout << endl;
    }
}
```

Bu kodun hemen hemen hepsi Talha arkadaşınızın yazdığı kodun aynısı. Burada ufak bir iki şey ekledik ki bu işlev kalıbını `kutucuk`, `sarmal`, `üçgen` ve `emoji` için kullanabilelim. Bu projemizin kodunu epey sadeleştirir (*refactoring the code* ve DRY yani *Don't Repeat Yourself* denilen ilkeden daha önce de bahsetmiştik), öyle değil mi? Bu ileri kalıp ve işlevsel programlama tekniğini daha iyi anlamak için de işlevleri girdi ve çıktı olarak kullanmaya (*functional programming*) giriş yaptık. [`ele` ve `işle` adlı işlevleri tanımlayan kod burada](https://onlinegdb.com/hom_Y7CSt). But arada ilk defa **adsız işlevleri** tanıdık (İngilizcesi *lambda* ya da *anonymous function*.) Yazdığımız program çalışırken yeni işlevler tanımlayıp onları çalıştırabiliyor! Çok faydalı bir teknik. Dersten sonra bir de daha genel `işle2` adında bir işlev daha ekledim. Onu ayrı bir başlık dosyası içine koydum. Bu da`işle` yöntemi gibi verilen bir dizinin bütün ögelerini değiştirerek yeni bir dizi yapıyor. Girdisi akıllı sayı dizisi ama çıktısı karakter, ikil, yazı ya da başka herhangi bir türün dizisi olabiliyor. Ana işlevin en altında bir iki örnek var. `işle2` tanımı epey ileri bir yöntem olan *metaprogramlama* kullanıyor ki ben bile pek bilmiyorum detaylarını. Onun için çok üzerinde durmayın ama fikriniz olsun ki ilerde gerekince dönüp bakın ve kullanın.

Arada, geçen dersteki [kağıt katlama koduna](https://onlinegdb.com/QNojjbcbV) birkaç hedef daha eklendi: en yakın komşu yıldız [Proksima Sentauri](https://en.wikipedia.org/wiki/Proxima_Centauri), en yakın komşu galaksi [Andromeda](https://en.wikipedia.org/wiki/Andromeda_Galaxy) ve bilinen [Evren'in ucu](https://docs.google.com/document/d/1vyvwIJ3sX90vZp9yzZ-zOfFuMMMENNJftpcWO3k402Q/)! İçinde `std::map` yani **eşlem** kalıbını kullanan bir örneğimiz daha var.

En son grafik kartı kullanarak canlandırma, simülasyon ve oyun programlamaya giriş yaptık. [Cinder adlı kütüphaneyi](https://libcinder.org) inceledik. Örnek olarak [zıplayan top simülasyonu kodunu](https://onlinegdb.com/aYu-ehYHj) okuduk ve çalıştırdık. Ne yazık ki [OnlineGDB](https://www.onlinegdb.com/) henüz bu gelişmiş kütüphaneyi desteklemiyor. Zaten çevrimiçi yani internette bir sunucuda çalışması o sunucunun grafik kartını çok zorlardı. Bilgisayarınıza bu kütüphaneyi indirip *Visual Studio* ile derlemek ve çalıştırmak isterseniz bana haber verin, yardımcı olayım.

Bitti.