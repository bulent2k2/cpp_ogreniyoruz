// KIV-4-I1 · Kaç çağrı?
// Çıktı: "yavaş: 832040, ... çağrı", "hızlı: 832040, ... çağrı", "fib(90) = ...", "bellek: ... kayıt"
tanım fibYavaş(n: Sayı): Uzun =
  eğer (n < 2) n
  yoksa fibYavaş(n - 1) + fibYavaş(n - 2)
dez bellek = Eşlem[Sayı, Uzun]()
tanım fibHızlı(n: Sayı): Uzun =
  eğer (n < 2) n
  yoksa bellek.alYoksa(n, {
    dez sonuç = fibHızlı(n - 1) + fibHızlı(n - 2)
    bellek.eşEkle(n -> sonuç)
    sonuç
  })
satıryaz(fibHızlı(45))
satıryaz(fibHızlı(90))
