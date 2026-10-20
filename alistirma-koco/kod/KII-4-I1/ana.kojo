// KII-4-I1 · Hepsini boşaltın
// Çıktı: "yığın: 4 1 3" ve "kuyruk: 3 1 4"
dez yığın = Yığın[Sayı]()
dez kuyruk = Kuyruk[Sayı]()
Dizin(3, 1, 4).herbiriİçin { s =>
  yığın.koy(s)
  kuyruk.ekle(s)
}
satıryaz(yığın.al())        // 4 -- son giren
satıryaz(kuyruk.baştanAl()) // 3 -- ilk giren
