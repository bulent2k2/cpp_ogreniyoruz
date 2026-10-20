// KIII-2-Z2 · Sayan döngü
// Çıktı: "1000 için 10 hak" ve "27 için 111 adım"
tanım kaçKere(koşul: => İkil)(adım: => Birim): Sayı = {
  den sayı = 0
  // koşul doğru kaldıkça: adım; sayı = sayı + 1
  sayı
}
den n = 1
dez hak = kaçKere(n < 1000) { n = n * 2 }
satıryaz(s"1000 için $hak hak")
// Collatz 27
