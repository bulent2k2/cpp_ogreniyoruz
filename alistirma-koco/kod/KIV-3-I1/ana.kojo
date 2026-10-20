// KIV-3-I1 · Dört disk
den adım = 0
tanım taşı(n: Sayı, kaynak: Sayı, hedef: Sayı, yardımcı: Sayı): Birim =
  eğer (n > 0) {
    taşı(n - 1, kaynak, yardımcı, hedef)
    adım = adım + 1
    satıryaz(s"$adım) $n. diski $kaynak -> $hedef")
    taşı(n - 1, yardımcı, hedef, kaynak)
  }
taşı(3, 1, 3, 2)
