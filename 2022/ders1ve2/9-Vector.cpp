#include <iostream>
//vektör kulllanýmý için
#include <vector>
//sort için
#include <algorithm>



using namespace std;

int main()
{
   vector<int> v;
   v.push_back(3);
   v.push_back(2);
   v.push_back(5);

   for(int i=0;i<v.size() ;i++)
    cout <<v[i]<<"\n"; // 3 2 5

   // son elemaný çýkarmak için
   v.pop_back();
   // son elemaný bulmak için
   cout << v.back() <<"\n"; //2

   v.push_back(3);
   v.push_back(8);
   v.push_back(6);
   // listeyi sýralamak için
   sort(v.begin(),v.end());
   for(int i=0;i<v.size() ;i++)
   cout <<v[i]<<"\n"; //2 3 3 6 8

   // listeyi tersten sýralamak için
   sort(v.rbegin(),v.rend());
   for(int i=0;i<v.size() ;i++)
   cout <<v[i]<<"\n"; //8 6 3 3 2


   // listeyi tersten sýralamak için
   sort(v.rbegin(),v.rend());
   for(int i=0;i<v.size() ;i++)
   cout <<v[i]<<"\n"; //8 6 3 3 2

   vector<int> d(10); // 10 elemanlýk tüm elemanlarý 0 olan bir dizi
    for(int i=0;i<d.size() ;i++)
   cout <<d[i]<<"\n"; // 0 0 0 0 0 0 0 0 0 0

    vector<int> e(10,5); // 10 elemanlýk tüm elemanlarý 5 olan bir dizi
    for(int i=0;i<e.size() ;i++)
   cout <<e[i]<<"\n"; // 5 5 5 5 5 5 5 5 5 5

   // listenin maksimum ve minimum deðeri
   int maks;
   maks = *max_element(v.begin(), v.end());
     cout <<"Maks ="<< maks;
     cout <<"\nMin ="<< *min_element(v.begin(), v.end());
}
