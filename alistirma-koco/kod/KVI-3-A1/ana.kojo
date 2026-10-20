// KVI-3-A1 · Kaçış adımları
// Çıktı: "(0.0, 0.0): 100" biçiminde beş satır
durum sınıf Karmaşık(g: Kesir, s: Kesir) {
  tanım +(öbürü: Karmaşık) = Karmaşık(g + öbürü.g, s + öbürü.s)
  tanım *(öbürü: Karmaşık) =
    Karmaşık(g * öbürü.g - s * öbürü.s, g * öbürü.s + s * öbürü.g)
  tanım büyüklüğü = karekökü(g * g + s * s)
}
tanım kaçışAdımı(c: Karmaşık): Sayı = {
  tanım dön(z: Karmaşık, adım: Sayı): Sayı =
    eğer (adım == 100 || z.büyüklüğü > 2) adım
    yoksa dön(z * z + c, adım + 1)
  dön(Karmaşık(0, 0), 0)
}
Dizin(Karmaşık(0, 0), Karmaşık(1, 1)).herbiriİçin { c =>
  satıryaz(s"(${c.g}, ${c.s}): ${kaçışAdımı(c)}")
}
