> [Önceki](ders1-4.md) [Hepsi](icindekiler.md) [Sonraki](ders6.md)

*Tam bölünebilen sayıları sayma, komut satırından derleyici çalıştırma. Ayrıca Windows'a Terminal, C++ Derleyici ve Emacs ya da başka Editör eklemek için gerekli linkler.*  

[Project Euler Birinci Problem](https://projecteuler.net/problem=1)  3'e ve 5'e bölünen sayıların toplamını bulmak için beraber kod yazdık. İki kaynak dosyamız var. **ana.cpp**:  
```c++
#include <iostream>

using namespace std;

int p1();

int main() {
  cout << "Project Euler, birinci problem: ";
  cout << p1() << endl;
  return 0;
}
```  
ve **prob1.cpp**  
```c++
#include <iostream>

bool bölünüyorMu(int sayı, int bölen) {
  return sayı % bölen == 0;
}

int p1() {
  int toplam{0};

  for (int sayı{3}; sayı < 1000; ++sayı) {
    if (bölünüyorMu(sayı, 3)) {
      toplam = toplam + sayı;
    }
    if (bölünüyorMu(sayı, 5)) {
      toplam += sayı;
    }
    if (bölünüyorMu(sayı, 15)) {
      toplam -= sayı;
    }
  }
  return toplam;
}
```
Derlemek ve link etmek için, terminalde c++ programını çalıştırdık:  
```shell
% c++ -std=c++23 ana.cpp prob1.cpp -o program
```
Sonra da yanıtı bulduk:
```shell
% program                                    
Project Euler, birinci problem: 233168
```

Ayrıca, bazı terminal komutlarını gördük: **pwd, ls, mkdir, cd**, vb. GitHub'daki bu sayfayı ve altındaki kodları kendi bilgisayarımıza indirmek için:  
```bash
% git clone https://github.com/bulent2k2/cpp_ogreniyoruz
% cd cpp_ogreniyoruz 
% cd e1
% ls
Makefile	e1b.cpp		e1da.cpp
e1a.cpp		e1c.cpp		e1db.cpp
% c++ e1a.cpp
% a.out
233168
% c++ -c e1a.cpp
% c++ -o prob1 e1a.o
prob1
233168
%
``` 

[Unix Terminal komutları hakkında daha ayrıntılı bilgi](https://acikders.ankara.edu.tr/pluginfile.php/155213/mod_resource/content/0/10.1.%20Linux%20Komutlar%C4%B1.pdf)  

Yukarıda **e1a.o** örneğinde gördüğümüz **object code** (nesne ya da makine kodu) hakkında konuştuk. Derleyicinin **-c** seçeneğini kullanarak birkaç örnek derledik ve sonra linker'la (**-c** kullanmadan) programı oluşturduk ve çalıştırdık.  

Gelecek hafta için üç ödevimiz var. Fırsat buldukça, yapabildiğimiz kadar yapalım:  
1) [Project Euler Hakkında](https://projecteuler.net/about) sayfasını istersek İngilizce ya da Türkçeye tercüme ettirip okuyuverelim ve kendimize bir oturum açalım. Sonra da birinci sorunun yanıtını girelim. Doğru yanıtı girince bize sunulan PDF dosyasını okuyalım.
1) Windows bilgisayarımıza cygwin terminal indirmek ve cygport paketiyle c++ derleyiciyi (ve arzu edersek Emacs editörünü) yüklemek. Linkler hemen aşağıda. Cygwin64 terminalini çalıştırın ve **pwd** komutunu girin. Size **/home/<kullanıcı-adı>** gibi bir çıktı verir. Bu **C:\cygwin64\home\<kullanıcı-adı>** diziniyle bir. Unix ve Windows arasındaki farklardan biri de bu. Yukarıda gördüğümüz **git** ve **c++** komutlarını da deneyin. Çalışmazsa Bülent hocaya danışıverin.
2) [Project Euler 15. Problem](https://projecteuler.net/problem=15) satranç tahtasında iki çapraz köşe arasındaki en kısa yolları nasıl sayabiliriz? 2x2 tahtada 6 yol var. Ya 3x3'te?

Windows'da Terminal, C++ Derleyici ve Editör
--
[Windows'a linux benzeri terminal ekle (cygwin)](https://cygwin.com/install.html) + 
[Cygwin'e c++ derleyici eklemek için cygport paketini indir](https://stackoverflow.com/questions/44354169/how-to-install-g-in-cygwin?newreg=f4dff0a25415471fa12f1dd8c109a3fe) +   
ilk program `deneme.cpp` diye bir dosya olsun: 
```bash
$ c++ deneme.cpp -o dene
$ ./dene
```
[Bir de emacs editor iyi olur](https://ftp.gnu.org/gnu/emacs/windows/emacs-29/emacs-29.4-installer.exe). Eski ama [özgür bir yazılım](https://www.gnu.org/software/emacs/). [Özgür yazılım vakfı](https://fsf.org) ve pekçok gönüllü tarafından geliştiriliyor ve destekleniyor.    
[Bu da modern VS Code editörü ve IDE'si](https://code.visualstudio.com/). Bunda yazıp bizim cygwin terminalinde derlemeyi ve çalıştırmayı deneyebilirsiniz. 

> [Önceki](ders1-4.md) [Hepsi](icindekiler.md) [Sonraki](ders6.md)
