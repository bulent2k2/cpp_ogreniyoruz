#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main(){

 int N=7; //node sayısını bir fazla yazdım
 vector<pair<int,int>> adj[N];
 adj[1].push_back({2,3});
 adj[2].push_back({1,3});

 adj[1].push_back(make_pair(5,5));
 adj[5].push_back(make_pair(1,5));

 adj[2].push_back({3,5});
 adj[3].push_back({2,5});

 adj[2].push_back({5,6});
 adj[5].push_back({2,6});

 adj[3].push_back({4,9});
 adj[4].push_back({3,9});

 adj[3].push_back({6,3});
 adj[6].push_back({3,3});

 adj[4].push_back({6,7});
 adj[6].push_back({4,7});

 adj[5].push_back({6,2});
 adj[6].push_back({5,2});


 int sn=1; //baslangıc node'u


 priority_queue<pair<int,int>> pq ;

 pq.push({0,sn});

bool processed[N]={false};

int total_weight=0;
int a;

 while (!pq.empty())
 {
     a = pq.top().second;

     if(!processed[a])
     total_weight = total_weight - pq.top().first;

     pq.pop();

     if (processed[a]) continue;
     processed[a]= true;
     for (auto u:adj[a])
     {
        int b= u.first;
        int w= u.second;

        if(!processed[b])
        {
            pq.push({-w,b});
        }
     }
 }


         printf("%d \n", total_weight);


 }


