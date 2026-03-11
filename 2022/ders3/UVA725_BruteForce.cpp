#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkValues(int a, int b){
   set<int> s;

    if(a<10000)
    s.insert(0);
   if(b<10000)
    s.insert(0);

   while(a != 0){
        s.insert(a%10);
        a/=10;
   }

   while(b != 0){
        s.insert(b%10);
        b/=10;
   }

   if(s.size() != 10)
        return false;
    if(s.size() == 10)
        return true;
}
int main(){
    int abcde, fghij;
        for(int N=2;N<=79;N++) {
        for(fghij=1234; fghij<=98765; fghij++){
       //  for(fghij=1234; fghij<=98765/N; fghij++){
            abcde = N * fghij;

            if(abcde > 98765)
              break;

           if(checkValues(abcde, fghij)){
             printf("%d  %d %d \n",abcde, fghij, N);
            }
        }
        }
    }


