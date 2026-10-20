// KV-2-A2 · Yığın mı, kuyruk mu?
// Çıktı: "yığınla : A C E F G D B" ve "kuyrukla: A B C D E F G"
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
tanım gez2(ç: Çizge, ilk: Düğüm) = {
  dez bekleyen = Yığın[Düğüm]()
  den gezilen = Küme[Düğüm]()
  bekleyen.koy(ilk)
  yineleDoğruysa(bekleyen.tane > 0) {
    dez şimdiki = bekleyen.al()
    eğer (!gezilen(şimdiki)) {
      gezilen = gezilen + şimdiki
      yaz(s"$şimdiki ")
      ç(şimdiki).herbiriİçin(komşu => bekleyen.koy(komşu))
    }
  }
  satıryaz()
}
yaz("yığınla : "); gez2(ç, 'A')
// gez3: kuyrukla
