// KV-3-A2 · Kaç parça?
// Çıktı: "2 parça" ve "1 parça"
tür Düğüm = Harf
tür Çizge = Eşlem[Düğüm, Küme[Düğüm]]
dez y: Çizge = Eşlem(
  'A' -> Küme('B', 'C'), 'B' -> Küme('A', 'D'), 'C' -> Küme('A', 'D'), 'D' -> Küme('B', 'C'),
  'E' -> Küme('F'), 'F' -> Küme('E'))
tanım gez(ç: Çizge, buradan: Düğüm, gezilen: Küme[Düğüm]): Küme[Düğüm] =
  eğer (gezilen(buradan)) gezilen
  yoksa ç(buradan).soldanKatla(gezilen + buradan)(
    (g, komşu) => gez(ç, komşu, g)
  )
tanım parçaSayısı(ç: Çizge): Sayı = {
  dez düğümler = ç.dizine.işle { durum (d, _) => d }.sıralı
  // soldanKatla((0, Küme[Düğüm]())) { ... }
  0
}
satıryaz(s"${parçaSayısı(y)} parça")
