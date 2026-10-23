Dilim Ağaçları (*Segment Trees*)
====

Dizi parçalarının verimli kullanımı. Bir dizide iki iş sık sık bir arada
gerekir: "i'den j'ye toplam (ya da en büyük) kaç?" sorusu ve "k'ıncı öğeyi
değiştir" işlemi. Düz dizide sorgu O(n), değiştirme O(1); birikimli toplam
(*prefix sums*) sorguyu O(1) yapar ama değiştirmeyi O(n)'e çıkarır. Dilim
ağacı ikisini de O(log n)'de yapar: diziyi ikiye, ikiyi dörde böle böle bir
ağaç kurar, her budakta kendi diliminin özetini tutar.

Derslerde:  

+ [ders 1-8 (2025-26)](../dersler/d20251010-1128.md): Dilim, Budak ve Ağaç
  türleri, özyineleyen `ağaçKur()` işlevi, AtCoder'daki alıştırma.  
+ [ders 9](../dersler/d20251205.md): miskin (*lazy*) dilim ağaçları; acele
  edince neden yanlış çıkıyor, `DilimAğacı` sınıfı.  

Okumak için: Rekabetçi Programlama El Kitabı'nın aralık sorguları bölümü
([kitap/](../../kitap/ReadMe.md)). Kitapçığın VI. bölümündeki "Nereye
gidilir?" listesinin ilk iki maddesi buradan başlar.
