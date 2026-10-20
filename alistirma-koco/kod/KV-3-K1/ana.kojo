// KV-3-K1 · Labirentte katmanlar
// Çıktı: "A'dan B'ye 9 adım"
tür Kare = (Sayı, Sayı)
dez plan = Dizin("########", "#.A#...#", "#.##.#B#", "#......#", "########")
tanım boşMu(k: Kare): İkil = { dez (y, x) = k; y >= 0 && y < plan.boyu && x >= 0 && x < plan(0).boyu && plan(y)(x) != '#' }
tanım komşular(k: Kare): Küme[Kare] = {
  dez (y, x) = k
  Küme((y - 1, x), (y + 1, x), (y, x - 1), (y, x + 1)).ele(boşMu)
}
tanım katmanlar(komşu: Kare => Küme[Kare], sınır: Küme[Kare], gezilen: Küme[Kare]): Dizin[Küme[Kare]] = Boş
// A ve B'yi bulun, katmanları alın, B'nin katmanı
