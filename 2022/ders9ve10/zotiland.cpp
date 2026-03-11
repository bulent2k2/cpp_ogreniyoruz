#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main(){

int N,M,X;
cin>>N>>M>>X;


vector<pair<int,int>> adj[N+1];
int i,n1,n2,fiyat =0;

set<pair<int,int>> s;

for (int j=1;j<=N;j++)

{
    for (int k=j+1;k<=N;k++)
       s.insert(make_pair(j,k));
}

while (i<M)
{
    i++;
    cin>>n1>>n2>>fiyat;
    adj[n1].push_back(make_pair(n2,fiyat));
    adj[n2].push_back(make_pair(n1,fiyat));
    s.erase(s.find(make_pair(n1,n2)));
   // s.erase(n2,n1);
}

for(auto z:s)
{
    adj[z.first].push_back(make_pair(z.second,X));
    adj[z.second].push_back(make_pair(z.first,X));
  //  s.erase(s.find(make_pair(z.first,z.second)));
}

 int sn=1;

 int dist[N+1];

 for(int i=1;i<=N;i++)
 {
     dist[i]=2000000;
 }
 dist[sn]=0;

 priority_queue<pair<int,int>> pq ;



 pq.push({0,sn});

 bool processed[N+1]={false};

 while (!pq.empty())
 {
     int a=pq.top().second;
     pq.pop();
     if (processed[a]) continue;
     processed[a]= true;
     for (auto u:adj[a])
     {
        int b= u.first;
        int w= u.second;
        if(dist[a]+w<dist[b])
        {
            dist[b]=dist[a]+w;
            pq.push({-dist[b],b});
        }
     }
 }



        printf("%d \n", dist[N]);


 }
