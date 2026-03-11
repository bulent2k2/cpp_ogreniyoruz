#include <iostream>

using namespace std;

int main()
{
    int asal;
    asal = 1;
    int i,j;
    scanf("%d",&j);
     for(int i=2; i < j; i++)
       {
         if (j%i==0 ) asal=0;
      //   printf("%d",asal);
       }

    printf("%d",asal);
    return 0;
}
