// KV-2-Z1 · Gerçek bir hata, sayılarla
// Çıktı: "denetimsiz: 12 işlem", "denetimli: 7 işlem", "çevrimle: 1000 işlemde durduruldu"
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
tanım denetimsiz(ç: Çizge, ilk: Düğüm, sınır: Sayı): Sayı = {
  dez bekleyen = Yığın[Düğüm]()
  den işlem = 0
  bekleyen.koy(ilk)
  // gezilen denetimi yok; işlem < sınır olduğu sürece
  işlem
}
