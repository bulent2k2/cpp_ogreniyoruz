#include <iostream>
#include <bits/stdc++.h>

#define INF 20000;

using namespace std;

 int c[3]={1,3,4};

int solve(int x) {
if (x < 0) return INF;
if (x == 0) return 0;
int best = INF;
for (int i=0;i< (sizeof(c)/sizeof(c[0]));i++) {
best = min(best, solve(x-c[i])+1);

}
return best;
}
int main()
{

 int result = solve(20); //100'ü deneyelim
 cout<<"\n"<<result;
}
