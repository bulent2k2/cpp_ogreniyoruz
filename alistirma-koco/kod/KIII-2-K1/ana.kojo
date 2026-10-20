// KIII-2-K1 · Dönence içinde dönence
tanım çokgen(kenarSayısı: Sayı, kenar: Kesir) = {
  yinele(kenarSayısı) {
    ileri(kenar)
    sağ(360.0 / kenarSayısı)
  }
}
tanım dönence(kaç: Sayı, açı: Kesir)(çizim: => Birim) = {
  yinele(kaç) {
    çizim
    sağ(açı)
  }
}
canlandırmaHızınıKur(0)
dönence(6, 60) { dönence(12, 30) { çokgen(3, 40) } }
