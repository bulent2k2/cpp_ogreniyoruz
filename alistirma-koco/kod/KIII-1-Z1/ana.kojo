// KIII-1-Z1 · Izgara, iki yoldan
// Çıktı: "kare kare: 48 çizgi" ve "çizgi çizgi: 9 çizgi"
den çizgi = 0
tanım çiz(boy: Kesir) = { ileri(boy); çizgi = çizgi + 1 }
tanım kare(kenar: Kesir) = { yinele(4) { çiz(kenar); sağ() } }
tanım ızgara(satır: Sayı, sütun: Sayı, kenar: Kesir) = {
  // satır × sütun kare, atla ile
}
ızgara(3, 4, 40)
satıryaz(s"kare kare: $çizgi çizgi")
// çizgi çizgi sürümü
