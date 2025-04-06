Conway adlı bir matematikçinin yaklaşık 50 yıl önce icat ettiği [yaşam oyununu](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) duydunuz mu? 

Şu siteyi kurcalayarak başlayalım:

[Yaşam Oyununu Oyna adlı site](https://playgameoflife.com/).  

Oyunun kuralları oldukça basit ama bir o kadar da ilginç:

Oyun, canlı veya ölü durumda olan hücrelerin bulunduğu bir ızgara üzerinde oynanır. Her hücrenin sekiz komşusu vardır (dikey, yatay ve çapraz). Hücrelerin bir sonraki nesle geçişi şu kurallara bağlıdır:

1. **Az Nüfus Kuralı**: Herhangi bir canlı hücre, iki hücreden daha az sayıda canlı komşuya sahipse ölür (yalnızlıktan).

2. **Hayatta Kalma Kuralı**: Herhangi bir canlı hücre, iki veya üç canlı komşuya sahipse bir sonraki nesilde de hayatta kalır.

3. **Aşırı Nüfus Kuralı**: Herhangi bir canlı hücre, üçten fazla canlı komşuya sahipse ölür (aşırı kalabalıktan).

4. **Üreme Kuralı**: Herhangi bir ölü hücre, tam olarak üç canlı komşuya sahipse, bir sonraki nesilde canlı hücreye dönüşür.

Bu basit kurallar, inanılmaz karmaşık ve güzel desenler oluşturabilir. Oyunun en ilginç yanı, başlangıç durumu belirlendikten sonra herhangi bir insan müdahalesi olmadan sistemin kendi kendine gelişmesidir. 

Bazı önemli noktalar:
- Oyun "sıfır oyunculu" bir oyundur, yani başladıktan sonra oyuncuların yapması gereken bir şey yoktur.
- Her nesil, önceki neslin durumuna göre tamamen otomatik olarak oluşur.
- Başlangıç desenine bağlı olarak hücreler yok olabilir, sabit kalabilir veya karmaşık desenler oluşturabilir.

Yukardaki çevirimiçi site güzel bir yazılımla çalışıyor (sanırım JavaScript diliyle yazılmış). Dersimizde okumak ve yazmak için [Claude AI yardımıyla başlayan C++ yazılım](https://onlinegdb.com/9nOi2LmtO) da burada. Okuyup yazalım ki daha iyi anlayalım. 
