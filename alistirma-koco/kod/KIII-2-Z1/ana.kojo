// KIII-2-Z1 · Kendi işle'niz, kendi ele'niz
// Çıktı: "işle: 9 1 16 1 25 = 9 1 16 1 25" ve "ele: 3 1 1 5 = 3 1 1 5"
dez d = Dizin(3, 1, 4, 1, 5)
tanım bizimİşle(d: Dizin[Sayı])(f: Sayı => Sayı): Dizin[Sayı] = Boş
tanım bizimEle(d: Dizin[Sayı])(deneme: Sayı => İkil): Dizin[Sayı] = Boş
satıryaz(s"işle: ${bizimİşle(d)(s => s * s).yazıYap(" ")} = ${d.işle(s => s * s).yazıYap(" ")}")
satıryaz(s"ele: ${bizimEle(d)(s => s % 2 == 1).yazıYap(" ")} = ${d.ele(s => s % 2 == 1).yazıYap(" ")}")
