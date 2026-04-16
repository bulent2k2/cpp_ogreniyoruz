> [Önceki](ders8.md) [Hepsi](icindekiler.md) [Sonraki](ders10.md)

*Eşlem kalıbını pekiştirmek için örnekler, matematiksel tam sayı fonksiyonları, `makefile` ve `make` uygulaması ile otomasyon, karmaşık sayı türüyle *nesne yönelimine* hızlı giriş.*  

[Görsel kayıt](https://drive.google.com/file/d/1zwkZlNUy0wBKcLLF9hJN__ogHwUnTavp/view). 51:54 uzunluğunda.   

Önce geçen dersi tekrar ettik.  

Çok yararlı *eşlem* türü (*std::map*) üzerinde durduk. Önce birlikte küçük bir örnek yazdık. Harfleri sayılarla eşledik:
```c++
#include <iostream>
#include <map>

using std::cout, std::endl;
typedef std::map<char, int> eşlem;
int bak(eşlem e, char h);
void yaz(int n) { cout << "bak işlevinin çıktısı: " << n << endl; }

int main() {

  eşlem e1{
    {'a', 10},
    {'b', 20},
    {'z', 999}
  };
  for(auto [harf, sayı] : e1)
    cout << harf << " -> " << sayı << endl;

  char birHarf{'c'};
  int çıktı{bak(e1, birHarf)}; yaz(çıktı);
  cout << e1[birHarf] << endl; // Hata! Bu yanlışı yapmayalım ileride
  çıktı = bak(e1, birHarf); yaz(çıktı);
  çıktı = bak(e1, 'z'); yaz(çıktı);
  
  return 0;
}

int bak(eşlem e, char h) {
  if (e.contains(h)) {
    cout << h << " eşi: " << e[h] << endl;
    return e[h];
  } else {
    cout << h << "'nin eşi yok.\n";
    return -1;
  }
}
```

Derste `bak` işlevinin çıktı türünü `char` olarak belirlemiştik. Doğrusu `int` olacak. Hataya rağmen çalışmıştı. [Nedeni burada](https://www.sololearn.com/en/compiler-playground/cjfGIRFAb144). Derleyicinin uyarısına dikkat. Daha çok bilgi için: [stackoverflow-implicit-conversion](https://stackoverflow.com/questions/48650685/c-implicit-conversion-of-int-to-char).  

Derleme ve çalıştırmayı hızlandırmak için de bir `makefile` yazdık:
```Makefile
# bu dosyadaki ilk hedefle başlar yapmaya (make programı)
# <hedef>: <birinci alt hedef> <ikinci alt hedef> ...
hedefler: derle çalıştır

derle: prog

# ana.cpp dosyası prog dosyasından yeni tarihliyse c++ derleyicisini çağırır:
prog: ana.cpp
	c++ -std=c++23 ana.cpp -o prog

çalıştır:
	./prog
```

Komut satırında: `make` yazmak yetti. Hatta, direk [*Emacs* editorü içinde](https://www.gnu.org/software/emacs/) `compile` komuduyla işimiz daha da kolay. 

İkinci örnek olarak geçen dersten 2025'in sayısal süprizlerini bulduğumuz koda baktık ve ufak bir değişiklik yaptık:  

[Matematiksel tam sayı fonksiyonu](https://onlinegdb.com/37o_p7vq3).   

Onuncu satırda `Fonksiyon` türünü iki `int` değerin eşleşmesi olarak tanımladık. Otuz ikinci satırda iki tane `Fonksiyon` tanımladık, `f` ve `f2` adında. 34 ve 35 satırlarında `f(x)` ve `f2(x)` değerlerini tanımladık. Sonra da fonksiyonları iki farklı `for` döngüsüyle yazdırdık.

En son beş dakikada *karmaşık sayı* örneğiyle `struct` ya da `class` kullanarak yeni bir tür tanımlamaya hızlı bir giriş daha yaptık: 
[Karmaşık (varsıl) sayı kodu](https://onlinegdb.com/SybVZuiJ_). `operator<<` işlevine baktık çabucak. Gelecek derste devam ederiz inşallah. Bu arada şu linklere bakıverin:  
1) [Khan Akademisinden Karmaşık Sayı dersi](https://tr.khanacademy.org/math/precalculus/imaginary-and-complex-numbers).  
[Bilhassa güç döngüsünü gösteren giriş görseli](https://tr.khanacademy.org/math/precalculus/imaginary-and-complex-numbers/the-imaginary-numbers/v/introduction-to-i-and-imaginary-numbers).  
2) [Vikipedi maddesi](https://tr.wikipedia.org/wiki/Karmaşık_sayı).  
3) [Mandelbrot kümesi](https://tr.wikipedia.org/wiki/Mandelbrot_k%C3%BCmesi). Karmaşık sayı düzleminde tanımlanan bir küme. Sınırı hem var, hem yok!    
[John](http://www.eddaardvark.co.uk/index.html) adında bir bilgisayar mühendisi kendi sitesinde hem [Mandelbrot kümesinden](http://www.eddaardvark.co.uk/v2/mandelbrot/webgl.html) hem de bizim [üç kare açılımı](http://www.eddaardvark.co.uk/v2/cube_sums/index.html) konularından bahsediyor. Güzel ve faydalı görseller var.  

**İyi tatiller!**

> [Önceki](ders8.md) [Hepsi](icindekiler.md) [Sonraki](ders10.md)
