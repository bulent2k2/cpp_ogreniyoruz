#include <iostream>

using namespace std;

int combinatorial(int n, int k)
{
    if ((k==0) || (k==n))
        return 1;
    else
        return combinatorial(n-1,k-1) + combinatorial(n-1,k);
}


int main()
{
    int j,v;
    scanf("%d %d",&j,&v);

    printf("%d", combinatorial(j, v));
    return(0);
}
