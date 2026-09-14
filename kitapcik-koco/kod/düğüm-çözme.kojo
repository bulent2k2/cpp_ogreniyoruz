// Mavi topları (düğümleri) sürükleyerek
// kırmızı bağların kesişmemelerini sağlayın.

// Kırmızı kareye basarak düğümleri rastgele
// dağıtabilir, yeniden oynayabilirsiniz.

// Tam ekranda oynamak daha kolay olur.

// Bunu değiştirip tekrar çalıştırın:
dez tane = 4 // 5 daha zor. 3 kolay. 6 epey uğraştırır

// Şundan esinlendik (Çizgelerin düzlemselliği)
//   https://en.wikipedia.org/wiki/Planarity

dez düğümSayısı = tane * tane
dez yç = 10 // düğümün yarıçapı

durum sınıf Bağ(d1: Düğüm, d2: Düğüm) {
  den czg = çizgiÇiz(d1.x, d1.y, d2.x, d2.y)
}

tanım çizgiÇiz(xa: Kesir, ya: Kesir, xb: Kesir, yb: Kesir) = {
  dez czg = ötele(xa, ya) -> Resim.çizgi(xb - xa, yb - ya)
  czg.çiz()
  czg
}

den bağlar = Dizi[Bağ]()

durum sınıf Düğüm(den x: Kesir, den y: Kesir) {
  dez dgm = ötele(x, y) * boyaRengi(mavi) -> Resim.daire(yç)
  çiz(dgm)
  tanım git(gx: Kesir, gy: Kesir): Birim = {
    x = gx; y = gy
    dgm.konumuKur(gx, gy)
  }
  dgm.fareyleSürükleyince { (mx, my) =>
    dgm.konumuKur(mx, my); x = mx; y = my; bağlarıÇiz(bağlar)
  }
}

// Düğümleri yapalım:
görünmez() // kaplumbağayı saklayalım
dez dgmler = Dizi.doldur(düğümSayısı) { _ => Düğüm(0, 0) }

// bildir(yeni KuralDışı("dur"))  // düğümleri görmek için burada dur

// Bağları ekleyelim:
için (i <- 0 |- düğümSayısı) {
  dez x = i / tane
  dez y = i % tane
  eğer (y < tane - 1) bağlar = bağlar :+ Bağ(dgmler(i), dgmler(i + 1))
  eğer (x < tane - 1) bağlar = bağlar :+ Bağ(dgmler(i), dgmler(i + tane))
}

rastgeleDağıt(dgmler) // düğümleri rastgele yerleştirip bağları çizelim

// yeni oyun düğmesi
tanım kırmızıKare(x: Kesir, y: Kesir, en: Kesir) = {
  dez dörtgen = ötele(x, y) * boyaRengi(kırmızı) -> Resim.kare(en)
  çiz(dörtgen)
  dörtgen
}
dez yeniOyun = kırmızıKare(-tane * 35, -tane * 35, 20)
yeniOyun.fareyeTıklayınca { (x, y) => rastgeleDağıt(dgmler) }

tanım rastgeleDağıt(dd: Dizi[Düğüm]): Birim = { // rastgele koordinat:
  tanım rk = tane * yç * 6 * (rasgele - 0.5)
  dd.herbiriİçin { d => d.git(rk, rk) }
  bağlarıÇiz(bağlar)
}

// bağları düğümlerin çemberine dokunacak şekilde çizelim
tanım bağlarıÇiz(dizi: Dizi[Bağ]) = dizi.herbiriİçin { b =>
  dez (x1, y1, x2, y2) = (b.d1.x, b.d1.y, b.d2.x, b.d2.y)
  dez (dx, dy) = (x2 - x1, y2 - y1)
  dez uzunluk = karekökü(dx * dx + dy * dy)
  dez (xr, yr) = (dx * yç / uzunluk, dy * yç / uzunluk)
  b.czg.sil()
  b.czg = çizgiÇiz(x1 + xr, y1 + yr, x2 - xr, y2 - yr)
}
