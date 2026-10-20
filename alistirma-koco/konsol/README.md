Konsol düzeneği
===

Koco cildinin **konsola yazan** alıştırmalarını makinede sınamak için küçük
bir düzenek. Koco'nun kendisi bir masaüstü uygulaması; burada yalnız
Türkçe anahtar sözcüklü Scala derleyicisi (`bulent2k2/kojo` deposundaki
`scala-tr` jar'ları) ve Türkçe API'nin standart kütüphaneyle çalışan parçaları
(`Dizin`, `Küme`, `Eşlem`, `işle`, `ele`, `|-|` ...) kullanılıyor; üstüne
`satıryaz`, `yinele`, `belirt` gibi konsol komutları ve çizmeyen bir
kaplumbağa (yalnız konum ve yön tutar) ekleniyor: `KonsolAPI.scala`,
`Kaplumbaga.scala`, `package.scala`.

```bash
./kur.sh                  # bir kere: Kojo deposunu seyrek çeker, derler (Java 17+ gerekir)
./koco.sh betik.kojo      # bir betiği çalıştırır
make -C ../kod test       # beklenen çıktısı olan bütün alıştırmaları sınar
```

Beklenen çıktılar bu düzenekle üretildi. Üç ayrıntı:

+ Çizim alıştırmalarının beklenen çıktısı yok; onlar iKojo'da ya da Koco'da
  gözle sınanır (defterdeki "Tuvalde:" satırı ne görülmesi gerektiğini söyler).
+ `rastgele` burada sabit tohumlu; oyun alıştırmaları `satıroku` ile girdi
  dosyasından okur.
+ Kap ve İkil gösterimi ortama göre değişir (iKojo `List(1, 2)` ve `true`,
  masaüstü Koco `Dizin(1, 2)` ve `doğru` basar). Alıştırmalar bu yüzden kapları
  `yazıYap` ile, İkil'leri `eğer (...) "evet" yoksa "hayır"` ile yazdırır.

`kojo/`, `src/` ve `out/` dizinleri `kur.sh`'ın ürünüdür ve sürüm denetiminde
değildir. `kur.sh` kojo deposunun sınanmış bir sürümünü çeker
(`KOJO_SURUM`, şu an `965de1e7`); Türkçe API değişince yeni sürümü orada
güncelleyip `make -C ../kod test` ile yeniden sınayın. Kojo'nun kaynak kodu kendi lisansına tabidir; buradaki üç Scala
dosyası ve betikler MIT.
