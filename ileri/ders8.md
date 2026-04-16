> [Önceki](ders7.md) [Hepsi](icindekiler.md) [Sonraki](ders9.md)

*Yine `std::list` kullanarak özyineleme, 2025 sayısının özellikleri ve `std::map` kalıbı, *fayda.h* başlık dosyası ve faydaları, dizi (array), akıllı dizi (`vector`), dizin (`list`) ve eşlem (`map`) kalıpları arasındaki benzerlikler ve farklar. Bir de *DRY* ilkesi.*  

[Görsel kayıt](https://drive.google.com/file/d/1WpOxvV7uT1ift6mPO51yMSaSRt2ZfE-2/view?usp=drivesdk).  1:22:08 uzunluğunda.

[std::list, namespace ve özyineleyerek asal çarpan bulma](https://onlinegdb.com/9m56IBI1M).   İşlevlerin girdisi ve çıktısı olarak *dizin* (std::list) kullandık. Dizilerle dizinlerin farkı hakkında konuştuk.

[Yeni yılın matematiksel sürprizleri, *eşlem* (std::map) ve *ikili* (std::pair) veri yapıları](https://onlinegdb.com/aT8ic-BoR).   

[Ön işlemci komutları: #if, #else, #endif]( 
https://onlinegdb.com/xf6G6EgDw
).   Yapay beyin koduyla başladık, *for* döngüsüyle biraz oynadık. Ayrıca ++i ve i++ arasındaki farka baktık.   

[fayda.h başlık dosyası ve Sözlük yapısı](https://onlinegdb.com/xhCQeTBsM).  *Eşlem* (std::map), *dizin* (std::list) ve *yazı* (std::string) türlerini kullanarak çok tanımlı bir Sözlük yapısı oluşturduk.  

Bunu çatallayıp sözlüğe yeni sözcükler veya yeni tanımlar eklemeyi deneyebilirsiniz. 

[Bir küçük **eşlem**(*std::map*) örneği daha](https://coliru.stacked-crooked.com/a/2cbfbebdc875e918). 14. ve 15. satırlara dikkat. Eşlemde bulunmayan bir ögeyi *[]* işlemcisiyle okuyunca ne oluyor? 

Kurulukta fayda olur mu?!
---
Bu arada yeri gelmişken bence çok önemli bir programlama ilkesine de değinelim: **DRY**: *Don't Repeat Yourself*. Bir programın yazılımında kopyalayıp yapıştırmaktan, yani aynı şeyleri yinelemekten kaçınmakta çok fayda var. Onun için, bu son örneği tekrar (!) yazalım: [tekrarlardan kaçınma örneği](https://coliru.stacked-crooked.com/a/260fc13e808be74c).  

> [Önceki](ders7.md) [Hepsi](icindekiler.md) [Sonraki](ders9.md)
