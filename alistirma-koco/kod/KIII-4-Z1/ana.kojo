// KIII-4-Z1 · Tekrar var mı, ölçün (beklenen çıktı yok)
tanım süresi(iş: => Birim): Kesir = {
  dez t0 = buSaniye
  iş
  buSaniye - t0
}
tanım tekrarVar1(d: Dizin[Sayı]): İkil = d.yinelemesiz.boyu != d.boyu
tanım tekrarVar2(d: Dizin[Sayı]): İkil = d.kümeye.boyu != d.boyu
Dizin(10000, 100000, 1000000).herbiriİçin { n =>
  dez d = (1 |-| n).dizine.işle(s => s % 1000)
  // iki süre
}
