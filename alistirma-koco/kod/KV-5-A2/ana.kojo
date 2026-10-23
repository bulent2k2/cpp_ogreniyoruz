// KV-5-A2 · Odaları özyinelemeyle sayın
// Çıktı: "4 oda" ve "en büyük oda: 4 kare"
dez harita = Dizin("..#..#", "..#..#", "######", "#...#.")
dez S = harita.boyu
dez K = harita(0).boyu
den gezilen = Küme[(Sayı, Sayı)]()
tanım doldur(s: Sayı, k: Sayı): Sayı = 0   // taban; gezilen = gezilen + ((s, k)); 1 + dört komşu
// her boş, gezilmemiş kareden başlat; say ve en büyüğü tut
