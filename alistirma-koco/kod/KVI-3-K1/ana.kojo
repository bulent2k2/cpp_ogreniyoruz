// KVI-3-K1 · Mandelbrot'u boyayın
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
canlandırmaHızınıKur(0)
görünmez()
// 200 x 200 nokta: x = -2.2 + i * 3.0 / 200, y = -1.5 + j * 3.0 / 200; renk, atla, ileri(1)
