#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
  set<int> s;
  s.insert(3);
  s.insert(2);
  s.insert(5);

  set<int>::iterator it =s.begin();
  //it kümedeki en küçük elemanýna pointer koyuyor
  cout<<*it<<"\n";

  for(auto it = s.begin(); it!= s.end();it++)
    cout<<*it<<"\n";

}
