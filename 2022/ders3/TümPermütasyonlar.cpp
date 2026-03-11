#include <iostream>

#include <bits/stdc++.h>

using namespace std;


void display(vector<int> a, int n){
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
}

int main()
{
    //Dizinin uzunluðunu gir
    int n;
    cin >> n;

    //vectorü tanýmla
    vector<int> a(n);

    //Kümenin elemanlarýný gir
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    do{
        //Permütasyonu yazdýr
        display(a, n);
    }while(next_permutation(a.begin(), a.end())); //Bir sonraki permütasyona geç

    return 0;
}
