// KIV-3-A1 · Üç tanım, eşle ile
// Çıktı: "boy: 6 6", "en büyük: 9 9", "ters: 9 5 1 4 1 3 = 9 5 1 4 1 3"
dez d = Dizin(3, 1, 4, 1, 5, 9)
tanım boy(d: Dizin[Sayı]): Sayı = d eşle {
  durum Boş => 0
  durum baş :: gerisi => 1 + boy(gerisi)
}
// enBüyük ve ters
satıryaz(s"boy: ${boy(d)} ${d.boyu}")
