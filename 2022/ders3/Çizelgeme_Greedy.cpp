
#include <bits/stdc++.h>
using namespace std;

void printMaxActivities(int s[], int f[], int n)
{
    int i, j;

    cout <<"Seçilen iþler "<< endl;

    // Bitim zamaný olacaðý için ilk iþi alýyoruz.
    i = 0;
    cout <<" "<< i;

    // Kalan iþler için
    for (j = 1; j < n; j++)
    {

      if (s[j] >= f[i])
      {
          cout <<" " << j;
          i = j;
      }
    }
}

// driver program to test above function
int main()
{
    //iþlerin baþlama zamanlarý
    int s[] =  {1, 3, 0, 5, 8, 5};
    //iþlerin bitiþ zamanlarý(sýralý)
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}
