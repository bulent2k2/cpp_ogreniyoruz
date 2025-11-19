Kümede küçük olmayan sayı bulma ve sayı çıkarma (*successor with delete*)
====================

Elimizde `n` tane tam sayı, yani şu küme olsun:  
```  K = { 0, 1, ..., n-1 }.```

`x` kümenin bir elemanı olsun. İki tür yöntem yazalım:
  - `x`'i kümeden çıkar.  
  - Kümenin içinde `x`'den küçük olmayan en küçük sayı `y` olsun.  
    Yani en küçük `y ≥ x` neyse onu bulalım.  
    Öyle bir `y` yoksa, çıktı `x-1` olsun.  

Örneğin:
```c++
struct Küme {
    using S=unsigned;
    Küme(S n);
    void çıkar(S x);
    S sonraki(S x);
private:
    // ???
};

void dene() {
  Küme k(5);    // {0, 1, 2, 3, 4} kümesini oluştursun
  k.sonraki(3); // 3 versin
  k.çıkar(3);   // {0, 1, 2, 4}
  k.sonraki(3); // 4
  k.çıkar(4);   // {0, 1, 2}
  k.sonraki(3); // 2
  k.sonraki(4); // 3
  k.sonraki(1); // 1
  k.çıkar(0);   // {1, 2}
  k.çıkar(1);   // {2}
  k.sonraki(0); // 2
  k.çıkar(2);   // {}
  k.sonraki(0); // -1
}
```

Bu küme sınıfını öyle programlayalım ki 
`sonraki()` ve `çıktı()` yöntemleri en azından logaritmik hızla, yani çok hızlı çalışsın. 

Logaritmik olunca kümenin büyüklüğü karesine çıksa, 
çalışma süresi sadece iki kat civarında artıyor. 
Örneğin 5'ten 25'e çıkarsa çalışma süreleri iki kat,
125'e çıkarsa üç kat, 625'e çıkarsa dört kat artsın.
