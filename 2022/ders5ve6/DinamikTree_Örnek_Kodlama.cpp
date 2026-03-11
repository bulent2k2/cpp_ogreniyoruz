#include <bits/stdc++.h>
using namespace std;


  struct node {
  int value; int weight; struct node *left, *right;} ;


 int main()
{
   int N,m,v;
   vector<int> a(3);
   vector<node*> nodes;

   m=0;

   cin>>N;

   for(int i=1;i<=N;i++)
{


      node* temp = new node;

      temp->value = i;
      temp->weight = 0;
      temp-> left = NULL;
      temp-> right = NULL;
      nodes.push_back(temp);
}


        while (N>0)
   {
       N--;
        for(int i=0;i<=3;i++){
	        cin>>a[i];
	    }
	    if (a[0]>0)
	    {
	        nodes[m]->left =  nodes[a[0]-1];
	        nodes[a[0]-1]->weight = a[1];

	    }
        if (a[2]>0)
        {
         nodes[m]->right =  nodes[a[2]-1];
	    nodes[a[2]-1]->weight = a[3];
        }
        m++;
    }

}


