// KIII-1-A1 · Yıldıza genelleme
// Çıktı: "5 köşe: 144.0" biçiminde üç satır
tanım çokgen(kenarSayısı: Sayı, kenar: Kesir) = {
  yinele(kenarSayısı) {
    ileri(kenar)
    sağ(360.0 / kenarSayısı)
  }
}
tanım yıldız(köşe: Sayı, kenar: Kesir) = {
  // dönüş açısı: iki tam tur / köşe
}
yıldız(5, 120)
