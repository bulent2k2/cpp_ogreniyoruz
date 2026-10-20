// KIV-1-I1 · Sarmalı sayın
// Çıktı: "sarmal(200): ... çizgi"
tanım sarmal(boy: Kesir): Birim =
  eğer (boy > 2) {
    ileri(boy)
    sağ()
    sarmal(boy * 0.95)
  }
canlandırmaHızınıKur(10)
sarmal(200)
