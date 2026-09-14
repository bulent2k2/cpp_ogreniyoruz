Oyun tarifleri
==============

> Kogics Foundation'ın Kojo belgelerindeki
> [Gaming How-to code snippets](https://docs.kogics.net/howtos/gaming.html)
> sayfasının çevirisi. Özgün metin: © 2010-2025 Kogics Foundation,
> CC BY-NC-SA. Çeviri de aynı lisansta; deponun CC BY-SA 4.0 lisansı bu
> dosyayı kapsamaz (bkz. [`LICENSE`](../../LICENSE), 3. bölüm).
> Kod örnekleri Koco'nun Türkçe adlarıyla yazıldı.


Oyun yazarken sık gereken altı küçük tarif. Her biri kendi başına
çalışan, kopyalayıp iKojo'ya yapıştırabileceğiniz bir yazılımcık.

+ [Bir resmi verilen bir konuma doğru hareket ettirmek](#bir-resmi-verilen-bir-konuma-doğru-hareket-ettirmek)
+ [Resme tıklanınca yeni bir resim çizmek](#resme-tıklanınca-yeni-bir-resim-çizmek)
+ [İki resmin aynı yöne baktığını sınamak](#iki-resmin-aynı-yöne-baktığını-sınamak)
+ [Mermi atmak](#mermi-atmak)
+ [Oyunu başlatmak için bir düğmeye tıklamak](#oyunu-başlatmak-için-bir-düğmeye-tıklamak)
+ [Çarpışma sınaması için sıcak noktalı resimler](#çarpışma-sınaması-için-sıcak-noktalı-resimler)


Bir resmi verilen bir konuma doğru hareket ettirmek
--

```scala
// bir dikdörtgenin fare imlecine doğru gittiği bir örnek
temizle()
dez resim = Resim.dikdörtgen(50, 50)
çiz(resim)

canlandır {
    dez fk = fareKonumu
    // fk artık fare imlecinin o anki yerinin x, y'sini tutuyor
    dez konum = resim.konum

    dez hız = Yöney2B(fk.x - konum.x, fk.y - konum.y).boyunuBirYap * 3
    resim.taşı(hız)
}
```


Resme tıklanınca yeni bir resim çizmek
--

```scala
temizle()
dez resim = Resim {
    kalemRenginiKur(Renkler.siyah)
    boyamaRenginiKur(Renkler.yeşil)
    yinele(4) {
        ileri(100)
        sağ(90)
    }
}
resim.konumuKur(100, 100)
resim.fareyeTıklayınca { (x, y) =>
    dez yeniResim = Resim {
        kalemRenginiKur(Renkler.siyah)
        kalemKalınlığınıKur(4)
        sağ(45)
        ileri(100)
    }
    yeniResim.konumuKur(x, y)
    // dikkat: `yeniResim`, `resim`in üstüne çizilecek. Yani `yeniResim`in
    // sınırları içindeki fare tıklamaları `resim`e ulaşmayacak
    çiz(yeniResim)
}
çiz(resim)
```


İki resmin aynı yöne baktığını sınamak
--

```scala
temizle()
dez resim1 = Resim {
    yinele(4) {
        ileri(100)
        sağ(90)
    }
}

dez resim2 = Resim {
    yinele(4) {
        ileri(100)
        sağ(90)
    }
}

resim2.konumuKur(200, 0)
resim2.döndür(-45)

çiz(resim1, resim2)
satıryaz(resim1.doğrultu)

tanım doğrultularAynıMı(r1: Resim, r2: Resim) = {
    r2.doğrultu % 360 == r1.doğrultu % 360
}
canlandır {
    eğer (tuşBasılıMı(tuşlar.sol)) {
        resim2.döndür(1)
        satıryaz(resim2.doğrultu)
    }

    eğer (tuşBasılıMı(tuşlar.sağ)) {
        resim2.döndür(-1)
        satıryaz(resim2.doğrultu)
    }

    eğer (doğrultularAynıMı(resim1, resim2)) {
        çizMerkezdeYazı("Kazandın", yeşil, 30)
        canlandırmayıDurdur()
    }
}
tuvaliEtkinleştir()
```

*Çevirmen notu:* son satır önemli — `tuvaliEtkinleştir()` olmadan tuvale
klavye odağı gelmiyor ve ok tuşları işlemiyor.


Mermi atmak
--

```scala
temizle()
çizSahne(beyaz)
dez ts = tuvalSınırları

tanım yeniMermi = {
    boyaRengi(kırmızı) -> Resim.dikdörtgen(2, 5)
}

den mermiler = Küme[Resim]()

yineleSayaçla(1000) {
    dez m = yeniMermi
    mermiler = mermiler.ekli(m)
    çiz(m)
    m.konumuKur(ts.solu + 20, ts.altı + 5)
    m.açıyaDön(-rastgele(45))
}

canlandır {
    mermiler.herbiriİçin { m =>
        m.taşı(0, 5)
    }

    mermiler.herbiriİçin { m =>
        eğer (m.çarpışıyorMu(sahneKenarı)) {
            mermiler = mermiler.çıkarılmış(m)
            m.sil()
        }
    }
}
```

*Çevirmen notu:* özgün kod mermileri `HashSet`te tutuyor. Koco'nun
`Küme`si değişmez ve değişebilir kümenin henüz Türkçe adı yok; bu yüzden
burada `den` ile tanımlı bir `Küme` var — eklemek `ekli`, çıkarmak
`çıkarılmış`. İşleyişi aynı. Aynı örnek
[Skala kısa kılavuzunda](6-skala-kisa-kilavuz.md) da geçiyor (kaplar
bölümünün sonunda).


Oyunu başlatmak için bir düğmeye tıklamak
--

```scala
temizle()
çizSahne(siyah)
dez oyuncu = Resim.dikdörtgen(100, 60)
oyuncu.konumuKur(100, 100)
çiz(oyuncu)
den hız = Yöney2B(2, 3)
den etkin = yanlış
canlandır {
    eğer (etkin) {
        asılCanlandırma()
    }
}

tanım asılCanlandırma(): Birim = {
    oyuncu.taşı(hız)
    eğer (oyuncu.çarpışıyorMu(sahneKenarı)) {
        hız = sahneKenarındanYansıtma(oyuncu, hız)
    }
}

dez başlaDüğmesi = Resim {
    // bunu yapmanın daha kolay yolları var
    // ama şimdilik kaplumbağa çizimiyle idare edelim
    boyamaRenginiKur(yeşil)
    kalemRenginiKur(mavi)
    yinele(2) {
        ileri(60)
        sağ(90)
        ileri(130)
        sağ(90)
    }
    konumuKur(30, 50)
    yazıBoyunuKur(30)
    kalemRenginiKur(siyah)
    yazı("Başla")
}

çiz(başlaDüğmesi)
başlaDüğmesi.fareyeTıklayınca { (x, y) =>
    etkin = doğru
    başlaDüğmesi.sil()
}
```


Çarpışma sınaması için sıcak noktalı resimler
--

Bu biraz çetrefil: sıcak noktası olan bir resmi döndürürken hem küresel
koordinat dizgesini hem sıcak noktanın yerel koordinat dizgesini takip
etmek gerekiyor.

```scala
temizle()

sınıf SıcakNoktalıResim(resim: Resim, noktaX: Kesir, noktaY: Kesir, noktaYarıçapı: Kesir) {
    dez sıcakNokta = Resim.daire(noktaYarıçapı)
    sıcakNokta.kalemRenginiKur(Renkler.mavi)
    sıcakNokta.kalemKalınlığınıKur(1)

    tanım çiz(): Birim = {
        resim.çiz(); sıcakNokta.çiz()
    }

    tanım döndür(a: Kesir): Birim = {
        resim.döndür(a)
        sıcakNokta.döndürMerkezli(a, -noktaX, -noktaY)
    }

    tanım konumuKur(x: Kesir, y: Kesir): Birim = {
        resim.konumuKur(x, y)
        sıcakNokta.konumuKur(x + noktaX, y + noktaY)
    }

    tanım sıcakNoktaÇarpışıyorMu(öbürü: SıcakNoktalıResim): İkil = {
        sıcakNokta.çarpışıyorMu(öbürü.sıcakNokta)
    }

    tanım boyamaRenginiKur(r: Renk): Birim = {
        resim.boyamaRenginiKur(r)
    }

    konumuKur(0, 0)
}

dez resim1 = Resim {
    boyamaRenginiKur(Renkler.yeşil)
    kalemKalınlığınıKur(0)
    yinele(4) {
        ileri(100)
        sağ(90)
    }
}

dez snr1 = yeni SıcakNoktalıResim(resim1, 2, 98, 2)
snr1.konumuKur(50, 0)

dez resim2 = Resim {
    boyamaRenginiKur(Renkler.kahverengi)
    kalemKalınlığınıKur(0)
    yinele(4) {
        ileri(50)
        sağ(90)
    }
}

dez snr2 = yeni SıcakNoktalıResim(resim2, 48, 2, 2)
snr2.konumuKur(-100, 0)

snr1.çiz()
snr2.çiz()

canlandır {
    snr1.döndür(1)
    eğer (snr1.sıcakNoktaÇarpışıyorMu(snr2)) {
        snr2.boyamaRenginiKur(kırmızı)
        canlandırmayıDurdur()
    }
}
```

*Çevirmen notu:* özgün sayfa `PicWithHotspot` sınıfının alanlarını
`pic`, `spotX`, `spotY`, `spotRadius` diye adlandırıyor; burada Türkçeye
çevirdiler. Sınıfın içindeki `çiz()`, `döndür(...)`, `konumuKur(...)` ve
`boyamaRenginiKur(...)` yöntemleri, aynı adlı genel komutları **gölgeler**
(*shadow*) — ama gövdelerinde her çağrı bir resmin üstünden
(`resim.çiz()`, `sıcakNokta.döndürMerkezli(...)`) yapıldığı için sorun
çıkmıyor.
