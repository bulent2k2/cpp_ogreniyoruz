// KI-1-A2 · Sayaçlı yineleme, sayarak
// Çıktı: "0: 20" ile başlayan beş satır
tanım kare(kenar: Sayı) = { yinele(4) { ileri(kenar); sağ() } }
yineleDizinli(5) { k =>
  kare(20 + 15 * k)
}
