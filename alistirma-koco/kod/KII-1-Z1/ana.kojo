// KII-1-Z1 · Dizini öne ekleyerek kurun
// Çıktı: "ters: 5 4 3 2 1" ve "düz: 1 2 3 4 5"
den d: Dizin[Sayı] = Boş
yineleDizinli(5) { k =>
  d = (k + 1) :: d
}
satıryaz(s"ters: ${d.yazıYap(" ")}")
// düz sürüm
