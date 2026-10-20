// KV-1-A1 · Dereceler
// Çıktı: "A: çıkan 2, gelen 0" biçiminde yedi satır, sonra toplamlar
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
tanım çıkan(d: Düğüm): Sayı = 0
tanım gelen(d: Düğüm): Sayı = 0
