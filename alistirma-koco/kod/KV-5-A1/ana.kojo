// KV-5-A1 · Dereceler, eşlemle
// Çıktı: "A: 2" satırları, sonra "en çok komşu: C (3)"
dez bağlar = Dizin(("A", "B"), ("A", "C"), ("B", "C"), ("C", "D"), ("D", "E"))
dez komşu = Eşlem[Yazı, Küme[Yazı]]()
// her (a, b) için iki yöne ekle
// dereceler: komşu.dizine.işle { durum (d, k) => (d, k.dizine.boyu) }.sıralı
