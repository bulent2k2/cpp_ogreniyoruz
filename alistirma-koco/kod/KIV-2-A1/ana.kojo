// KIV-2-A1 · Kare tanesi
// Çıktı: "bir kenar, derinlik 3: ... çizgi" ve "dört kenar: ... çizgi"
den çizgi = 0
tanım kareKoh(boy: Kesir, derinlik: Sayı): Birim =
  eğer (derinlik == 0) { ileri(boy); çizgi = çizgi + 1 }
  yoksa {
    // beş parça
  }
canlandırmaHızınıKur(0)
kareKoh(243, 3)
satıryaz(s"bir kenar, derinlik 3: $çizgi çizgi")
