// KV-1-A2 · Yönsüze çevirin
// Çıktı: "A: B C (2)" biçiminde yedi satır, sonra "dereceler toplamı: 16"
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
tanım yönsüz(ç: Çizge): Çizge = {
  dez y: Çizge = Eşlem()
  // her düğüm: komşuları ++ onu komşu sayanlar
  y
}
