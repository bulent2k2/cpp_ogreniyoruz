// KV-3-A1 · En az kaç adım?
// Çıktı: "A -> G: 4" biçiminde dört satır
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
tanım katmanlar(ç: Çizge, sınır: Küme[Düğüm], gezilen: Küme[Düğüm]): Dizin[Küme[Düğüm]] =
  eğer (sınır.boşMu) Boş
  yoksa {
    dez sonraki = sınır.düzİşle(d => ç(d)).ele(k => !gezilen(k))
    sınır :: katmanlar(ç, sonraki, gezilen ++ sonraki)
  }
tanım uzaklık(ç: Çizge, a: Düğüm, b: Düğüm): Sayı = -1
Dizin(('A', 'G'), ('A', 'E'), ('D', 'G'), ('G', 'A')).herbiriİçin { durum (a, b) =>
  satıryaz(s"$a -> $b: ${uzaklık(ç, a, b)}")
}
