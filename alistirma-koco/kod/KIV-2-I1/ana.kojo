// KIV-2-I1 · Çizgileri sayın
// Çıktı: "derinlik 4: ... çizgi"
tanım koh(boy: Kesir, derinlik: Sayı): Birim =
  eğer (derinlik == 0)
    ileri(boy)
  yoksa {
    koh(boy / 3, derinlik - 1); sol(60)
    koh(boy / 3, derinlik - 1); sağ(120)
    koh(boy / 3, derinlik - 1); sol(60)
    koh(boy / 3, derinlik - 1)
  }
canlandırmaHızınıKur(0)
yinele(3) {
  koh(243, 4)
  sağ(120)
}
