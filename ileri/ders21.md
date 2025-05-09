Kısaca yazılım tarihçesi ve bazı faydalı veri yapıları
====

[Görsel kayıt burada](https://drive.google.com/file/d/1HFgtYu63jB1Rfmr1tatwwjs1TSlhdHUC). 55 dakika uzunluğunda.

Yığın, kuyruk, öncelik sırası ve deste
----
Daha önce görmediğimiz ama çok faydalı olabilen bazı özel dizi türlerini inceledik. Hepsinin `size()` ve `empty()` adlı yöntemleri var. Hiçbirinde `begin()` ve `end()` yok.

- Yığın: İlk giren son çıkar. Son giren ilk çıkar. Önemli yöntemler: `push()`, `pop()` ve `top()`. DFS (derinlemesine gezi/arama) için faydalı.
- Kuyruk: İlk giren ilk çıkar. Son giren son çıkar. Yöntemler: `push()`, `pop()` ve `front()`. BFS (enlemesine gezi/arama) için faydalı.
- Öncelik sırası: En büyük değer önce çıkar. Giriş sırası önemli değil. Yöntemler yığınla aynı: `push()`, `pop()` ve `top()`. En kısa yol bulmak için faydalı.
- Deste: Ya da iki başlı kuyruk: Öne ya da arkaya eklenebilir ve önden ya da arkadan çıkarılabilir. Yöntemler: `push_front()`, `push_back()`, `front()`, `back()`.

[Dersten kodumuz biraz iyileştirilmiş haliyle burada](https://onlinegdb.com/g-bZYoHcx).

Bu kavramları, bilhassa *yığın* yapısını biraz pekiştirmek için şu alıştırma üzerinde düşünmek ve mümkünse kodunu yazıp çözmek öğretici olabilir: [Parantezler doğru açılıp doğru kapanıyor mu](https://onlinegdb.com/Gk91i3N7K)? 

Tarihi sırasıyla programlama teknikleri ve yöntemleri
----
- Makine dili: 1940larda komutlar ve bütün değişkenler/bellekteki adresler sayılarla yazılıyor.
- Assembly dili: 1950lerde komutların adları var sonunda. Örneğin MOV ADD COPY JUMP. Direk donanımın komutlarını çalıştırıyor.
- Yüksek düzey dillerin doğuşu: Fortran, Cobol ve C. C dili 1980lerde yüksek düzey kabul edilirken, 2000'lerde düşük düzey kalıyor.
- Modüler programlama (işlevlerle yapıtaşları tanımlama ve onlari bir araya getirme)
- Object Oriented (nesne yönelimli) (classes/sınıflar/yeni türler). 1990larda C++ ve Java ile yaygınlaşıyor.
- Functional programming (işlevsel programlama). 2000'lerde web sunucuları ve web sitesi yazılımlarında kullanılarak yaygınlaşıyor. *Closure*, *Haskell* ve *Scala* en meşhurlarından.
- Paralel programlama (core/cpu thread)  multicore computers, supercomputers
- Eşzamanlı programlama/Concurrent programming (cluster of computers) 
  RDD model Resilient Distibuted Data model (Scala / Spark) 
- Çok geniş hacimli veri işleme (big data) / Google arama motoru / AI
- Veri yapıları/Data structures: verileri nasıl düzenleyelim, bir araya koyalim, yapılandıralım
```c++
int s; // tek değer
int x[] {1, 3, 5, 7, 6, 4, 2, 1}; x[3] = 8;  // bellekte dizi
std::vector<int> v; v.push_back(s); v[3] // akıllı dizi
std::list<int> l;  l.push_front(); l.pop_front(); // zincirli dizi
std::set<int> küme; kume.insert(1) 
std::map<string, int>;
std::stack<int> // yığın   FILO (ilk giren son çıkan) DFS derinlemesine
std::queue<int> // kuyruk  FIFO BFS
...
```
Daha detaylı tarihi bilgiler için şu makale fena değil: [1849'dan 2022'ye Kodlama: Programlama Dillerinin Zaman Çizelgesine Bir Kılavuz](https://www.computer.org/publications/tech-news/insider-membership-news/timeline-of-programming-languages).
