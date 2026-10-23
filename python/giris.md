Python'a Giriş
====

Python, C++'tan sonra en kolay öğrenilen ikinci dil: derleme adımı yok,
tür bildirimi yok, `cin`/`cout` yerine `input()`/`print()`. Kitapçıkta
gördüğünüz her kavramın burada bir karşılığı var: akıllı dizi (`vector`)
yerine liste, eşlem (`map`) yerine sözlük (`dict`), küme yine `set`,
`struct` yerine `class`. İlk program tek satır:

```python
print("Merhaba, dünya")
```

Döngü ve işlev de tanıdık gelecek; girinti süslü parantezin yerini alıyor:

```python
def kare(x):
    return x * x

for n in range(1, 6):
    print(n, kare(n))
```

Nereden devam edilir:  

+ [ders 23](../ileri/ders23.md): C++, Python ve Scala'nın yan yana karşılaştırması.  
+ [Resmî Python öğreticisi (Türkçe)](https://docs.python.org/tr/3/tutorial/): dilin kendi anlatımı, bölüm bölüm.  
+ [Bilgisayar mühendisi gibi düşünme](../notlar/bilgisayar-muhendisi-gibi-dusunme--pythondan-da-ogrenelim.pdf): Python'la algoritma düşünmeyi öğreten, ders 23'te üzerinden geçtiğimiz kitap.  
+ Kitapçığın alıştırmalarını Python'da bir daha çözmek, iki dili de pekiştirir: [Keyifli Alıştırmalar](../alistirma/README.md).
