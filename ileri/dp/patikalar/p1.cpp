#include <iostream>
#include <limits>

// int yetmez
const long LIMIT = std::numeric_limits<long>::max();

const int N=1001;
// pe15 için: 20x20 0 vermeli:
// const long MOD = 137846528820;
const long MOD = 1e9 + 7;
long bellek[N][N];

long patikalar(int x, int y) {
  if (x == 1) return y+1;
  if (y == 1) return x+1;
  long p1=bellek[x-1][y], p2=bellek[x][y-1];
  if (p1 == 0) {
    p1 = patikalar(x - 1, y);
    bellek[x-1][y] = p1;
  }
  if (p2 == 0) {
    p2 = patikalar(x, y - 1);
    bellek[x][y-1] = p2;
  }
  return (p1 + p2) % MOD;
}

long bul(int n) {
  return patikalar(n, n) % MOD;
}

int main() {
  std::cout << LIMIT << '\n'
	    << MOD << '\n';

  for(int x=1; x<N; ++x)
    for(int y=1; y<N; ++y)
      bellek[x][y] = 0;

  for(int s=2; s < N; ++s) 
    std::cout << s << 'x' << s << "=" << bul(s) << '\n';

  return 0;
}
