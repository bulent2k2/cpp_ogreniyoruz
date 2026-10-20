package net.kogics.kojo.lite.i18n

package object tr {
  type Nesne = Object
  type Birim = Unit
  type Her   = Any
  type HerDeğer  = AnyVal
  type HerGönder = AnyRef
  type Yok   = Null
  type Hiç   = Nothing
  type Renk = java.awt.Color
  type Boya = java.awt.Paint
  type İkil = Boolean
  type Seçim = Boolean
  type Lokma   = Byte
  type Kısa    = Short
  type Sayı    = Int
  type Uzun    = Long
  type İriSayı = BigInt
  type UfakKesir = Float
  type Kesir = Double
  type İriKesir = BigDecimal
  type Diz[B] = collection.Seq[B]
  type Dizi[B] = Seq[B]
  type Dizin[A] = List[A]
  type Aralık = Range
  type Yığın[T] = collection.mutable.Stack[T]
  type SıralıDizi[A] = IndexedSeq[A]
  type Yineleyici[Col] = Iterator[Col]
  type Yinelenebilir[Col] = Iterable[Col]
  type YinelenebilirBirKere[Col] = IterableOnce[Col]
  type Yapıcıdan[DiziTürü, GirdiTürü, ÇıktıTürü] = collection.BuildFrom[DiziTürü, GirdiTürü, ÇıktıTürü]
  type Yazı = String
}
