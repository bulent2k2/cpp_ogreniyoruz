// KIII-4-K1 · Asal sayma yarışı
// Çıktı: "deneyerek: 9592" ve "elekle: 9592"
dez n = 100000
tanım asalMıHızlı(k: Sayı): İkil =
  k > 1 && (2 |-| 400).alDoğruKaldıkça(b => b * b <= k).hepsiDoğruMu(b => k % b != 0)
dez elek = Dizik.doldur(n + 1)(doğru)
elek(0) = yanlış
elek(1) = yanlış
// 2'den √n'ye: elek(i) doğruysa i'nin katlarını yanlış yap
