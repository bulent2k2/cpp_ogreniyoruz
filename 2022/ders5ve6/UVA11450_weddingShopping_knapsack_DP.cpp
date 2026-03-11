#include <iostream>
#include <bits/stdc++.h>

using namespace std;



vector<int> G[20];
int dp[201][21];

int buy(int m, int c){
  if (m<0) return -2;      // negative money means no solution
  if (c==0) return 0;      // no more garment to buy, this is a solution
  int &ret = dp[m][c];     // ret is an alias of dp[m][c]
  if (ret!=-1) return ret; // if the current state is already visited, return immediately
  ret = -2;                // initialize this state as having no solution (-2)
  for(int i=0;i<G[c-1].size();i++){    // for all model of this garment
    int ci = G[c-1][i];             // the price of model ci of garment c-1
    if (buy(m-ci, c-1) != -2)       // if this model can produce a solution
      ret = max(ret, buy(m-ci, c-1) + ci);  // update the maximum money spent
  }
  return ret;
}

int main(){
  int N,M,C,K;
  scanf("%d",&N);
  while (N--){
    scanf("%d %d",&M,&C);
    for(int i=0;i<C;i++){
      scanf("%d",&K);
      G[i].resize(K);                        // resize the vector to size K
      for(int j=0;j<K;j++) scanf("%d",&G[i][j]);
    }
    memset(dp,-1,sizeof(dp));
    if (buy(M,C) == -2) puts("no solution"); // -2 means no solution
    else printf("%d\n", buy(M,C));           // this will return the memoized solution
  }
}
