// KI-3-A1 · Project Euler 1, üç kere
// Çıktı: üç satır
tanım bölünüyorMu(sayı: Sayı, bölen: Sayı) = sayı % bölen == 0
tanım pe1(sınır: Sayı) = (1 |- sınır).ele(s => bölünüyorMu(s, 3) || bölünüyorMu(s, 5)).topla
satıryaz(pe1(1000))
// 10000 ve 3-5-7 sürümü
