// KIV-3-Z1 · Kümeyi ikiye bölün
// Çıktı: "en küçük fark: 1"
tanım altKümeler(d: Dizin[Uzun]): Dizin[Dizin[Uzun]] = d eşle {
  durum Boş => Dizin(Boş)
  durum baş :: gerisi =>
    dez başsızlar = altKümeler(gerisi)
    başsızlar ++ başsızlar.işle(ak => baş :: ak)
}
dez elmalar = Dizin[Uzun](3, 2, 7, 4, 1)
// her altkümenin toplamı t: fark = |toplam - 2t|; en küçüğü
