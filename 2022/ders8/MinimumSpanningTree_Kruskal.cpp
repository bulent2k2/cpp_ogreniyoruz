#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main(){

vector<tuple<int,int,int>> edges;

int solution = 0;
int node1 = 0;
int node2 = 0;
int n=6; //# of nodes

edges.push_back({3,1,2}); //ilki weight, diðerleri edgeleri oluþturan node'u gösterir.
edges.push_back({5,1,5});
edges.push_back({6,2,5});
edges.push_back({5,2,3});
edges.push_back({3,3,6});
edges.push_back({2,5,6});
edges.push_back(make_tuple(7,6,4));
edges.push_back(make_tuple(9,3,4));


vector<int> cycle(n);

for (int i = 0; i < n; i++)
    cycle[i] = i;


sort(edges.begin(),edges.end());

while (edges.size()>0)
{ node1=get<1>(edges[0]); // örneðin (4,5,6) için get<0> 4'ü get<1> 5'i get<2> 6'yý getirir.
 node2= get<2>(edges[0]);



if (cycle[node1] != cycle[node2])
  {
     solution += get<0>(edges[0]);
  }

 int old_id = cycle[node1], new_id = cycle[node2];
        for (int i = 0; i < n; i++) {
            if (cycle[i] == old_id)
                cycle[i] = new_id;
        }

edges.erase(edges.begin());
}

cout<<solution;
 }
