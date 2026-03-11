#include <iostream>
//sort için alttaki library'i eklemek lazým
#include <algorithm>


using namespace std;

int main()
{
  int n=7;
  int a[]={4,2,5,3,5, 8,3};
  sort(a,a+n);
  for(int i=0;i<n; i++)
    printf("%d ",a[i]);
}
