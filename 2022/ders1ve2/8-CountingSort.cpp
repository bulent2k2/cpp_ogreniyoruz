#include <iostream>

using namespace std;

int main()
{
    int val;
    int a[]={4,2,5,3,5, 8,3};
    // max deðerin 8 olduðunu bildiðim için 8 elemanlýk bir dizi yaratýyorum.
    int b[8]={0,0,0,0,0,0,0,0};
    int n = sizeof(a) / sizeof(a[0]);
    for(int i=0;i<n;i++)
    {  val = a[i]-1;
       ++b[val];
    }
    for(int i=0;i<8;i++)
    {if (b[i])
        for(int j=1;j<=b[i];j++)
        printf("%d ",i+1);
    }
}
