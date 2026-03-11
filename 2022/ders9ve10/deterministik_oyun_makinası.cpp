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


   cin>>v;

   bool bulundu;
   int cozum = 0;
   int gezi, b_gezi;
   bulundu =false;


while  (  (nodes[0]->right->weight>0 || nodes[0]->left->weight>0)  && !bulundu)

{

     gezi =0;

     while (gezi>=0)
     {
       b_gezi = gezi;
       if (nodes[b_gezi]->left == NULL)
       {
           if (nodes[b_gezi]->right->weight>0)
           {
             gezi = nodes[b_gezi]->right->value-1;
             nodes[b_gezi]->right->weight = max(0,nodes[b_gezi]->right->weight -1) ;
             if (b_gezi==0) cozum++;
           } else
           gezi = -1;
       } else
         if (nodes[b_gezi]->right == NULL)
       {
           if (nodes[b_gezi]->left->weight>0)
           {
              gezi = nodes[b_gezi]->left->value-1;

           nodes[b_gezi]->left->weight = max(0,nodes[b_gezi]->left->weight -1) ;
           if (b_gezi==0) cozum++;
           } else
           gezi = -1;

       } else

    if  ((nodes[b_gezi]->left->weight >= nodes[b_gezi]->right->weight) && nodes[b_gezi]->left->weight>0)
        {

          gezi = nodes[b_gezi]->left->value-1;
          nodes[b_gezi]->left->weight = max(0, (nodes[b_gezi]->left->weight -1)) ;
          if (b_gezi==0) cozum++;

          }

    else if (nodes[b_gezi]->right->weight>0)
        {
          gezi= nodes[b_gezi]->right->value-1;
          nodes[b_gezi]->right->weight = max(0,nodes[b_gezi]->right->weight -1) ;

          if (b_gezi==0) cozum++;
        }
    else gezi = -1;



     cout<<gezi+1<<"\n";
     //gezi degeri bir sonraki gidecegim node oldu
     if (gezi==v-1)
        {
          bulundu = true;

        }
     if (gezi>=0)
     if ((nodes[gezi]->left == NULL) && (nodes[gezi]->right ==NULL))
       {
          gezi = -1; //eger bir sonraki node'un devamý yoksa looptan çýk

       }
     }
}


if (bulundu)
    cout<<cozum;
else cout<<-1;

}
