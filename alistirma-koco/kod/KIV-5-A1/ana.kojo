// KIV-5-A1 · Altküme toplamları, kümede
// Çıktı: "11 farklı toplam" sonra "0 1 2 ... 10"
tanım toplamlar(d: Dizin[Sayı]): Küme[Sayı] =
  eğer (d.boşMu) Küme(0)
  yoksa {
    dez geri = toplamlar(d.kuyruğu)
    geri   // ++ başı eklenmiş hâli
  }
dez t = toplamlar(Dizin(3, 1, 2, 4)).dizine.sıralı
// yazdır
