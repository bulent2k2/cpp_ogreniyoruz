Koco için kavramsal bir makine
==============================

> Kogics Foundation'ın **Fundamentals** dizisindeki
> [A notional machine for Kojo](https://docs.kogics.net/concepts/notional-machine.html)
> sayfasının çevirisi. Özgün metin: © 2010-2025 Kogics Foundation,
> CC BY-NC-SA. Çeviri de aynı lisansta; deponun CC BY-SA 4.0 lisansı bu
> dosyayı kapsamaz (bkz. [`LICENSE`](../../LICENSE), 3. bölüm).


Bir **kavramsal makine** (*notional machine*):

+ Bilgisayar donanımının ve bir programın çalışma ortamının öteki
  yönlerinin idealleştirilmiş bir soyutlamasıdır.
+ Bir programın çalıştırıldığında ne yaptığının kavramsal olarak doğru
  biçimde anlatılmasına izin verir.

Kavramsal makinenin amacı, bilgisayar programlarını anlamanıza,
yaratmanıza ve hatalarını bulmanıza yardım etmektir.

Kojo için bir kavramsal makine:

+ Çalışan programlar bellekte yaşar; bellek bir **kod alanı**, bir
  **öbek** (*heap*) ve bir **çağrı yığını** (*call stack*) arasında
  bölüşülür.
  - Kod alanı, bir programın kodunun yüklendiği yerdir.
  - Öbek, bir programın verisinin yaratıldığı ve yaşadığı yerdir.
  - Çağrı yığını, yerel değişkenlerin ve adlandırılmış değerlerin,
    komut/işlev girdilerinin ve parametrelerinin (onlar da adlandırılmış
    değer gibidir) ve komut/işlev çıktılarının, yani dönüş değerlerinin
    yaşadığı yerdir.
+ Her veri parçası bir **nesnedir**. Nesne; verinin kendisini, verinin
  türüyle ilgili bilgiyi ve bu türle çalışan koda bir başvuruyu içerir.
  Kod, bir sürü komut ve işlevdir; bunlara nesnenin **yöntemleri** denir.
  Bir veri parçasına gündelik dilde **değer** de denir.
+ Bir **`dez`**, bir değere sabit başvurudur. Bir adın bir değere
  değiştirilemez biçimde bağlanması diye düşünebilirsiniz.
+ Bir **`den`**, bir değere başvurudur. Bir adın bir değere değiştirilebilir
  biçimde bağlanması diye düşünebilirsiniz. Bu bağ, programınızın başka
  bir noktasında başka bir değere çevrilebilir.
+ Bir veri parçası başka veri parçalarından yapılmış olabilir, ya da
  **atomik** olabilir. Atomik veri yalnızca kendi değerini içerir.
  Atomik olmayan veri, farklı parçalarına başvuran `dez`ler/`den`ler
  içerir.
+ Bazı veri türleri yaratıldıktan sonra hiç değiştirilmez; örneğin
  `İkil`, `Sayı`, `Kesir`, `Yazı`, `Dizi`, `Dizin` vb. Bunlara
  **değişmez** (*immutable*) veri türleri denir. Ya atomiktirler ya da
  `dez`lerden yapılmışlardır.
+ Başka veri türleri yaratıldıktan sonra değiştirilebilir; örneğin
  `EsnekDizik` (*ArrayBuffer*), kıyma eşlemleri ve kıyma kümeleri
  (*HashMap*, *HashSet*). Bunlara **değişebilir** (*mutable*) veri
  türleri denir. `den`lerden yapılmışlardır.
+ Kod belleğe yüklendiğinde, Kojo onu kod alanında saklanan bir komut
  dizisine çevirir.
+ Kod, bir nesnenin içine konarak veri gibi ele alınabilir. Bu yüzden
  komutları/işlevleri `dez`lere/`den`lere atamak ve onları başka
  komutlara/işlevlere girdi/parametre olarak geçirmek mümkündür.
+ Kod çalıştırıldığında, Kojo koddaki komutları tek tek gezer ve her
  birinin söylediğini sırası geldiğinde yapar.
+ Bazı komutlar Kojo'ya veri okutur (sorgular), hesap yaptırıp yeni veri
  yaratır (işlevler) ve eylemler yürütür (komutlar). Başka komutlar ise
  Kojo'nun hangi komutları çalıştıracağını denetler (bunlar çoğunlukla
  anahtar sözcük komutlarıdır); döngü ve seçim böyle çalışır.
+ Herhangi bir komutun ya da işlevin çağrılması bir **çağrı/dönüş** ile
  olur.
  - Bir komut ya da işlev çağrıldığında Kojo yeni bir **yığın çerçevesi**
    yaratıp çağrı yığınına ekler. Komuta/işleve girdiler ve parametreler
    bu çerçeveyle sağlanır.
  - Bir yöntem, bir nesne üstünde nokta gösterimiyle çağrıldığında, nesne
    de yöntemin bir girdisi/parametresi sayılır.
  - Her yığın çerçevesi, komutun/işlevin içinde yaratılan `dez`/`den`
    adlarını ve bu adlara karşılık gelen veriye başvuruları saklar.
    Komut/işlev girdileri ve parametreleri, yığın çerçevesindeki birer
    `dez`den başka bir şey değildir.
  - Bir `dez`/`den` kullanıldığında Kojo onu geçerli yığın çerçevesinde
    arar. Orada yoksa en üst düzeydeki (küresel) çerçevede arar.
  - Bir komut ya da işlev bittiğinde Kojo onun yığın çerçevesini çağrı
    yığınından siler, çağrıdan önce çalıştırdığı komutlara geri döner ve
    çağrıdan sonraki komutla devam eder.
  - Bir işlev, bir değer döndürür (hesabının sonucu olan değeri) — kendi
    yığın çerçevesinden çağıranın yığın çerçevesine kopyalayarak. O
    değeri uygun biçimde kullanmak, sonraki komutun sorumluluğudur;
    yoksa değer programda kullanılmadan kalır.
  - Bir komut, sonraki komuta birim değeri `()` döndürür (bu da yine
    kendi çerçevesinden çağıranın çerçevesine kopyalanarak). Birim
    değeri `()` hiçbir bilgi belirtmez. Sonraki komut yoksa program
    biter.


Kavramsal makineler üzerine daha çok
--

Özgün sayfa, *Teaching Tech Together* kitabının
[kavramsal makineler bölümüne](https://teachtogether.tech/en/index.html#s:models-notional)
bağlanıyor (İngilizce). Oradaki fikrin özü şu: *hesaplamalı düşünme*
teriminin kapsamını tartışmak yerine, öğrencilerin anlamasını istediğiniz
**kavramsal makineyi** düşünmek daha yararlıdır. Kitap, tanımı Sorva'dan
alıyor: kavramsal makine, donanımın ve çalışma ortamının idealleştirilmiş
bir soyutlamasıdır; programların anlamının anlatılmasına izin verir; ve
programların çalıştırıldığında ne yaptığını doğru yansıtır. Kitabın
yazarı, yukarıdakine çok benzeyen bir listeyi Python için veriyor ve şöyle
diyor: Python öğretirken bu karikatür gerçekliği kullanıyorum; yaklaşık 25
saatlik dersten ve öğrencilerin kendi başına 100 saatlik çalışmasından
sonra, çoğunun zihinsel modelinde bu özelliklerin çoğunun ya da hepsinin
bulunmasını bekliyorum.
