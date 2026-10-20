// KI-4-Z2 · Tahmini tersine çevirin
// Çıktı: "50?" biçiminde sorular; yanıt b/k/=; sonunda "... bildim, 6 adım"
den altSınır = 1
den üstSınır = 100
den adım = 0
den bulundu = yanlış
yineleDoğruysa(!bulundu) {
  dez orta = (altSınır + üstSınır) / 2
  adım = adım + 1
  satıryaz(s"$orta?")
  dez yanıt = satıroku("b: daha büyük, k: daha küçük, =: bildin")
  // yanıta göre altSınır/üstSınır/bulundu
}
