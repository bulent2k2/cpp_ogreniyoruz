// KVI-2-A1 · Hangi paralar?
// Çıktı: "11: ... (3 para)" ve "23: ... (... para)"
dez paralar = Dizin(1, 5, 7)
dez defter = Eşlem[Sayı, Dizin[Sayı]]()
tanım enAzParalar(tutar: Sayı): Dizin[Sayı] = Boş
Dizin(11, 23).herbiriİçin { t =>
  dez d = enAzParalar(t)
  satıryaz(s"$t: ${d.yazıYap(" ")} (${d.boyu} para)")
}
