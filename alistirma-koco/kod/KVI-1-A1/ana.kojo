// KVI-1-A1 · Birikimli toplam, dikdörtgen
// Çıktı: "2x2: 6", "3x4: 35", "20x20: 137846528820"
tanım birikimli(satır: Dizin[Uzun]): Dizin[Uzun] =
  satır.kuyruğu.soldanKatla(Dizin(satır.başı)) {
    (bina, öge) => (bina.başı + öge) :: bina
  }.tersi
tanım yollarAY(r: Sayı, c: Sayı): Uzun = 0
satıryaz(s"2x2: ${yollarAY(2, 2)}")
