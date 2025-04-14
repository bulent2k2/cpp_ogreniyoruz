[Görsel kayıt burada](https://drive.google.com/file/d/1N432CdhsD0_aBFxe-MMQoRvW4PzPIJz2). Süresi bir saat 8 dakika. 

Geçen yılın sınav sorularına baktık.

Gelecek ders için iki alıştırma öneriyorum: 

1. Verilen bir sayı dizisinin içinde tekrar var mı yok mu? Nasıl bulabiliriz? En az iki üç değişik yöntem var benim aklıma gelen. Ya siz?  

2. Örnek dizimiz şu olsun: `{4, 2, 3, 1, 3, 2, 1}`. Bunun içinde başı ve sonu aynı olan üç tane alt dizi var:   
  - A1: `{2, 3, 1, 3, 2}`  
  - A2: `{3, 1, 3}`  
  - A3: `{1, 3, 2, 1}`   
İçindeki sayıların toplamı en büyük olan alt dizi A1. Toplamı da 11. Verilen herhangi bir dizi için bu özel toplamı bulan bir işlev yazalım:
```c++
int altToplam(std::vector<int> dizi) {
    // ...
    return 0;
}
```
İpucu: `std::map` yani *eşlem* kalıbı işimizi çok kolaylaştırır.

