// KII-5-A2 · Skor tablosu
// Girdi: "ad sayı" satırları, son satır "bitti". Çıktı: "ad: en iyi n" (ada göre sıralı)
dez enİyi = Eşlem[Yazı, Sayı]()
den satır = satıroku("ad ve tahmin sayısı (bitti ile çıkın)")
yineleDoğruysa(satır != "bitti") {
  dez parçalar = satır.böl(' ')
  // ad = parçalar(0), n = parçalar(1).sayıya; daha iyiyse eşEkle
  satır = satıroku("ad ve tahmin sayısı (bitti ile çıkın)")
}
// tabloyu yazdır
