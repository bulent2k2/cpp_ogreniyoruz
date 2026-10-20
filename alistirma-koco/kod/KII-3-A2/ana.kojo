// KII-3-A2 · Tekrar var mı?
// Çıktı: her dizin için "3 1 4 1 5: evet evet" biçiminde bir satır
tanım tekrarVar1(d: Dizin[Sayı]): İkil = yanlış   // yinelemesiz ile
tanım tekrarVar2(d: Dizin[Sayı]): İkil = yanlış   // kümeye ile
tanım yanıt(b: İkil) = eğer (b) "evet" yoksa "hayır"
Dizin(Dizin(3, 1, 4, 1, 5), Dizin(1, 2, 3), Dizin(7, 7)).herbiriİçin { d =>
  satıryaz(s"${d.yazıYap(" ")}: ${yanıt(tekrarVar1(d))} ${yanıt(tekrarVar2(d))}")
}
