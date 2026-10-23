// KVI-5-A1 · Çizelgeyi eşlemle tutun
// Çıktı: "2x2: 2 yol", "5x5: 70 yol", "16x16: ... yol", "defterde ... kayıt"
dez defter = Eşlem[(Sayı, Sayı), Uzun]()
tanım yol(s: Sayı, k: Sayı): Uzun =
  eğer (s == 1 || k == 1) 1L
  yoksa defter.alYoksa((s, k), {
    0L   // hesapla, eşEkle, döndür
  })
Dizin(2, 5, 16).herbiriİçin { n => satıryaz(s"${n}x$n: ${yol(n, n)} yol") }
// defterde kaç kayıt?
