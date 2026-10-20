// KII-4-A1 · Parantez dengesi
// Çıktı: "(()()): evet", "((): hayır", ")(: hayır"
tanım dengeliMi(yazı: Yazı): İkil = {
  dez yığın = Yığın[Harf]()
  den bozuk = yanlış
  // harf harf
  !bozuk && yığın.tane == 0
}
Dizin("(()())", "(()", ")(").herbiriİçin { y =>
  satıryaz(s"$y: ${eğer (dengeliMi(y)) "evet" yoksa "hayır"}")
}
