// KIV-4-A2 · Pascal üçgeni, bellekli
// Çıktı: ilk altı satır ("1", "1 1", ...), sonra "binom(30, 15) = 155117520"
dez bellek = Eşlem[(Sayı, Sayı), Uzun]()
tanım binom(n: Sayı, k: Sayı): Uzun = 0
(0 |-| 5).herbiriİçin { n => satıryaz((0 |-| n).işle(k => binom(n, k)).yazıYap(" ")) }
satıryaz(s"binom(30, 15) = ${binom(30, 15)}")
