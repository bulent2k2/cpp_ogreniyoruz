// KV-2-A1 · Yol var mı?
// Çıktı: "A -> G: evet" biçiminde dört satır
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
tanım ulaşırMı(ç: Çizge, a: Düğüm, b: Düğüm): İkil = yanlış
Dizin(('A', 'G'), ('G', 'A'), ('B', 'E'), ('E', 'F')).herbiriİçin { durum (a, b) =>
  satıryaz(s"$a -> $b: ${eğer (ulaşırMı(ç, a, b)) "evet" yoksa "hayır"}")
}
