// KII-2-A2 · Dört kısaltmayı indirge ile
// Çıktı: "toplam: 31 31" gibi dört satır (indirge ile, kısaltma ile)
dez sayılar = Dizin(3, 1, 4, 1, 5, 9, 2, 6)
satıryaz(s"toplam: ${sayılar.indirge((a, b) => a + b)} ${sayılar.topla}")
// çarpım, en büyük, en küçük
