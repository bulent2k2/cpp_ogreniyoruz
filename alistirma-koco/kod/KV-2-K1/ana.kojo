// KV-2-K1 · Çizgeyi tuvale çizin
// Çıktı: "7 düğüm, 8 bağ"
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
dez konum = Eşlem[Düğüm, (Kesir, Kesir)](
  'A' -> (-200.0, 0.0), 'B' -> (-100.0, 80.0), 'C' -> (-100.0, -80.0),
  'D' -> (0.0, 60.0), 'E' -> (0.0, -60.0), 'F' -> (100.0, 0.0), 'G' -> (200.0, 0.0))
tanım düğümÇiz(ad: Düğüm, x: Kesir, y: Kesir) = { }
tanım bağÇiz(a: Düğüm, b: Düğüm) = { }
