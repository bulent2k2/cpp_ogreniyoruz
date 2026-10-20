// KIII-1-A2 · Hesapta da tekrar etmeyin
// Çıktı: 233168
dez üçler = (1 |- 1000).ele(s => s % 3 == 0).topla
dez beşler = (1 |- 1000).ele(s => s % 5 == 0).topla
dez onbeşler = (1 |- 1000).ele(s => s % 15 == 0).topla
satıryaz(üçler + beşler - onbeşler)
