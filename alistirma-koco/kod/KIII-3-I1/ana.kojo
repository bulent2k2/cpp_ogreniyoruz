// KIII-3-I1 · İki deneme daha
// Çıktı: "6 deneme geçti."
tanım asalMı(n: Sayı): İkil =
  n > 1 && (2 |- n).hepsiDoğruMu(b => n % b != 0)
tanım denemeler() = {
  belirt(asalMı(2), "2 asaldır")
  belirt(asalMı(97), "97 asaldır")
  belirt(!asalMı(1), "1 asal sayılmaz")
  belirt(!asalMı(91), "91 = 7 × 13, kolay tuzak")
  satıryaz("denemeler geçti.")
}
denemeler()
