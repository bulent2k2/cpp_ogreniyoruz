// KIV-5-A2 · Tekrarlı harflerin dizilişleri
// Çıktı: "3 farklı diziliş" sonra aab / aba / baa
tanım dizilişler(d: Dizin[Harf]): Küme[Dizin[Harf]] =
  eğer (d.boşMu) Küme(Boş)
  yoksa Küme()   // d.yinelemesiz.işle(h => ...).indirge(_ ++ _)
dez sonuç = dizilişler("aab".dizine).dizine.işle(p => p.yazıYap("")).sıralı
// yazdır
