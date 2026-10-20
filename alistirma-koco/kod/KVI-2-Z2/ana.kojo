// KVI-2-Z2 · Sonsuz yerine Belki
// Çıktı: "11: yok", "12: 2", "23: ..."
dez paralar = Dizin(5, 7)
dez defter = Eşlem[Sayı, Belki[Sayı]]()
tanım enAz(tutar: Sayı): Belki[Sayı] = Hiçbiri
Dizin(11, 12, 23).herbiriİçin { t =>
  satıryaz(s"$t: ${enAz(t) eşle { durum Biri(n) => n.yazıya; durum Hiçbiri => "yok" }}")
}
