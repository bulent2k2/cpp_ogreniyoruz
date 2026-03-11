#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long n,y,  a, b, first, last,result, sifir, s1,s2 ;
   int x;
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>first>> last;
   x =  log2(n);
   y = (1LL<<x) * 2 - 1 ;


  result = last-first+1;
    for(int i=0; i<=x;i++)
    if(1LL<<i & (y-n) )
     {

       a =  1LL<< (x-i);
       b = a*2;
       sifir = 0;

       s1 = (first-a)/b;
       if (first<a)
        s1 = a;
       else if ((first-a)%b==0)
       s1 = a+b*(s1);
       else
        s1 =a+b*(s1+1);

        s2 = (last-a)/b;
       if (last<a)
        sifir = 0;
       else
       s2 = a+b*(s2);


       if ((last>= a) && (last>=s1 ))
       sifir = (s2-s1)/b+1;
       result = result - sifir;
     }
  if (n==0)
    result = 0;
   cout<<result;
    return 0;
}
