// KI-4-A1 · Bilgisayar bulsun
// Çıktı: "50 büyük" gibi satırlar, sonunda "73 bildim, 6 adım"
dez tutulan = 73
den altSınır = 1
den üstSınır = 100
den adım = 0
den bulundu = yanlış
yineleDoğruysa(!bulundu) {
  dez orta = (altSınır + üstSınır) / 2
  adım = adım + 1
  // orta == tutulan: bildim; küçükse altSınır = orta + 1; büyükse üstSınır = orta - 1
}
