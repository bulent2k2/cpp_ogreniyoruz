// KIV-1-A1 · Dalları sayın
// Çıktı: "ağaç(90): ... dal"
tanım ağaç(boy: Kesir): Birim =
  eğer (boy > 4) {
    ileri(boy)
    sol(30)
    ağaç(boy * 0.7)
    sağ(60)
    ağaç(boy * 0.7)
    sol(30)
    geri(boy)
  }
canlandırmaHızınıKur(1)
kalemRenginiKur(kahverengi)
ağaç(90)
