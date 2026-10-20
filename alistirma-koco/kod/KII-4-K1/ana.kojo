// KII-4-K1 · Gişe kuyruğu
// Çıktı: her müşteri için "ad: x dk bekledi", sonra "ortalama: y dk"; sonra yığınla aynısı
dez müşteriler = Dizin(("Ayşe", 5), ("Berk", 2), ("Ceren", 8), ("Deniz", 1), ("Ece", 4))
dez kuyruk = Kuyruk[(Yazı, Sayı)]()
müşteriler.herbiriİçin(m => kuyruk.ekle(m))
// sırayla işle, beklemeleri topla
