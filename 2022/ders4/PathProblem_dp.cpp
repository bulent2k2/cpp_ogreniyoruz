#include <iostream>
#include <bits/stdc++.h>


using namespace std;



int main()
{
 int N=5;
 int sum[6][6]={0};
 int value[N][N]={3,7,9,2,7,9,8,3,5,5,1,7,9,8,5,3,8,6,4,10,6,3,9,7,8};
 for (int y=1;y<=N;y++) {
    for (int x=1;x<=N;x++)
 {

  sum[y][x] = max(sum[y][x-1],sum[y-1][x])+value[y-1][x-1];

 }
 }

cout<<sum[4][4];
}
