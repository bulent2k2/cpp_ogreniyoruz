// KII-2-Z1 · Sıra önemli mi?
// Çıktı: "3: ... ..." ve "4: ... ..." (önce işle-ele, sonra ele-işle)
dez önceİşle3 = (1 |-| 100).işle(s => s * s).ele(k => k % 3 == 0).topla
// önceEle3, önceİşle4, önceEle4
