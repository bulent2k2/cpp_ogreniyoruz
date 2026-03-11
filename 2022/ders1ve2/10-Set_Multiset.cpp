#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  set<int> s;
  s.insert(3);
  s.insert(2);
  s.insert(5);
  s.insert(3);
  //kümedeki bir elemanın kaç tane olduğu
  cout<<s.count(3)<<"\n"; //1
  cout<<s.count(4)<<"\n"; //0
  //kümenin eleman sayısı
  cout<<s.size()<<"\n"; //3

  multiset<int> ms;
  ms.insert(3);
  ms.insert(2);
  ms.insert(5);
  ms.insert(3);
  //kümedeki bir elemanın kaç tane olduğu
  cout<<ms.count(3)<<"\n"; //2
  cout<<ms.count(4)<<"\n"; //0

   //kümenin eleman sayısı
  cout<<ms.size()<<"\n"; //4
  //kümeden eleman çıkarma
  s.erase(4);
  s.erase(2);
  ms.erase(s.find(3));
 // ms.erase(3);
  cout<<ms.size()<<"\n"; //3
}
