#include <iostream>
#include <bits/stdc++.h>

#define INF 20000;

using namespace std;

 int c[3]={1,3,4};
 bool ready[100];
 int value[100];


int solve(int x) {
if (x < 0) return INF;
if (x == 0) return 0;

if (ready[x]) return value[x];

int best = INF;
for (int i=0;i< (sizeof(c)/sizeof(c[0]));i++) {
best = min(best, solve(x-c[i])+1);

}
//memoization
value[x] = best;
ready[x] = true;
return best;
}
int main()
{

 int result = solve(100);
 cout<<"\n"<<result;
}
