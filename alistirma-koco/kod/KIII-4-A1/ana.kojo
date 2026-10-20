// KIII-4-A1 · Şimdi ölçün (beklenen çıktı yok: kendi sayılarınız)
tanım asalMı(n: Sayı): İkil =
  n > 1 && (2 |- n).hepsiDoğruMu(b => n % b != 0)
tanım süresi(iş: => Birim): Kesir = {
  dez t0 = buSaniye
  iş
  buSaniye - t0
}
tanım asalMıHızlı(n: Sayı): İkil =
  n > 1 && (2 |-| 40000).alDoğruKaldıkça(b => b * b <= n).hepsiDoğruMu(b => n % b != 0)
dez n = 999999937
// iki süre ve oran
