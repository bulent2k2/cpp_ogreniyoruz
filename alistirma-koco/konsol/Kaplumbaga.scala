package net.kogics.kojo.lite.i18n.tr

// Konsol sınaması için kaplumbağa benzetimi: çizmez, yalnız konum/yön tutar
// ve kaç çizgi çizildiğini sayar (stderr'e özet basılır). Adlar trInit.scala'daki
// TurkishTurtle'dan birebir.
trait KaplumbağaBenzetimi {
  private var x = 0.0; private var y = 0.0; private var açı = 90.0; private var kalem = true
  var çizgiSayısı = 0; var toplamUzunluk = 0.0
  private var bellek: List[(Double, Double, Double)] = Nil
  private def yürü(adım: Kesir): Birim = {
    x += adım * math.cos(math.toRadians(açı)); y += adım * math.sin(math.toRadians(açı))
    if (kalem && adım != 0) { çizgiSayısı += 1; toplamUzunluk += math.abs(adım) }
  }
  def ileri(adım: Kesir): Birim = yürü(adım)
  def ileri(): Birim = yürü(25)
  def geri(adım: Kesir): Birim = yürü(-adım)
  def geri(): Birim = yürü(-25)
  def sağ(a: Kesir): Birim = { açı -= a }
  def sağ(): Birim = sağ(90)
  def sağ(a: Kesir, yarıçap: Kesir): Birim = { açı -= a; çizgiSayısı += 1 }
  def sol(a: Kesir): Birim = { açı += a }
  def sol(): Birim = sol(90)
  def sol(a: Kesir, yarıçap: Kesir): Birim = { açı += a; çizgiSayısı += 1 }
  def zıpla(n: Kesir): Birim = { val k = kalem; kalem = false; yürü(n); kalem = k }
  def zıpla(): Birim = zıpla(25)
  def atla(nx: Kesir, ny: Kesir): Birim = { x = nx; y = ny }
  def konumuKur(nx: Kesir, ny: Kesir): Birim = atla(nx, ny)
  def ev(): Birim = { x = 0; y = 0; açı = 90 }
  def noktayaDön(nx: Kesir, ny: Kesir): Birim = { açı = math.toDegrees(math.atan2(ny - y, nx - x)) }
  def doğrultu: Kesir = açı
  def konumX: Kesir = x
  def konumY: Kesir = y
  def daire(yarıçap: Kesir = 25): Birim = { çizgiSayısı += 1 }
  def yay(yarıçap: Kesir, a: Kesir): Birim = { çizgiSayısı += 1 }
  def kalemiİndir(): Birim = { kalem = true }
  def kalemiKaldır(): Birim = { kalem = false }
  def konumVeYönüBelleğeYaz(): Birim = { bellek = (x, y, açı) :: bellek }
  def konumVeYönüGeriYükle(): Birim = bellek match { case (a, b, c) :: t => x = a; y = b; açı = c; bellek = t; case _ => }
  def kalemRenginiKur(r: Renk): Birim = ()
  def boyamaRenginiKur(b: Boya): Birim = ()
  def kalemKalınlığınıKur(n: Kesir): Birim = ()
  def canlandırmaHızınıKur(n: Uzun): Birim = ()
  def hızıKur(h: Her): Birim = ()
  def sil(): Birim = { x = 0; y = 0; açı = 90; kalem = true }
  def temizle(): Birim = sil()
  def görünmez(): Birim = ()
  def görünür(): Birim = ()
  def yazı(t: Her): Birim = ()
  def yazıBoyunuKur(boy: Sayı): Birim = ()
  def artalanıKur(r: Her): Birim = ()
  def eksenleriGöster(): Birim = ()
  def eksenleriGizle(): Birim = ()
  object Renkler {
    import java.awt.{Color => R}
    val mavi: Renk = R.blue; val kırmızı: Renk = R.red; val sarı: Renk = R.yellow; val yeşil: Renk = R.green
    val mor: Renk = new R(0x740f73); val pembe: Renk = R.pink; val turuncu: Renk = R.orange; val kahverengi: Renk = new R(0x8b4513)
    val siyah: Renk = R.black; val beyaz: Renk = R.white; val gri: Renk = R.gray; val camgöbeği: Renk = R.cyan
    val koyuMavi: Renk = new R(0x00008b); val koyuYeşil: Renk = new R(0x006400); val açıkMavi: Renk = new R(0xadd8e6)
    val lacivert: Renk = new R(0x000080); val eflatun: Renk = R.magenta
  }
  val mavi = Renkler.mavi; val kırmızı = Renkler.kırmızı; val sarı = Renkler.sarı; val yeşil = Renkler.yeşil
  val mor = Renkler.mor; val pembe = Renkler.pembe; val turuncu = Renkler.turuncu; val kahverengi = Renkler.kahverengi
  val siyah = Renkler.siyah; val beyaz = Renkler.beyaz; val gri = Renkler.gri; val camgöbeği = Renkler.camgöbeği
  val (yavaş, orta, hızlı, çokHızlı) = ("yavaş", "orta", "hızlı", "çokHızlı")
  def kaplumbağaÖzeti: Yazı = f"[kaplumbağa] çizgi: $çizgiSayısı, uzunluk: $toplamUzunluk%.1f, konum: ($x%.1f, $y%.1f), yön: ${((açı % 360) + 360) % 360}%.1f"
}
