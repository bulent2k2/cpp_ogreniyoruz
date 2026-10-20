// KII-2-I1 · Üçlü, bir de zincir
dez sayılar = Dizin(3, 1, 4, 1, 5, 9, 2, 6)
satıryaz(sayılar.işle(s => s * s).yazıYap(" "))
satıryaz(sayılar.ele(s => s % 2 == 0).yazıYap(" "))
satıryaz(sayılar.indirge((a, b) => a + b))
satıryaz(sayılar.topla)
satıryaz(sayılar.çarp)
satıryaz(sayılar.enİrisi)
satıryaz(sayılar.enUfağı)
// zincir: (1 |-| 100) kareler, 3'e bölünenler, toplam
