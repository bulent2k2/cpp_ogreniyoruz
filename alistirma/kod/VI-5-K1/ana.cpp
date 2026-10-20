#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
using S = long long;
template <class T> using Dizi = vector<T>;

// VI-5-K1 · bul2'yu bitirin
// Çıktı: "7 deneme geçti"
using yazi = std::string;

yazi bul2(const yazi& y1, const yazi& y2) {
    const int boy1 = y1.size(), boy2 = y2.size();
    int enUzun = 0, k = 0;   // şu ana kadarki en uzun ve nerede bittiği
    std::vector<std::vector<int>>
        tane(boy1 + 1, std::vector<int>(boy2 + 1, 0));
    for (int k1 = 0; k1 < boy1; ++k1) {
        for (int k2 = 0; k2 < boy2; ++k2) {
            if (y1[k1] == y2[k2]) {
                int m = tane[k1+1][k2+1] = tane[k1][k2] + 1;
                // ... buradan sonrası size kalıyor
            }
        }
    }
    if (enUzun > 0) return y1.substr(k + 1 - enUzun, enUzun);
    else return yazi{""};
}

int gecen = 0;
void dene(yazi y1, yazi y2, yazi ortak) {
    assert(bul2(y1, y2) == ortak);
    ++gecen;
}

int main() {
    dene("abca",      "daxbcby",    "bc");
    dene("abc",       "xyz",        "");
    dene("xyabc",     "xydabca",    "abc");
    dene("abcdxyad",  "xyabcdxyb",  "abcdxy");
    dene("123",       "345",        "3");
    dene("1010110010","10110",      "10110");
    dene("1110111011","10011",      "011");
    std::cout << gecen << " deneme geçti" << std::endl;
    return 0;
}
