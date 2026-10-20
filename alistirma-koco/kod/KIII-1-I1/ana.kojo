// KIII-1-I1 · Çember olmaya çalışan çokgen
// Çıktı: "3 kenar: 120.0" biçiminde satırlar
tanım çokgen(kenarSayısı: Sayı, kenar: Kesir) = {
  yinele(kenarSayısı) {
    ileri(kenar)
    sağ(360.0 / kenarSayısı)
  }
}
çokgen(3, 120)
çokgen(4, 90)
çokgen(6, 60)
çokgen(60, 6)
