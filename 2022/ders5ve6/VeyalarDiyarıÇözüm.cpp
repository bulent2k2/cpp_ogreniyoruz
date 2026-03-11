#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main(){
  int M, N,k, k1, start, finish, sonuc;

  cin>>N;
  vector<int> v(N);
    for(int i=0;i<N;i++){
	        cin>>v[i];
	    }
  vector<int> sonuclar;

 scanf("%d",&M);
 while (M--)
 {
     sonuc =0;
     scanf("%d %d",&k,&k1);
     finish = k-1;
     start =finish-k1;
     for( int j=start;j<=finish;j++)
     {
         sonuc = sonuc | v[j];
     }
     // altgorev 3
     //sonuc = *max_element(v.begin()+start,v.begin()+finish);
     printf("%d",sonuc);
     sonuclar.push_back(sonuc);
 }

    }
