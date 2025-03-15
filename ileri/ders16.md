Çizim Projesi, İşlevsel Programlama ve Grafik Kütüphanesiyle Kodlamaya Giriş 
====

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

Hatta, çizimleri yan yana ve alt alta çizen iç içe `for` döngüleri üç dört farklı yerde aynı şekilde kullanılıyor. Şöyle bir kalıp olsa: 
```c++
template <typename İşlev>
void oluşturVeYaz(İşlev çizim, int w, int l, int sayi, int k) {
  string alan[w][l];
    
  // istenilen çizimi alana yaz:
  çizim(alan, w, l);
  
  // sonra onu ekrana yaz:

  // Önce ilk satır sonra ikinci vs. olmak üzere her satırı
  // yatay doğrultu boyuncaki kutucuk/sarmal/üçgen/emoji 
  // sayısı kadar yazdırıyoruz:
  for(int sayac=sayi/k;sayac>0;sayac--) {
    for(int y=0;y<l;y++) {
      for(int s=k;s>0;s--) { 
        cout << "  ";
        for(int x=0;x<w;x++) 
          cout << alan[x][y];
      }
      if(y==l-1) cout << endl << endl;
      else cout << endl;
    }
  }
  // Eğer tam bölünme yoksa kalanlari son satıra ekliyoruz 
  if(sayi%k!=0)
    for(int y=0;y<l;y++) {
      for(int s=sayi%k;s>0;s--){
        cout << "  ";
        for(int x=0;x<w;x++) 
          cout << alan[x][y];
      }
      if(y==l-1) cout <<endl << endl;
      else cout << endl;
    }
}
```

Bu işlevi `kutucuk`, `sarmal`, `üçgen` ve `emoji` işlevleri içinde kullanabiliriz.  Onun için de gelişmiş bir teknik olan işlevleri girdi ve çıktı olarak kullanmaya (*functional programming*) giriş yaptık. [`ele` ve `işle` adlı işlevleri tanımlayan kod burada](https://onlinegdb.com/hom_Y7CSt). 

Geçen dersten [kağıt katlama koduna](https://onlinegdb.com/QNojjbcbV) birkaç hedef daha eklendi: en yakın galaksi Andromeda ve bilinen Evren'in ucu. 

Grafik kartı kullanarak canlandırma, simülasyon ve oyun programlamaya giriş yaptık. [Cinder adlı kütüphaneyi](https://libcinder.org) inceledik. Örnek olarak [zıplayan top simülasyonu kodunu](https://onlinegdb.com/aYu-ehYHj) okuduk ve çalıştırdık.

