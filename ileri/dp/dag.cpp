/*********************
 * çizge programlama *
 *********************/
#include <iostream>
#include <set>
#include <map>
#include <list>
using Düğüm = char; // node/vertex
using Uzunluk = int; // edge length
using Bağ = std::pair<Düğüm, Uzunluk>; // directed edge
using Bağlar = std::set<Bağ>;
using Çizge = std::map<Düğüm, Bağlar>; // Komşuluk Kümesi
using Gezi = std::list<Düğüm>; // düğümleri sıralamak için
using Küme = std::set<Düğüm>;
using İkili = std::pair<Düğüm,Düğüm>;
using Uzunluklar = std::map<İkili, Uzunluk>; // kolaylık için
using GelenBağlar = std::map<Düğüm, Küme>;

void bağla(Çizge& c, Düğüm a, Düğüm b, Uzunluk boy);
Küme komşular(const Çizge& c, Düğüm d);
GelenBağlar gelenBağlar(const Çizge& c);
Gezi sırala(const Çizge& czg, Düğüm b); // topological ordering
Gezi gez(bool enine, const Çizge& ç, Gezi sıra, Küme atla);

void bağla(Çizge& c, Düğüm a, Düğüm b, Uzunluk boy) {
  Bağ bağ{b, boy};
  if (c.contains(a))
    c[a].insert(bağ);
  else {
    Bağlar küme{bağ};
    c[a] = küme;
  }
}

Küme komşular(const Çizge& c, Düğüm d) {
  Küme k{};
  if (!c.contains(d)) return k; // komşusu olmayabilir
  for (auto [d2, boy]: c.at(d))
    k.insert(d2);
  return k;
}

GelenBağlar gelenBağlar(const Çizge& czg) {
    GelenBağlar gb;
    for (auto [d, bk]:czg)
        for (auto [d2, boy]:bk)
            if (gb.contains(d2)) gb[d2].insert(d);
            else gb[d2] = Küme{d};
    return gb;
}

Gezi sırala(const Çizge& czg, Düğüm b) {
  return gez(true, czg, Gezi{b}, Küme{});
}

Gezi gez(bool enine, const Çizge& çizge, Gezi sıra, Küme atla) {
  if (sıra.size() == 0) return Gezi{};
  auto ilk = sıra.front();
  Küme komşu{komşular(çizge, ilk)};
  for(auto d : atla) komşu.erase(d);
  for(auto d : sıra) komşu.erase(d);
  sıra.pop_front();
  atla.insert(ilk);
  for (auto d : komşu)
    if (enine) sıra.push_back(d); // bfs
    else sıra.push_front(d); // dfs: boyuna ya da derinlemesine
  Gezi gezi{gez(enine, çizge, sıra, atla)};
  gezi.push_front(ilk);
  return gezi;
}

Uzunluklar uzunluklar(const Çizge& czg) {
    Uzunluklar uz;
    for (auto [d, bk] : czg)
        for (auto [d2, u] : bk)
            uz[{d, d2}] = u;
    return uz;
}
Uzunluk toplamBağ(const Uzunluklar& uz) {
    Uzunluk toplam = 0;
    for(auto [ikili, u] : uz)
        toplam += u;
    return toplam;
}
Uzunluk enUzunBağ(const Uzunluklar& uz) {
    Uzunluk max = 0;
    for(auto [ikili, u] : uz)
        if (u > max) max = u;
    return max;
}

void enKısaYollar(const Çizge& czg, Düğüm baş) {
    std::map<Düğüm, Uzunluk> uzaklık{ {baş, 0} };
    Gezi s{sırala(czg, baş)};
    s.pop_front(); // baş düğümü çıkaralım
    Uzunluklar uz{uzunluklar(czg)};
    Uzunluk max = toplamBağ(uz); // yeterli. Sonsuza gerek yok
    GelenBağlar gb{gelenBağlar(czg)};
    using std::cout;
    cout << baş << " düğümünden en kısa yollar:\n";
    for(auto d : s) {
        Küme gelenler{gb[d]};
        Uzunluk min = max;
        for(auto d2:gelenler) {
            Uzunluk bu = uz.at(İkili{d2,d}) + uzaklık[d2];
            if (bu < min) min = bu;
        }
        uzaklık[d] = min;
        std::cout << "  " << d << " düğümüne: "
            << min << '\n';
    }
}

// Dikkat! topo sıralama yetmiyor! s-a-c == s-c-a ama birinci doğru çalışmaz!
void enUzunYollar(const Çizge& czg, Düğüm baş) {
    std::map<Düğüm, Uzunluk> uzaklık{ {baş, 0} };
    Uzunluklar uz{uzunluklar(czg)};
    // topo sırası yetmediği için:
    for(auto d : komşular(czg, baş))
        uzaklık[d] = uz[İkili{baş, d}];
    // todo: aşağıdaki for döngüsü içinde de aynı sorun var
    Gezi s{sırala(czg, baş)};
    s.pop_front(); // baş düğümü çıkaralım
    GelenBağlar gb{gelenBağlar(czg)};
    using std::cout;
    cout << baş << " düğümünden en uzun yollar:\n";
    for(auto d : s) {
        Küme gelenler{gb[d]};
        Uzunluk max = 0;
        for(auto d2:gelenler) {
            if (!uzaklık.contains(d2)) // todo!
                cout << d << " yanlış! Çünkü henüz " << d2 << " hesaplanmamış!\n";
            Uzunluk bu = uz.at(İkili{d2, d}) + uzaklık[d2];
            if (bu > max) max = bu;
        }
        uzaklık[d] = max;
        cout << "  " << d << " düğümüne: "
             << max << '\n';
    }
}

void yap(Çizge & czg) {
  struct Üçlü {
    Düğüm d1, d2;
    Uzunluk boy;
  };
  /*
     Bu örnek şuradan: Vazirani Algorithms Kitabı 6. Bölüm (Dynamic Programming) Sayfa 169
  */
  char S{'s'}, A{'a'}, B{'b'}, C{'c'}, D{'d'}, E{'e'};
  Üçlü üçlüler[] {
    {S, A, 1}, {S, C, 2},
    {C, A, 4}, {A, B, 6}, {C, D, 3}, {B, D, 1},
    {B, E, 2}, {D, E, 1}
  };

  for (auto [a,b,k] : üçlüler) bağla(czg,a,b,k);
}

void yaz(const Çizge & czg) {
    using std::cout;
    cout << "Çizge:\n";
    for(auto [d, bk] : czg) {
        cout << "  " << d << " -> ";
        for(auto [d2, boy] : bk)
            cout << "(" << d2 << " " << boy << ") ";
        cout << "\n";
    }
    Uzunluklar uz{uzunluklar(czg)};
    cout << "Bağ uzunlukları:\n";
    for(auto [ikili, l] : uz)
        cout << "  " << ikili.first << "->"
             << ikili.second << ": "
             << l << '\n';
    cout << "En uzun bağ=" << enUzunBağ(uz) << '\n';
    cout << "Gelen Bağlar:\n";
    GelenBağlar gb{gelenBağlar(czg)};
    for(auto [d, dk]:gb) {
        cout << "  " << d << " <- ";
        for (Düğüm d2:dk)
            cout << d2 << ' ';
        cout << '\n';
    }
    std::cout << "Topo sıralama: ";
    for (auto d : sırala(czg, 's'))
        std::cout << d << ' ';
    std::cout << '\n';
    enKısaYollar(czg, 's');
    enUzunYollar(czg, 's');
}

int main() {
  Çizge czg;
  yap(czg); // çizgeyi oluşturalım
  yaz(czg);
  return 0;
}
