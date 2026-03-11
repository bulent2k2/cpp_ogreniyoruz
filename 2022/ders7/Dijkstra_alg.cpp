#include <bits/stdc++.h>

using namespace std;



int main(){


 int N=6; // graph'daki node sayýsý (1'den baþlamak için 5 node için 6 girdim.
 vector<pair<int,int>> adj[N]; //komþuluk gösterimi için

 //slayt 54'deki örnek için graphý oluþturalým
 adj[1].push_back({2,5});              //adj[1].push_back(make_pair(2,5));
 adj[1].push_back(make_pair(5,1));     //adj[1].push_back({5,1});
 adj[2].push_back({1,5});
 adj[2].push_back({3,2});
 adj[3].push_back({2,2});
 adj[3].push_back({4,6});
 adj[4].push_back({3,6});
 adj[4].push_back({5,2});
 adj[5].push_back({4,2});
 adj[5].push_back({1,1});

 int sn=1; //starting node'u 1 olarak belirledik.

 int dist[N];

 for(int i=1;i<=N;i++)
 {
     dist[i]=2000000;
 }
 dist[sn]=0;

 priority_queue<pair<int,int>> pq ;// ilkine weight, ikincisine node deðerini yazalým.

 //  eðer pq.top() ile en büyük weight deðeri yerine en küçük wegiht deðerini almak istersem alttaki gibi yazmam lazým
 // ancak weighti eksi girerek buna gerek kalmayacak.
 //  priority_queue< iPair, vector <iPair> , greater<iPair> > pq;


 pq.push({0,sn});

 bool processed[N]={false}; // eðer bir node seçilmiþse onunla ilgili tekrar iþlem yapmamak için, initial deðer false olmalý

 while (!pq.empty())
 {
     int a=pq.top().second; //weight deðeri en büyük(küçük) olan node'u buluyoruz. weighti negatif gireceðiz
     pq.pop();
     if (processed[a]) continue;
     processed[a]= true;
     for (auto u:adj[a])
     {
        int b= u.first; //node'un numarasý
        int w= u.second; //node'un weight deðeri
        if(dist[a]+w<dist[b])
        {
            dist[b]=dist[a]+w;
            pq.push({-dist[b],b}); // eðer nodeun uzaklýk deðeri azaldýysa pq listesine ekledik.
        }
     }
 }


 for (int i = 1; i < N; ++i)
        printf("%d \t\t %d\n", i, dist[i]);


 }
