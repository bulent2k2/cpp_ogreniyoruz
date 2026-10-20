// KVI-1-A2 · Izgarada engel
// Çıktı: "3x4, iki engel: 3 yol"
dez yasak = Küme((0, 3), (1, 1))
dez satır = 3
dez sütun = 4
dez bellek = Eşlem[(Sayı, Sayı), Uzun]()
tanım yol(r: Sayı, c: Sayı): Uzun = 0
satıryaz(s"3x4, iki engel: ${yol(satır - 1, sütun - 1)} yol")
