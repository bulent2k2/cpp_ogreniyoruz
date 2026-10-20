package net.kogics.kojo.lite.i18n

// Koco'nun konsol (çizimsiz) alt kümesi: trInit.scala'daki TurkishAPI'nin
// yalnız standart kütüphaneyle çalışan parçaları + konsol komutları.
object KonsolAPI
    extends tr.CharMethodsInTurkish
    with tr.CoreTypeMethodsInTurkish
    with tr.DizikYöntemleri
    with tr.DizinYöntemleri
    with tr.EsnekDizikYöntemleri
    with tr.LazyListMethodsInTurkish
    with tr.MapMethodsInTurkish
    with tr.MatematikYöntemleri
    with tr.OptionMethodsInTurkish
    with tr.PartialFunctionMethodsInTurkish
    with tr.QueueMethodsInTurkish
    with tr.StackMethodsInTurkish
    with tr.RangeMethodsInTurkish
    with tr.SayıYöntemleri
    with tr.SeqMethodsInTurkish
    with tr.SetMethodsInTurkish
    with tr.StringMethodsInTurkish
    with tr.TakvimVeZamanYöntemleri
    with tr.YineleyiciYöntemleri
    with tr.İkisindenBiriYöntemleri
    with tr.VectorMethodsInTurkish
    with tr.KaplumbağaBenzetimi {

  type Nesne = tr.Nesne
  type Birim = tr.Birim
  type Her = tr.Her
  type HerGönder = tr.HerGönder
  type İkil = tr.İkil
  type Dizin[A] = tr.Dizin[A]
  type Diz[B] = tr.Diz[B]
  type Dizi[B] = tr.Dizi[B]
  type Aralık = tr.Aralık
  type Yığın[T] = tr.Yığın[T]
  type Yineleyici[C] = tr.Yineleyici[C]
  type Yinelenebilir[C] = tr.Yinelenebilir[C]
  type YinelenebilirBirKere[C] = tr.YinelenebilirBirKere[C]
  type Renk = tr.Renk
  val Eşlem = tr.Eşlem
  type Eşlem[A, D] = tr.Eşlem[A, D]
  val Dizim = tr.Dizim
  type Dizim[A] = tr.Dizim[A]
  val EsnekDizim = tr.EsnekDizim
  type EsnekDizim[A] = tr.EsnekDizim[A]
  val Yığın = tr.Yığın

  def belirt(belit: İkil, mesaj: => Any = ""): Birim = assert(belit, mesaj)
  def yinele(n: Sayı)(diziKomut: => Birim): Birim = { var i = 0; while (i < n) { diziKomut; i += 1 } }
  def yineleDizinli(n: Sayı)(diziKomut: Sayı => Birim): Birim = { var i = 0; while (i < n) { diziKomut(i); i += 1 } }
  def yineleDoğruysa(koşul: => İkil)(diziKomut: => Birim): Birim = { while (koşul) diziKomut }
  def yineleOlanaKadar(koşul: => İkil)(diziKomut: => Birim): Birim = { while (!koşul) diziKomut }
  def yineleKere[T](dizi: Yinelenebilir[T])(diziKomut: T => Birim): Birim = dizi.foreach(diziKomut)
  def yineleİçin[T](dizi: Yinelenebilir[T])(diziKomut: T => Birim): Birim = dizi.foreach(diziKomut)
  def yineleİlktenSona(ilki: Sayı, sonu: Sayı)(diziKomut: Sayı => Birim): Birim = (ilki to sonu).foreach(diziKomut)
  def satıryaz(): Birim = println()
  def satıryaz(veri: Her): Birim = println(veri)
  def yaz(veri: Her): Birim = print(veri)
  def çıktıyıSil(): Birim = ()
  private val üreteç = new scala.util.Random(12345)   // deterministik: konsol sınaması için
  def rastgele(üstSınır: Sayı): Sayı = üreteç.nextInt(üstSınır)
  def rastgele(altSınır: Sayı, üstSınır: Sayı): Sayı = altSınır + üreteç.nextInt(üstSınır - altSınır)
  def rastgeleSeçim: İkil = üreteç.nextBoolean()
  def rastgeleİkil: İkil = rastgeleSeçim
  def rastgeleKesir(üstSınır: Kesir): Kesir = üreteç.nextDouble() * üstSınır
  def rastgeleTohumunuKur(tohum: Uzun): Birim = üreteç.setSeed(tohum)
  def rastgeleDiziden[T](dizi: Dizi[T]): T = dizi(üreteç.nextInt(dizi.size))
  def rastgeleKarıştır[T](d: Dizi[T]): Dizi[T] = üreteç.shuffle(d)
  // girdi: konsol sınamasında standart girdiden okunur
  def satıroku(istem: Yazı = ""): Yazı = { val s = scala.io.StdIn.readLine(); if (s == null) sys.error("girdi bitti") else s }
  def sayıOku(istem: Yazı = ""): Sayı = satıroku(istem).trim.toInt
  def kesirOku(istem: Yazı = ""): Kesir = satıroku(istem).trim.toDouble
  // süre
  def rastgeleRenk: Renk = new java.awt.Color(üreteç.nextInt(0xffffff))
  def süreyiÖlç(iş: => Birim): Kesir = { val t0 = buSaniye; iş; buSaniye - t0 }
}
