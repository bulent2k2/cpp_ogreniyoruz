#include <iostream>

using namespace std;

int main()
{
   int array[8]= {-1,2,4,-3,5,2,-5,2};
   int a,b,best;
   int n=8;

   for (int a=0;a <n ; a++) {
    for (int b=a;b <n ; b++) {
        int sum=0;
        for (int k=a;k<=b;k++) {
            sum += array[k];

        }
        best = max(best,sum) ;
    }
   }
  printf("%d",best);
}
