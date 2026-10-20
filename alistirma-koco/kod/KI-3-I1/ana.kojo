// KI-3-I1 · İki işlev daha: mutlak ve enİri3
// Çıktı: 8, bölünür, bölünmez, eksi, 5, 9  (ayrı satırlarda)
tanım topla(a: Sayı, b: Sayı) = a + b
tanım bölünüyorMu(sayı: Sayı, bölen: Sayı) = sayı % bölen == 0
tanım enİri2(a: Sayı, b: Sayı) = eğer (a > b) a yoksa b
tanım işaret(s: Sayı) =
  eğer (s > 0) "artı"
  yoksa eğer (s < 0) "eksi"
  yoksa "sıfır"
satıryaz(topla(3, 5))
satıryaz(eğer (bölünüyorMu(15, 5)) "bölünür" yoksa "bölünmez")
satıryaz(eğer (bölünüyorMu(16, 5)) "bölünür" yoksa "bölünmez")
satıryaz(işaret(-5))
// mutlak(-5) ve enİri3(4, 9, 7)
