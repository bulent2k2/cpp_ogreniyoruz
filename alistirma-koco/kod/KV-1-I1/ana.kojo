// KV-1-I1 · Komşuları yazdırın
// Çıktı: "A: B C" biçiminde yedi satır, boş satır, yedi satır daha
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
// ç.dizine.sırala(...) ile dolaşın
