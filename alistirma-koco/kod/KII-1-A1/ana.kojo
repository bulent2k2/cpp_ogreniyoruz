// KII-1-A1 · İlk üçün toplamı
// Çıktı: "başla: 8, alla: 8" biçiminde iki satır (iki dizin için)
tanım ilkÜç(d: Dizin[Sayı]): Sayı = 0   // başı ve kuyruğu ile
tanım ilkÜç2(d: Dizin[Sayı]): Sayı = 0  // al(3).topla ile
dez a = Dizin(3, 1, 4, 1, 5, 9)
dez b = Dizin(10, 20, 30)
satıryaz(s"başla: ${ilkÜç(a)}, alla: ${ilkÜç2(a)}")
satıryaz(s"başla: ${ilkÜç(b)}, alla: ${ilkÜç2(b)}")
