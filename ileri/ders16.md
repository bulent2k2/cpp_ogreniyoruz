Çizim Projesi, İşlevsel Programlama ve Grafik Kütüphanesiyle Kodlamaya Giriş 
====

[Görsel kayıt(https://drive.google.com/file/d/17cazkcCEq1kCGr9qp7sQTMNrlPpmZEhD) bir saat 27 dakika uzunluğunda.

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

Hatta, bazı döngü kalıpları üç dört farklı yerde tekrar ediyor. Onları sadeleştirmek, yeni bir yapıtaşı oluşturmak faydalı olur dedik ve onun için işlevleri girdi ve çıktı olarak kullanma tekniklerine giriş yaptık. [`ele` ve `işle` adlı işlevleri tanımlayan kod burada](https://onlinegdb.com/hom_Y7CSt). 

Geçen dersten [kağıt katlama koduna](https://onlinegdb.com/QNojjbcbV) birkaç hedef daha eklendi: en yakın galaksi Andromeda ve bilinen Evren'in ucu. 

Grafik kartı kullanarak canlandırma, simülasyon ve oyun programlamaya giriş yaptık. [Cinder adlı kütüphaneyi](https://libcinder.org) inceledik. Örnek olarak [zıplayan top simülasyonu kodunu](https://onlinegdb.com/aYu-ehYHj) okuduk ve çalıştırdık.

