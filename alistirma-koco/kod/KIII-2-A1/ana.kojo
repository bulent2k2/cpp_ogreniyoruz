// KIII-2-A1 · bizimYineleDizinli
// Çıktı: "0 1 2 3 4" ve altında yine "0 1 2 3 4"
tanım bizimYinele(kaç: Sayı)(komutlar: => Birim): Birim =
  eğer (kaç > 0) {
    komutlar
    bizimYinele(kaç - 1)(komutlar)
  }
tanım bizimYineleDizinli(kaç: Sayı)(komutlar: Sayı => Birim): Birim = {
  // ipucu: yardımcı bir işlevle "nereden" başladığınızı taşıyın
}
yineleDizinli(5) { k => yaz(s"$k ") }
satıryaz()
bizimYineleDizinli(5) { k => yaz(s"$k ") }
satıryaz()
