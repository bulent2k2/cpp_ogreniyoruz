// KIII-3-Z1 · Eşleme denemesi (hızlı sürümde bilerek hata var)
// Çıktı: "ilk ayrışma: ...", düzeltince "ayrışma yok" ve "1000'e kadar 168 asal"
tanım asalMı(n: Sayı): İkil =
  n > 1 && (2 |- n).hepsiDoğruMu(b => n % b != 0)
tanım asalMıHızlı(n: Sayı): İkil =
  n > 1 && (2 |-| 1000).alDoğruKaldıkça(b => b * b < n).hepsiDoğruMu(b => n % b != 0)
dez ayrışan = (1 |-| 1000).bul(n => asalMı(n) != asalMıHızlı(n))
// ayrışan bir Belki: Biri(n) ya da Hiçbiri; yazdırın
