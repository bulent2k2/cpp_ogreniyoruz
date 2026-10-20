// KV-3-I1 · Katmanları yazdırın
// Çıktı: "0 adım: A" biçiminde katmanlar; A'dan, sonra C'den
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
dez kat = katmanlar(ç, Küme('A'), Küme('A'))
kat.ikileSırayla.herbiriİçin { durum (katman, uzaklık) =>
  satıryaz(s"$uzaklık adım: ${katman.dizine.sıralı.yazıYap(" ")}")
}
