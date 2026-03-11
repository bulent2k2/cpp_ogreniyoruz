#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int x(int s, vector<int> c, vector<int> d);
int y(int s, vector<int> d,vector<int> c );

int x(int s, vector<int> c, vector<int> d)
{
    if (s==1)
        return c[1];
    int x_sonuc;
    x_sonuc = min(y(s-1,d,c)+c[s],x(s-1,c,d)+max(c[s]-c[s-1],0));
    return(x_sonuc);
}

int y(int s, vector<int> d,vector<int> c )
{
    if (s==1)
        return d[1];
    int y_sonuc;
    y_sonuc = min(x(s-1,c,d)+d[s],y(s-1,d,c)+max(d[s]-d[s-1],0));
    return(y_sonuc);
}


int main(){
  int n,k;

  cin>>n>>k;
  vector<int> a(n+1);
    for(int i=1;i<=n;i++){
	        cin>>a[i];
	    }

   vector<int> b(n+1);
    for(int i=1;i<=n;i++){
	        cin>>b[i];
	    }

   vector<int> c(n+1);
   vector<int> d(n+1);
    for(int i=1;i<=n;i++){
	       c[i]=(a[i]-b[i])%k;
	       if (c[i]<=0)
            c[i]=c[i]+k;
           d[i]=k-c[i];
	    }

 int sonuc;
 sonuc = min(x(n,c,d),y(n,d,c));

 cout<<sonuc;

    }

