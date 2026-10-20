// KII-4-Z1 · Öncelik sırası, ters yüz
// Çıktı: "en uzak önce: ..." ve "en yakın önce: ..."
dez şehirler = Dizin((7, "Bolu"), (2, "İzmit"), (5, "Sakarya"), (2, "Gebze"))
dez sıra = ÖncelikSırası[(Sayı, Yazı)]()
şehirler.herbiriİçin(ş => sıra.ekle(ş))
yaz("en uzak önce:")
yineleDoğruysa(sıra.boyu > 0) { dez (u, ad) = sıra.baştanAl(); yaz(s" $ad($u)") }
satıryaz()
// eksi numarasıyla en yakın önce
