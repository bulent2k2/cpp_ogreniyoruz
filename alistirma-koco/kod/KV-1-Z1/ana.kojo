// KV-1-Z1 · Königsberg'in köprüleri
// Çıktı: "A: 5", "B: 3", "C: 3", "D: 3", "tek dereceli: 4, Euler yolu yok"
tür Düğüm = Harf
dez köprüler = Dizin(('A', 'B'), ('A', 'B'), ('A', 'C'), ('A', 'C'), ('A', 'D'), ('B', 'D'), ('C', 'D'))
tanım derece(d: Düğüm): Sayı = 0   // kaç köprüde geçiyor
