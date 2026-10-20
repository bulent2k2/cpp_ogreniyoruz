// KVI-1-I1 · Defterde kaç kayıt?
// Çıktı: "20x20: 137846528820" ve "kayıt: ..."
dez bellek = Eşlem[(Sayı, Sayı), Uzun]()
tanım yol(r: Sayı, c: Sayı): Uzun =
  eğer (r == 0 || c == 0) 1
  yoksa bellek.alYoksa((r, c), {
    dez s = yol(r - 1, c) + yol(r, c - 1)
    bellek.eşEkle((r, c) -> s)
    s
  })
satıryaz(s"20x20: ${yol(20, 20)}")
