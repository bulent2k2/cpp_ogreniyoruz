[Kare Bulmaca ](https://usaco.org/index.php?page=viewproblem2&cpid=488)
====

*Aralık 2014, 2. Bronz Problem*  
*Yazarı Mark Gordon*  
*Türkçesi GeminiAI ve hocanızdan*. 

`N x M` boyutlarında bir kare sözcük bulmacamız var. `3 <= N <= 50, 3 <= M <= 50`. Her bir kare ya boş ya da engelli (siyaha boyanmış). Ama kelime ipuçları eksik. İpuçları, iki mantıksal adımdan oluşan basit bir işlemle bulunuyor: 

1. Adım: Her karenin bir ipucu başlatıp başlatmadığını belirleriz. Bir kare yatay bir ipucu başlatıyorsa, boş olmalı, 
solundaki komşu hücre engellenmiş veya bulmaca ızgarasının dışında olmalı ve sağındaki iki hücre de boş olmalıdır.
Yani, yatay bir ipucu yalnızca 3 veya daha fazla karakterden oluşan bir kelimeyi temsil edebilir. Dikey ipucu başlatan kareler için de kurallar benzerdir: üstündeki kare engellenmiş veya ızgaranın dışında olmalı ve altındaki iki kare boş olmalıdır. 

2. Adım: İpucu başlatan her kareye birden başlayarak ardışık sayılar atanır. Bunu kitap okur gibi en üst sıradan başlar soldan sağa, sonra da ikinci sıradaki karelere soldan sağa, ve benzer şekilde son satıra kadar sayılar atanır. Yalnızca ipucu başlatan karelere sayı atanır. 

Örneğin, noktalar boş kareleri göstersin. `#` işareti de engellenmiş kareleri göstersin. 
```
... 
#.. 
...
..# 
.## 
```
Yatay veya dikey ipucu başlatabilen kareler aşağıda ünlem işareti ile işaretlenmiştir:
```
!!! 
#..
!..
..#
.## 
```
Bu karelere sayılar atarsak, aşağıdaki sonucu elde ederiz; 
```
123 
#.. 
4.. 
..# 
.## 
```
Birinci ipucu yatay, 2. ve 3. dikey, 4. hem yatay hem dikey sözcüklerden oluşuyor. Aman dikkat, bazı boş kareler herhangi bir ipucunun parçası olmayabilir. Yani bizim bulmacamız gazete ve dergilerde yayınlanan bulmacalardan biraz daha genel.

GİRDİ (crosswords.in dosyası) 
--
Girdinin ilk satırı, bir boşlukla ayrılmış `N` ve `M` içerir. Sonraki `N` satırın her biri, ızgaranın bir satırını tanımlar. Her biri, nokta (boş hücre) veya `#`(engellenmiş hücre) olan `M` karakter içerir. 

ÖRNEK GİRDİ
--
```
5 3
... 
#.. 
...
..#
.## 
```

ÇIKTI (crosswords.out dosyası) 
--
Çıktının ilk satırına, ipucu sayısını yazdırın. Kalan her satıra, tek bir ipucunun konumunu veren satır ve sütunu yazdırın (yukarıda açıklandığı gibi sıralanmıştır). 
Sol üst karenin konumu `(1, 1)`'dir. Sağ alt karenin konumu da `(N, M)`'dir. 

ÖRNEK ÇIKTI 
--
``` 
4 
1 1 
1 2 
1 3 
3 1
```


> [StackEdit](https://stackedit.io/) kullanarak yazdım.
