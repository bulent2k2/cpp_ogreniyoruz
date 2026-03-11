#include <iostream>
#include <bits/stdc++.h>

#define INF 20000;

using namespace std;



int main()
{
 int coins[3]={1,3,4};
 int count1[100]={0};
 count1[0]=1;

 for(int x=1;x<=5;x++){
 for(auto c:coins)
 {
     if(x-c >=0)
     {
         count1[x] += count1[x-c];
     }
 }


 }
cout<<count1[5];
}
