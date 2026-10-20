// KVI-2-A2 · Diziler mi, kümeler mi?
// Çıktı: "dizi: 8" ve "küme: 3"
dez paralar = Dizin(2, 3, 5)
tanım dizi(x: Sayı): Uzun = 0
tanım küme(x: Sayı, k: Sayı): Uzun = 0   // yalnız ilk k para
satıryaz(s"dizi: ${dizi(9)}")
satıryaz(s"küme: ${küme(9, paralar.boyu)}")
