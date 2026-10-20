// KVI-4-A1 · Yaşam oyunu, kümeyle
// Çıktı: "başlangıç: ..." ve "4 nesil sonra: ..." (hücreler sıralı, (y,x) biçiminde)
tür Hücre = (Sayı, Sayı)
dez planör = Küme((1, 2), (2, 3), (3, 1), (3, 2), (3, 3))
tanım komşular(h: Hücre): Küme[Hücre] = {
  dez (y, x) = h
  için (dy <- -1 |-| 1; dx <- -1 |-| 1; eğer (dy != 0 || dx != 0)) ver (y + dy, x + dx)
}.kümeye
tanım nesil(canlılar: Küme[Hücre]): Küme[Hücre] = canlılar
