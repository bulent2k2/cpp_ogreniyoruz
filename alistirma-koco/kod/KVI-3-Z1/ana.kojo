// KVI-3-Z1 · Mandelbrot, metinle
// Çıktı: 24 satırlık bir resim
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
(0 |- 24).herbiriİçin { satır =>
  dez y = 1.2 - satır * 2.4 / 23
  // 60 sütun: x = -2.2 + sütun * 3.0 / 59; karakter seç; satırı yaz
}
