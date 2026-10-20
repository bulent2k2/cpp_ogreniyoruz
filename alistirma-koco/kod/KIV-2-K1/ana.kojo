// KIV-2-K1 · Ejderha eğrisi
// Çıktı: "derinlik 10: ... çizgi"
den çizgi = 0
tanım ejderha(boy: Kesir, derinlik: Sayı, yön: Sayı): Birim =
  eğer (derinlik == 0) { ileri(boy); çizgi = çizgi + 1 }
  yoksa {
    // iki çağrı, arada sağ(yön * 90)
  }
canlandırmaHızınıKur(0)
ejderha(6, 10, 1)
satıryaz(s"derinlik 10: $çizgi çizgi")
