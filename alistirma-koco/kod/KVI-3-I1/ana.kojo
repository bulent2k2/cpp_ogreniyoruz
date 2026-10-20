// KVI-3-I1 · Bir işleç daha
// Çıktı: a + a, a * a, a - Karmaşık(1, 1), (a * a).büyüklüğü, Karmaşık(0, 1) * Karmaşık(0, 1)
durum sınıf Karmaşık(g: Kesir, s: Kesir) {
  tanım +(öbürü: Karmaşık) = Karmaşık(g + öbürü.g, s + öbürü.s)
  tanım *(öbürü: Karmaşık) =
    Karmaşık(g * öbürü.g - s * öbürü.s, g * öbürü.s + s * öbürü.g)
  tanım büyüklüğü = karekökü(g * g + s * s)
}
dez a = Karmaşık(1, 2)
satıryaz(a + a)
satıryaz(a * a)
