// KIV-2-Z1 · Tanenin çevresi
// Çıktı: "derinlik d: formül ... çizilen ..." biçiminde altı satır
den uzunluk = 0.0
tanım koh(boy: Kesir, derinlik: Sayı): Birim =
  eğer (derinlik == 0) { ileri(boy); uzunluk = uzunluk + boy }
  yoksa {
    koh(boy / 3, derinlik - 1); sol(60)
    koh(boy / 3, derinlik - 1); sağ(120)
    koh(boy / 3, derinlik - 1); sol(60)
    koh(boy / 3, derinlik - 1)
  }
canlandırmaHızınıKur(0)
// 0..5: uzunluk = 0; üç kenar; formülle karşılaştır
