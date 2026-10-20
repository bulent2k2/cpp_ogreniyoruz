// KV-4-Z1 · Yolu da yazın
// Çıktı: "uzaklıklar: 0 3 1 8 11" ve "1'den 5'e: 1 3 5"
tür Yollar = Eşlem[Sayı, Dizin[(Sayı, Sayı)]]
dez yollar: Yollar = Eşlem(
  1 -> Dizin((2, 4), (3, 1)), 2 -> Dizin((4, 5)), 3 -> Dizin((2, 2), (4, 8), (5, 10)),
  4 -> Dizin((5, 3)), 5 -> Boş)
dez nereden = Eşlem[Sayı, Sayı]()
// KV-4-A1'in dijkstra'sı + nereden; sonra geriye izleme
