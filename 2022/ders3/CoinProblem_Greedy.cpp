#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int deno[] = { 1, 2, 5, 10, 20,
               50, 100, 500, 1000 };
int n = sizeof(deno) / sizeof(deno[0]);

void findMin(int V)
{
    sort(deno, deno + n);

    vector<int> ans;

    for (int i = n - 1; i >= 0; i--) {

        // Find denominations
        while (V >= deno[i]) {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    // Print result
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

// Driver program
int main()
{
    int m;
    cin >> m;
    cout << "Girdiðiniz sayý için"
         << " minimum para " << m
         << ": ";
    findMin(m);
    return 0;
}
