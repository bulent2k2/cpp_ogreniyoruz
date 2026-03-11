#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
  int n;
  int max_first, max_second,result;
  result = 0;

  cin>>n;
  vector<int> M(n+1);
    for(int i=1;i<=n;i++){
	        cin>>M[i];
	    }


    for(int j=1;j<=n-1;j++)
    {
        max_first=0;
        for(int k=j+1;k<=n;k++)
         {
             max_first=max(max_first,M[k-1]);
             for(int z=k;z<=n;z++)
             {
                  max_second = 0;
                 for(int w=z+1;w<=n+1;w++)
                 {
                    max_second=max(max_second,M[w-1]);
                    if (max_first==max_second)
                       {
                         result++;
                        // cout<<j<<k<<z<<w<<"\n";
                       }
                 }
             }
         }

    }

    cout<<result;
}

