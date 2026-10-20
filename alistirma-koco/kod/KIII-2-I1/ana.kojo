// KIII-2-I1 · Kaç kere çizdi?
// Çıktı: "sayaç: ..."
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
canlandırmaHızınıKur(10)
dönence(12, 30) { çokgen(4, 100) }
dönence(36, 10) { daire(80) }
dönence(8, 45) {
  kalemRenginiKur(rastgeleRenk)
  çokgen(3, 80)
}
