// KVI-3-I1 · Bir işleç daha
// Çıktı: Karmaşık(2.0,4.0), Karmaşık(-3.0,4.0), sonra çıkarma, büyüklük ve i²
durum sınıf Karmaşık(g: Kesir, s: Kesir) {
  tanım +(öbürü: Karmaşık) = Karmaşık(g + öbürü.g, s + öbürü.s)
  tanım *(öbürü: Karmaşık) =
    Karmaşık(g * öbürü.g - s * öbürü.s, g * öbürü.s + s * öbürü.g)
  tanım büyüklüğü = karekökü(g * g + s * s)
}
dez a = Karmaşık(1, 2)
satıryaz(a + a)
satıryaz(a * a)
