// KIV-1-Z1 · Sierpinski üçgeni
// Çıktı: "derinlik 4: ... üçgen"
den üçgenSayısı = 0
tanım üçgen(kenar: Kesir) = { üçgenSayısı = üçgenSayısı + 1; yinele(3) { ileri(kenar); sol(120) } }
tanım sierpinski(kenar: Kesir, derinlik: Sayı): Birim =
  eğer (derinlik == 0) üçgen(kenar)
  yoksa {
    // üç köşeye sierpinski(kenar / 2, derinlik - 1); zıpla ile dolaşın
  }
canlandırmaHızınıKur(0)
sierpinski(320, 4)
satıryaz(s"derinlik 4: $üçgenSayısı üçgen")
