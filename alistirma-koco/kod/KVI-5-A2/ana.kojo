// KVI-5-A2 · Engelli ızgarada yol sayma
// Çıktı: "sağ-aşağı yol sayısı: 3"
dez harita = Dizin("S..#.", ".#...", "...#.", "#...C")
dez S = harita.boyu
dez K = harita(0).boyu
dez defter = Eşlem[(Sayı, Sayı), Uzun]()
tanım yol(s: Sayı, k: Sayı): Uzun = 0L
  // sınır dışı ya da engel: 0; (0,0): 1; yoksa defterle yol(s-1,k) + yol(s,k-1)
satıryaz(s"sağ-aşağı yol sayısı: ${yol(S - 1, K - 1)}")
