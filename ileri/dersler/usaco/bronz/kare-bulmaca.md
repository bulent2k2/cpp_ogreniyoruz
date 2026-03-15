[Kare Bulmaca ](https://usaco.org/index.php?page=viewproblem2&cpid=488)
====

*Aralık 2014, 2. Bronz Problem*  
*Yazarı Mark Gordon*  

`N x M` boyutlarında (`3 <= N <= 50, 3 <= M <= 50`) bir kare bulmacamız var. Bazı hücreler boş ve bazı hücreler engelli (siyaha boyanmış). Ama ipucu numaraları eksik.
İpucu sayısı iki mantıksal adımı izleyen basit bir işlemle bulunuyor: 

1. Adım: Her hücrenin yatay mı yoksa dikey bir ipucu mu başlattığını belirleriz. Bir hücre yatay bir ipucu başlatıyorsa, boş olmalı, 
solundaki komşu hücre engellenmiş veya bulmaca ızgarasının dışında olmalı ve sağındaki iki hücre de boş olmalıdır 
(yani, yatay bir ipucu yalnızca 3 veya daha fazla karakterden oluşan bir kelimeyi temsil edebilir). 
Dikey bir ipucu başlatan bir hücre için kurallar benzerdir: üstündeki hücre engellenmiş veya ızgaranın dışında olmalı ve altındaki iki hücre boş olmalıdır. 

3. Adım: Bir ipucu başlatan her hücreye bir numara atarız. Hücrelere, bir kitabı okuyacağınız sırayla, 
1'den başlayarak ardışık olarak numaralar atanır; en üst sıradaki hücrelere soldan sağa, 
ardından ikinci sıradaki hücrelere vb. numaralar atanır. Yalnızca bir ipucu başlatan hücrelere numaralar atanır. 

Örneğin, noktalar boş hücreleri göstersin. `#` işareti de engellenmiş hücreleri göstersin. 
```
... 
#.. 
...
..# 
.## 
```
Yatay veya dikey bir ipucu başlatabilen hücreler aşağıda ünlem işareti ile işaretlenmiştir:
```
!!! 
#..
!..
..#
.## 
```
Bu hücrelere sayılar atarsak, aşağıdaki sonucu elde ederiz; 
```
123 
#.. 
4.. 
..# 
.## 
```
1 yatay, 2 ve 3 dikey, 4 hem yatay hem dikey sözcükler. Giriş verilerinde açıklanan bulmacanın, yayınlanmış bulmacalarda tipik olarak görülen kısıtlamaları karşılamayabileceğini unutmayın. Örneğin, bazı boş hücreler herhangi bir ipucunun parçası olmayabilir. 

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
Sol üst hücrenin konumu `(1, 1)`'dir. Sağ alt hücrenin konumu `(N, M)`'dir. 

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
