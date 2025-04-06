Conway adlı bir matematikçinin yaklaşık 50 yıl önce icat ettiği [yaşam oyununu](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) duydunuz mu? 

Oyunun kuralları oldukça basit ama bir o kadar da ilginç:

Oyun, canlı ve cansız hücrelerin bulunduğu bir ızgara üzerinde oynanıyor. Her hücrenin sekiz komşusu var: üst, alt, sağ, sol ve dört çapraz köşe. Hücrelerin bir sonraki nesilde canlı ya da cansız olması şu kurallara bağlı:

1. **Az Nüfus Kuralı**: Canlı komşu sayısı ikiden az olan hücrelerin canı çıkar (yalnızlıktan).

2. **Hayatta Kalma Kuralı**: İki veya üç canlı komşusu olan hücreler canlı kalır.

3. **Aşırı Nüfus Kuralı**: Üçten fazla canlı komşusu olan hücrelerin canı çıkar (aşırı kalabalıktan).

4. **Üreme Kuralı**: Üç canlı komşusu olan hücreler canlanır.

Bu basit kurallar inanılmaz karmaşık ve güzel desenler oluşturabilir. Oyunun en ilginç yanı da şu: başlangıç durumu belirlendikten sonra herhangi bir müdahaleye gerek olmadan sistem kendi kendine gelişir durur. 

Bazı önemli noktalar:
- Satranç, tavla iki kişiliktir bilirsiniz. Tetris de en meşhur tek kişilik oyunlardan. Yaşam oyunuysa "sıfır oyunculu" bir oyun, yani başladıktan sonra oyuncuya gerek yok.
- Her nesil, önceki neslin durumuna göre tamamen otomatik (deterministic) olarak oluşur. Ama yine de geleceği öngörmek mümkün değişldir.
- Başlangıç desenine bağlı olarak hücreler yok olabilir, sabit kalabilir veya karmaşık desenler oluşturabilir.

Önce [Yaşam Oyununu Oyna adlı site](https://playgameoflife.com/) ile biraz oynayalım. Bu güzel site [Typescript adında çağdaş bir dil](https://www.typescriptlang.org/) kullanılarak yazılmış. Kodu [GitHub'da burada](https://github.com/edwinm/game-of-life). Otomatik olarak [JavaScript](https://javascript.info/) diline çevriliyor ki bizim internet tarayıcımızda çalışsın. Bilgisayar ya da cep telefonu fark etmiyor. Dersimizde faydalanmak için [Claude AI'la bir sohbete girdim](https://claude.site/artifacts/0bca8176-6704-4410-96d7-29dc830d5c64). Claude JavaScript diliyle yazdı önce. Ben rica edince de C++ diliyle yazdı. Bir [kopyası da burada](https://onlinegdb.com/UsaBsUrIZ). Ona bir bakıverin. Anlamadığınız bir yer var mı? Bir sonraki dersimizde [benim yaptığım bazı değişikliklerin](https://onlinegdb.com/9nOi2LmtO) üzerinden geçeriz. Amacımız bol bol kod okumak ve yazmak! O sayede daha iyi anlayacağız ve daha hızlı ve güzel kod yazmayı öğreneceğiz.
