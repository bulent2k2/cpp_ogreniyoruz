// KV-4-A1 · Dijkstra'yı Koco'ya çevirin
// Çıktı: "1: 0", "2: 5", "3: 2"
tür Yollar = Eşlem[Sayı, Dizin[(Sayı, Sayı)]]
dez yollar: Yollar = Eşlem(1 -> Dizin((2, 6), (3, 2)), 2 -> Boş, 3 -> Dizin((2, 3)))
tanım dijkstra(yollar: Yollar, başlangıç: Sayı): Eşlem[Sayı, Sayı] = {
  dez uzaklık = Eşlem[Sayı, Sayı]()
  dez sıra = ÖncelikSırası[(Sayı, Sayı)]()
  sıra.ekle((0, başlangıç))
  // sıra boşalana kadar: (-u, şehir) al; eski kayıtsa atla; komşuları gevşet
  uzaklık
}
dez u = dijkstra(yollar, 1)
(1 |-| 3).herbiriİçin { ş => satıryaz(s"$ş: ${u.alYoksa(ş, -1)}") }
