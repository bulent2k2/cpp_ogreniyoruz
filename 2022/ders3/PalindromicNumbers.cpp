#include <bits/stdc++.h>

using namespace std;



int main()
{
int n, t, sayi,sayi1, x;
string m, result;

cin>>t;
while (t--)
{
cin>>n;

cin>>m;
//cout<<result;
if (m[0]!='9')
{

 for(int i=0;i<n;i++)
{
  //  sayi = m[i]-'0';  //string deðeri sayýya çevirmek için

  //  result[i]=(9-sayi)+'0';
 // sayi = stoi(m[i]);

     cout<<'9'-m[i];
}
 cout<<"\n";
}
x =0; //elde var bir,(bir önceki basamaktaki toplam 10'dan büyükse değeri 1 azaltmak için)
if (m[0]=='9')
{


 for(int i=n-1;i>=0;i--)
{
    sayi = m[i]-'0';  //string deðeri sayýya çevirmek için

   m[i]=(11-sayi-x)%10+'0';
    sayi1 = m[i]-'0';

   if ((sayi+sayi1)>=10)
   x=1; else x=0;


}

  cout<<m;
  cout<<"\n";
 }

}
}


