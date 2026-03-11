#include <iostream>

using namespace std;

int main()
{
    int n,m;
    int sonuc=1;
    scanf("%d %d",&n,&m);
        for(int i=1; i<=m; i++)
       {
         sonuc = sonuc * (n-i+1)/i;

       }

    printf("%d",sonuc);
    return 0;
}
