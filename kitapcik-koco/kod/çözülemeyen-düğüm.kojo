// Kırmızı kareye (hiç değilse birkaç kere) tıklayın;
// mavi daireleri (düğümleri) tıklayın ve sürükleyin.

dez ilkİleti = "Çizge kuramının\ndüğümleriyle ve bağlarıyla\nkeyifli oyunlar"
dez yç = 10 // düğümlerin yarıçapı
dez yb = 12 // yazının boyu, büyütebilirsin istersen
// bir miktar yazı tutacak bir Resim nesnesi yapar
tanım yazıResmi(içerik: Yazı) =
  ötele(tuvalSınırları.solu + yç, -tuvalSınırları.altı - 4 * yç) ->
    Resim.renkliYazı(içerik, yb, yeşil)

den bilgi = yazıResmi(ilkİleti)
bilgi.çiz() // tuvale çizen satır bu

tanım yazıyıGüncelle(ileti: Yazı): Birim = {
  // Koco'nun yeni sürümlerinde Resim nesnesine doğrudan .güncelle diyebiliyoruz;
  // o zaman den'e gerek kalmaz, dez yeter
  bilgi.sil()
  bilgi = yazıResmi(ileti)
  bilgi.çiz()
}
görünmez()

// Şimdi çizgeye geçelim; her bağ iki düğümü birleştirir
durum sınıf Bağ(d1: Düğüm, d2: Düğüm) {
  den czg = çizgiÇiz(d1.x, d1.y, d2.x, d2.y) // birleştiren çizgiyi çiziyoruz
}
den bağlar = Dizi[Bağ]() // şimdilik bağ yok

durum sınıf Düğüm(no: Sayı, den x: Kesir, den y: Kesir) {
  dez resim = ötele(x, y) * boyaRengi(mavi) -> Resim.daire(yç)
  resim.çiz()
  resim.fareyleSürükleyince { (nx, ny) =>
    x = nx; y = ny; resim.konumuKur(nx, ny); bağlarıÇiz(bağlar)
  }
  resim.fareyiBırakınca { (nx, ny) =>
    yazıyıGüncelle(s"$adı ${yuvarla(nx, 2)},${yuvarla(ny, 2)}")
  }
  tanım adı = s"d$no"   // yazıya (toString) yerine açık bir ad
}
tür Düğümler = Dizi[Düğüm]
tür Bağlar = Dizi[Bağ]
tür Yazılar = Dizi[Yazı]

// bağları temsil eden çizgiyi çizer
tanım çizgiÇiz(xa: Kesir, ya: Kesir, xb: Kesir, yb: Kesir) = {
  dez ç = ötele(xa, ya) -> Resim.çizgi(xb - xa, yb - ya)
  çiz(ç)
  ç
}
tanım bağlarıÇiz(bb: Bağlar) = bb.herbiriİçin { b =>
  dez (x1, y1) = (b.d1.x, b.d1.y)
  dez (x2, y2) = (b.d2.x, b.d2.y)
  dez uzunluk = uzaklık(x1, y1, x2, y2)
  dez (xr, yr) = (yç / uzunluk * (x2 - x1), yç / uzunluk * (y2 - y1))
  b.czg.sil()
  b.czg = çizgiÇiz(x1 + xr, y1 + yr, x2 - xr, y2 - yr)
}

dez (ox, oy) = (tuvalSınırları.solu + 150, -tuvalSınırları.altı - 100)
dez (br, kk) = (4 * yç, 3) // ızgara birimi ve ızgaradan küçük bir kaçış
// k3,3 ve bir bağını bölen üçüncü düğüm
dez düğümler = Dizi( // gönlünüzce ekleyin:
  Düğüm(0, ox,               oy),
  Düğüm(1, ox + br,          oy - kk),
  Düğüm(2, ox + br,          oy - br),
  Düğüm(3, ox + 2 * br - kk, oy - br),
  Düğüm(4, ox + 2 * br,      oy - 2 * br),
  Düğüm(5, ox,               oy - 2 * br),
  Düğüm(6, ox + 3 * br,      oy + br)
)
tanım d(i: Sayı) = {
  belirt(i >= 0 && i < düğümler.boyu, "düğüm sırası yanlış")
  düğümler(i)
}
tanım bağYap(n1: Sayı, n2: Sayı) = Bağ(d(n1), d(n2))
bağlar = Dizi( // gönlünüzce ekleyin:
  bağYap(0, 1), bağYap(0, 6), bağYap(0, 5),
  bağYap(1, 2), bağYap(1, 3),
  bağYap(2, 6), bağYap(2, 5),
  bağYap(4, 6), bağYap(4, 3), bağYap(4, 5)
)
bağlarıÇiz(bağlar) // şart değil, ama ilk resmi biraz toparlıyor. neden?

tanım bağlıMı(a: Düğüm, b: Düğüm) = bağlar.varMı {
  durum Bağ(d1, d2) => (d1 == a && d2 == b) || (d1 == b && d2 == a)
}

dez kırmızıDüğme =
  ötele(tuvalSınırları.solu + yç, -tuvalSınırları.altı - 3 * yç) *
    boyaRengi(kırmızı) -> Resim.kare(3 * yç)
kırmızıDüğme.çiz()
den açık = doğru
kırmızıDüğme.fareyeTıklayınca { (x, y) =>
  dez ileti = eğer (açık) uzaklıklar(düğümler).yazıYap("\n") yoksa ilkİleti
  yazıyıGüncelle(ileti)
  açık = !açık
}

// uzaklıklar'ın bu sürümü düğümler yerine bağlar üstünde çalışsa daha iyi olurdu:
tanım uzaklıklar(dd: Düğümler): Yazılar =
  eğer (dd.boyu < 2) Dizi[Yazı]()
  yoksa (için (d2 <- dd.kuyruğu) ver araUzaklık(dd.başı, d2)) ++ uzaklıklar(dd.kuyruğu)

tanım araUzaklık(d1: Düğüm, d2: Düğüm): Yazı =
  eğer (!bağlıMı(d1, d2)) s"${d1.adı} x ${d2.adı}"
  yoksa {
    dez u = uzaklık(d1.x, d1.y, d2.x, d2.y)
    s"uzaklık(${d1.adı}, ${d2.adı})=${yuvarla(u, 2)}"
  }
