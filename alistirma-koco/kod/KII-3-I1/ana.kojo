// KII-3-I1 · Harf sayacı, başka sözcük
dez harfler = "kelebek kanadi".ele(h => h != ' ')
dez öbekler = harfler.öbekle(h => h)
dez sayaç = öbekler.işle { durum (harf, öbek) => (harf, öbek.boyu) }
sayaç.dizine.sıralı.herbiriİçin { durum (harf, kaç) =>
  satıryaz(s"$harf -> $kaç")
}
