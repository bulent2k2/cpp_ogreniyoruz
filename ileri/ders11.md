> [Önceki](ders10.md) [Hepsi](icindekiler.md) [Sonraki](ders12.md)

[Görsel kayıt burada](https://drive.google.com/file/d/1Ls8NcHeju8L_yrY0eDc9ZUUdb_Faqyzr/view). 1 saat 24 dakika uzunluğunda.  

Derste beraber yazdığımız yeni `Temel` adlı türün (`class`) [kodu burada]( https://www.onlinegdb.com/IO4hMr9R-). Epey çıktısı var, hatta en başta derleyici bir uyarı veriyor. Biraz düzeltmeler yapılmış hali de [burada]( https://onlinegdb.com/8h299NKAP). Uyarının çözümünü veriyor ve `cout` yerine `dout` nesnesi kullanarak da çıktıyı temizliyor. Bir de `void ana()` işlevinin en başında, Gürkan kardeşimizin rica ettiği *eşlem* (`std::map`) için ufak bir örnek de var. Cok yaygın kullanılan yazıdan sayıya eşleme: `std::string` -> `int` eşlemesi. Bu arada, eşlemin ilk değerini verirken, `x` adlı sayı değişkeninin ilk değerini belirtmedik. Çoğunlukla sıfır oluyor ama, arada bir şöyle bir çıktı da verebiliyor: `i:20 j:20 x:1696521216 y:5`. Onun için ilk değer girişi çok önemli.

Yeni türümüzün nesnelerini yapan ve yıkan yöntemler üzerinde durduk. Nasıl tanımlanırlar ve nasıl çalışırlar, deneyerek gördük. Birden fazla yapıcı olabileceğini ama sadece tek bir yıkıcı olduğunu öğrendik. Sonra başka bir nesnenin verilerini kopyalayarak yeni bir nesne yapan bir yöntem oluşturduk. Bu kopyalayarak yapan yapıcının adını *kopyalayıcı* koyduk. Bunların hiçbirinin çıktısı yok ve olamaz. Tek sorumlulukları, yeni nesne için bellekte yer açmak ve ilk değerini yazmak, ve ömrünün sonuna gelince de onu bellekten silmek. Onun için ilk yazımları (İngilizcesi *declaration* yani *tanıtım* da diyebiliriz) şöyle oluyor:
```c++ 
class Temel {
    // varsayılan durumda üyeler gizli
    int gizli_veri;
    
protected: 
    int korunmuş_veri;

public: 
    int görünür_veri;

    Temel(); // girdi olabilir
    ~Temel(); // girdi yok! 
    Temel(const Temel&); // aynı türden bir girdi zorunlu, hem de &, yani takma ad (reference) gerekli 

private: 
    int bu_da_gizli;
};
```

Bunu kurcalayarak öğrenmek için daha sade bir [yazılım projesi de burada](https://onlinegdb.com/Mzd1nDHWM). Üç dosya kullanıyor: `main.cpp, Temel.h, Temel.cpp`.  Açıklamalara bakıp birer birer deneyleri çalıştırın.  

Derste ayrıca bir nesnenin değerini değiştirmek için kullanılan eşittir işlemcisini (`operator=`) tanımladık. Bir yapıcı değil, ama üye bir yöntem. Çıktısı olmak zorunda değil, yani `void operator=(...)` diye de tanımlayabiliriz, ama o zaman, `t1 = t2 = t3` gibi peşpeşe eşitleme yapamayız. Onun için genelde kendisinin takma adını, yani kendisine referansı, çıktı olarak verir: 
```c++
Temel & operator=(const Temel& girdi) {
   // ...
   return *this;
}
```

Bununla da `this` anahtar sözcüğünü görmüş olduk: bu değişken, nesnenin kendisinin bellekteki adresini tutan bir *pointer*, yani nesnenin göstergesi.

Son olarak da `friend` anahtar sözcüğünü kullanarak `<iostream>` kütüphanesinden gelen `std::cout` için gerekli olan çıktı akımı işlemcisini tanımladık: 
```c++
class Temel { 
    // ...
    friend std::ostream& operator<<(std::ostream &, const Temel&);
}; 

ostream& operator<< (ostream& o, const Temel& t) {
    o << t.ad << " " << t.sayi << endl;
    return o;
}

int main() { 
    Temel temel;
    std::cout << temel << std::endl; 
}
``` 

Bu `friend` yani arkadaş anlamına gelen anahtar sözcüğüyle türün üyesi olmayan işlevler ve işlemciler de türün gizli verilerini okumak ve gerekirse değiştirebilmek için izin almış oluyorlar. Bir başka örnek de `std::cin` ile kullanıcıdan girdi okumak için kullandığımız `std::istream& operator>>(...)`. Kodumuza eklemek ister misiniz? Öğretici bir alıştırma olur. Biraz uğraşın isterseniz. [Çözümü de burada](https://onlinegdb.com/pI4w1tUIl2). Çalıştırınca, komut satırından sizin bir ad ve sayı girmenizi bekleyecek. Okuduğu girdileri de `Temel` türümüzün bir nesnesine yazacak.

Bu on birinci dersimiz biraz ağır bir ders oldu. **C++** dili, hızını ve nesne-eğilimli becerilerini bu sağlam ve titiz temellere borçlu. Devam etmek dileğiyle... 

> [Önceki](ders10.md) [Hepsi](icindekiler.md) [Sonraki](ders12.md)
