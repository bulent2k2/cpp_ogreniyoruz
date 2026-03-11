#include <iostream>
#include<bits/stdc++.h>


using namespace std;

int main()

{
  deque<int> d;
  d.push_back(5);
  d.push_back(2); //  [5,2]
  d.push_front(3); //   [3,5,2]
  d.pop_back(); //[3,5]
  d.pop_front(); //[5]


  stack<int> s;
  s.push(3);
  s.push(2);
  s.push(5);
  cout<< s.top(); //5
  s.pop();
  cout<< s.top(); //2


  queue<int> q;
  q.push(3);
  q.push(2);
  q.push(5);
  cout<< q.front(); //3
  q.pop();
  cout<< q.front(); //2


  priority_queue<int> p;
  p.push(3);
  p.push(5);
  p.push(7);
  p.push(2);
  cout<< p.top() << "\n"; //7
  p.pop();
  cout<< p.top() << "\n"; //5
  p.pop();
  p.push(6);
  cout<< p.top() << "\n\n"; //6
  p.pop();

   priority_queue<int,vector<int>, greater<int> > w;
  w.push(3);
  w.push(5);
  w.push(7);
  w.push(2);
  cout<< w.top() << "\n"; //2
  w.pop();
  cout<< w.top() << "\n"; //3
  w.pop();
  w.push(6);
  cout<< w.top() << "\n"; //5




}
