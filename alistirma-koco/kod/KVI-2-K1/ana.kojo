// KVI-2-K1 · Minimizing Coins, aşağıdan yukarı
// Çıktı: "11: 3" ve "1000000: ..."
dez SONSUZ = 1000000000
tanım enAzAY(x: Sayı, paralar: Dizin[Sayı]): Sayı = {
  dez f = Dizik.doldur(x + 1)(SONSUZ)
  f(0) = 0
  // 1..x: her p için f(t) = enUfağı(f(t), 1 + f(t - p)) (t - p >= 0 ise)
  eğer (f(x) >= SONSUZ) -1 yoksa f(x)
}
satıryaz(s"11: ${enAzAY(11, Dizin(1, 5, 7))}")
