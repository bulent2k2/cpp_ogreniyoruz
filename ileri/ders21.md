Kısaca yazılım tarihçesi ve bazı önemli veri yapıları
====

[Görsel kayıt burada](https://drive.google.com/file/d/1HFgtYu63jB1Rfmr1tatwwjs1TSlhdHUC). 55 dakika uzunluğunda.

Tarihi sırasıyla programlama teknikleri ve yöntemleri
----
- Makine dili: 1940larda komutlar ve bütün değişkenler/bellekteki adresler sayılarla yazılıyor.
- Assembly dili: 1950lerde komutların adları var sonunda. Örneğin MOV ADD COPY JUMP. Direk donanımın komutlarını çalıştırıyor.
- yüksek düzey dillerin doğuşu: Fortran, Cobol ve C. C dili 1980lerde yüksek düzey kabul edilirken, 2000'lerde düşük düzey kalıyor.
- Modüler programlama (işlevlerle yapıtaşları tanımlama ve onlari bir araya getirme)
- Object Oriented (nesne yönelimli) C++ (classes/sınıflar/yeni türler). 1990larda Java ile yaygınlaşıyor.
- Functional programming (işlevsel programlama). 2000'lerde yayginlaşıyor.
- Paralel programlama (core/cpu thread)  multicore computers, supercomputers
- Eşzamanlı programlama/Concurrent programming (cluster of computers) 
  RDD model Resilient Distibuted Data model (Scala / Spark) 
- Big data / Google search / AI
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

Yığın, kuyruk, öncelik sırası ve deste
----
Daha önce görmediğimiz ama çok faydalı olabilen bazı özel dizi türlerini inceledik. Hepsinin `size()` ve `empty()` adlı yöntemleri var. Hiçbirinde `begin()` ve `end()` yok.

- Yığın: İlk giren son çıkar. Son giren ilk çıkar. Önemli yöntemler: `push()`, `pop()` ve `top()`. DFS (derinlemesine gezi/arama) için faydalı.
- Kuyruk: İlk giren ilk çıkar. Son giren son çıkar. Yöntemler: `push()`, `pop()` ve `front()`. BFS (enlemesine gezi/arama) için faydalı.
- Öncelik sırası: En büyük değer önce çıkar. Giriş sırası önemli değil. Yöntemler yığınla aynı: `push()`, `pop()` ve `top(). En kısa yol bulmak için faydalı.
- Deste: Ya da iki başlı kuyruk: Öne ya da arkaya eklenebilir ve önden ya da arkadan çıkarılabilir. Yöntemler: `push_front()`, `push_back()`, `front()`, `back()`.

[Dersten kodumuz biraz iyileştirilmiş haliyle burada](https://onlinegdb.com/g-bZYoHcx).
