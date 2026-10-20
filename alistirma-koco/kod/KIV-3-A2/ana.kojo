// KIV-3-A2 · Permütasyonlar
// Çıktı: "1 2 3" ile başlayan altı satır, sonra "denemeler geçti."
tanım permütasyonlar(d: Dizin[Sayı]): Dizin[Dizin[Sayı]] = d eşle {
  durum Boş => Dizin(Boş)
  durum _ => Boş   // her x için: x :: (x'siz dizinin permütasyonları)
}
permütasyonlar(Dizin(1, 2, 3)).herbiriİçin(p => satıryaz(p.yazıYap(" ")))
