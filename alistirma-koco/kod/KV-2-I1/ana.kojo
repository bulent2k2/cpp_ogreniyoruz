// KV-2-I1 · Üç yerden gezi
// Çıktı: "A: A B C D E F G", "D: ...", "G: ..."
tür Düğüm = Harf
tür Çizge = Eşlem[Düğüm, Küme[Düğüm]]
dez ç: Çizge = Eşlem(
  'A' -> Küme('B', 'C'),
  'B' -> Küme('D'),
  'C' -> Küme('D', 'E'),
  'D' -> Küme('F'),
  'E' -> Küme('F'),
  'F' -> Küme('G'),
  'G' -> Küme[Düğüm]()
)
tanım gez(ç: Çizge, buradan: Düğüm, gezilen: Küme[Düğüm]): Küme[Düğüm] =
  eğer (gezilen(buradan)) gezilen
  yoksa ç(buradan).soldanKatla(gezilen + buradan)(
    (g, komşu) => gez(ç, komşu, g)
  )
satıryaz(s"A: ${gez(ç, 'A', Küme[Düğüm]()).dizine.sıralı.yazıYap(" ")}")
