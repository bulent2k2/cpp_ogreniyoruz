Conway adlı matematikçinin tam 55 yıl önce icat ettiği [yaşam oyununu](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) duydunuz mu? Oyunun kuralları oldukça basit ama bir o kadar da ilginç:

Satranç ve go tahtasına benzer ama daha büyük bir tahtamız var. Tahtanın her hücresi canlı ya da cansız olabiliyor. Her hücrenin sekiz komşusu var: üst, alt, sağ, sol ve dört çapraz köşe. Hücrelerin bir sonraki nesilde canlı ya da cansız olması şu kurallara bağlı:

1. **Az Nüfus Kuralı**: Canlı komşu sayısı ikiden az olan hücrelerin canı çıkar (yalnızlıktan).

2. **Hayatta Kalma Kuralı**: İki veya üç canlı komşusu olan hücreler canlı kalır.

3. **Aşırı Nüfus Kuralı**: Üçten fazla canlı komşusu olan hücrelerin canı çıkar (aşırı kalabalıktan).

4. **Üreme Kuralı**: Üç canlı komşusu olan cansız hücreler canlanır.

Bu basit kurallar inanılmaz karmaşık ve güzel desenler oluşturabiliyor. Oyunun ilginç bir yanı şu: başlangıç durumu belirlendikten sonra herhangi bir müdahaleye gerek olmadan kendi kendine gelişip duruyor. 

Bazı önemli noktalar:
- Satranç ve tavla iki kişiliktir bilirsiniz. Tetris de en meşhur tek kişilik oyunlardan. Yaşam oyunuysa "sıfır oyunculu" bir oyun, yani başlattıktan sonra oyuncuya gerek yok. Bizlere seyretmek ve tadını çıkarmak düşüyor. 
- Her nesil, bir önceki neslin durumuna göre tamamen otomatik (*deterministic*) olarak oluşuyor. Ama yine de geleceği öngörmek mümkün değil.
- Başlangıç desenine bağlı olarak hücrelerin hepsi yok olabilir, sabit kalabilir veya karmaşık desenler oluşturabilir.

Önce [Yaşam Oyununu Oyna adlı site](https://playgameoflife.com/) ile biraz oynayalım. Bu güzel site [Typescript adında çağdaş bir dil](https://www.typescriptlang.org/) kullanılarak yazılmış. Kodu [GitHub'da burada](https://github.com/edwinm/game-of-life). Typescript derleyicisi kodu [JavaScript](https://javascript.info/) diline çeviriyor ki internet tarayıcılarinda çalışsın. Bilgisayar ya da cep telefonu fark etmiyor. Dersimizde faydalanmak için bu konuda [Claude AI'la ufak bir sohbetim oldu](https://claude.ai/share/aed4d16b-c62e-4547-bc4f-7e7e86bf3a65). Claude AI, JavaScript diliyle yazdı önce. Sadece yazmakla kalmadı. Çalıştırdı bile. Yukarıdaki linkle sizin için de çalışır umarım. Ben rica edince [C++ kullanarak da bir kod yazdı](https://claude.site/artifacts/0bca8176-6704-4410-96d7-29dc830d5c64). Bir [kopyası da onlinegdb de çalışıyor](https://onlinegdb.com/UsaBsUrIZ). Onlara da bakıverin. Anlamadığınız bir yer var mı? Sorularınızı bekliyorum. Bir sonraki dersimizde [benim yaptığım bazı değişikliklerin](https://onlinegdb.com/9nOi2LmtO) üzerinden geçeriz. Amacımız bol bol kod okumak ve yazmak. O sayede daha iyi anlayacağız ve daha akıcı, daha rahat ve güzel kod yazmayı öğreneceğiz.
