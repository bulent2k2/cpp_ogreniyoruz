// iki dizinin ortak alt dizileri arasında en uzunlarından birini bulalım
#include <iostream>
#include <string>
#include <vector>

using yazı = std::string;
using std::vector;

yazı en_uzun_ortak_altdizi(yazı y1, yazı y2) {
  int u1 = y1.size(), u2 = y2.size();

  int max=0, // şu ana kadar bulduğumuz en uzun ortak alt dizinin boyu
    sonu; // en uzun ortak alt dizinin son harfinden bir sonraki konum
    
  // boy[k1][k2]: y1[k1-1]'de ve y2[k2-1]'de biten ortak alt dizinin boyu
  vector<vector<int>> boy(u1 + 1, vector(u2 + 1, 0)); // başta hepsi sıfır

  for (int k1 = 1; k1 <= u1; ++k1)
    for (int k2 = 1; k2 <= u2; ++k2)
      if (y1[k1-1] == y2[k2-1]) {
	int uzunluk = boy[k1][k2] = 1 + boy[k1-1][k2-1];
	if (uzunluk > max) {
	  max = uzunluk;
	  sonu = k1;
	}
      }
  
  if (max > 0) return y1.substr(sonu - max, max);
  return yazı{};
}

void dene(yazı y1, yazı y2) {
  std::cout << y1 << " <> " << y2 << " -> <"
	    << en_uzun_ortak_altdizi(y1, y2) << '>' << std::endl;
}

int main() {
  dene("abca", "daxbcby");
  dene("abc", "xyz");
  dene("xyabc", "xydabca");
  dene("abcdxyadb", "xyabcdxybcd");
  return 0;
}
