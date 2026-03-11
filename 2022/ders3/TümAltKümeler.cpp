#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int a[5] = {1,2,3,4,5};
    // bu kümenin tüm alt kümelerini bulalým
    int n=5;
    for(int i=0;i < (1<<n); i++) // 2^n
    {
        vector<int> subset;
        cout <<" \n";
        for(int z=0;z<sizeof(a)/sizeof(a[0]);z++)
            if(i&1<<z) subset.push_back(a[z]); //örneðin i=25 için 11001 1,4 ve 5'i listeye eklemek lazým
            // bunun için 11001 ile z=4 için 1<<z 16 yani 1000 & iþlemiyle true olduðundan 4 ünci elemani vector'e ekliyorum.
        for(int j=0;j<subset.size();j++)
            cout<<subset[j]<<" ";
    }

}
