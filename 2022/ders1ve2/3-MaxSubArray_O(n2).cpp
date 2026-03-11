#include <iostream>

using namespace std;

int main()
{
    {
   int array[8]= {-1,2,4,-3,5,2,-5,2};
   int a,b,best;
   int n=8;
   best =0;
   for (int a=0;a <n ; a++) {
    int sum=0;
    for (int b=a;b <n ; b++) {
            sum += array[b];
            best = max(best,sum) ;
    }
   }
  printf("%d",best);
}
}
