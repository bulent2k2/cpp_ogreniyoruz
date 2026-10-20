// KVI-2-I1 · Aceleci yanılsın
// Çıktı: "1,5,7 ile 11: 3", "1,5,7 ile 8: ...", "1,4,6 ile 8: 2"
dez paralar = Dizin(1, 5, 7)
dez defter = Eşlem[Sayı, Sayı]()
tanım enAzPara(tutar: Sayı): Sayı =
  eğer (tutar == 0) 0
  yoksa eğer (tutar < 0) 1000000
  yoksa defter.alYoksa(tutar, {
    dez s = 1 + paralar.işle(p => enAzPara(tutar - p)).enUfağı
    defter.eşEkle(tutar -> s)
    s
  })
satıryaz(s"1,5,7 ile 11: ${enAzPara(11)}")
