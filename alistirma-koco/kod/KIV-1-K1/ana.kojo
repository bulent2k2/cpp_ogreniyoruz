// KIV-1-K1 · Eğrelti otu: üç dal, renk
den dal = 0
tanım ağaç(boy: Kesir): Birim =
  eğer (boy > 4) {
    dal = dal + 1
    ileri(boy)
    sol(30); ağaç(boy * 0.7); sağ(60); ağaç(boy * 0.7); sol(30)
    geri(boy)
  }
canlandırmaHızınıKur(0)
ağaç(90)
satıryaz(s"$dal dal")
