#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
int mst=0;

typedef struct node{
  int u;
  int v;
  int weight;

  int imp;
}node;


node* create(int u,int v,int weight){           //stores the data in struct and returns it
  node* p= (node*) malloc(sizeof(node));
  p->u=u;
  p->v=v;
  p->weight=weight;

  p->imp=0;
  return p;
}

/* void sort(node*  G[100],int E){  //for sorting the edge set according to weights
    node*p;//temp structure
    for(int i=0;i<E-1;i++)
    {
      for(int j=0;j<E-i-1;j++){
        if((G[j]->weight)>(G[j+1]->weight)){
          p=G[j+1];
          G[j+1]=G[j];
          G[j]=p;
        }
      }
    }
} */

void sort(node *G[100], int n)
{
    node *temp;
    int min;
    int i, j, minj;

    for(i=0;i<n;i++)
    {
        min=G[i]->weight;
        minj=i;

        for(j=i+1;j<n;j++)
        {
            if((G[j]->weight)<= min)
            {

                min=G[j]->weight;
                minj=j;
            }
        }

       temp= G[i];
       G[i]=G[minj];
       G[minj]=temp;

    }
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

  int noCycle(int u, int v, int **reach)
  {
      if(reach[u][v]==1)
        return 0;
      else
        return 1;
  }

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

void reachable(int **reach, int n)
{
    int i, j, k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(reach[i][j]==1)
        {
            for(k=0;k<n;k++)
            {
                if(reach[j][k]==1)
                {
                    reach[i][k]=1;
                    reach[k][i]=1;
                }
            }
        }
    }
}
////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

void makeMST(node* G[100],int V,int E, int **reach, int r){
     // int include[100]={0};//this store the include node to check if cycle will be formed

        int num=0;//the number of edges innitially
        int i=0; //interator through graph
        //stores the weight of the current graph
        while(num!=V-1-r){      //tree will finish when edges is V-1
            if(noCycle(G[i]->v,G[i]->u,reach)&&G[i]->imp==0)
            {
              reach[G[i]->u][G[i]->v]=1;
              reach[G[i]->v][G[i]->u]=1;
              printf("%d %d added\n", G[i]->u, G[i]->v);
              reachable(reach, V);
              mst+=(G[i]->weight);
              num++;    //if including the edge increment num
            }
            i++;


        }
        //printf("%d",mst);

}
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
int main(){
int V,E,i,j;

node* G[100];//array of node pointers
scanf("%d %d",&V,&E);
///////////////////////////////////////////////////MAKING AND INITITALIZING THE REACHABILITY MATRIX///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int **reach= (int **)malloc(V *sizeof(int *));
for(i=0;i<V;i++)
{
    reach[i]=(int *)malloc(V*sizeof(int));
}


for(i=0;i<V;i++)
    for(j=0;j<V;j++)
    reach[i][j]=0;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

    for(i=0;i<E;i++){
      int u,v,weight;
      scanf("%d %d %d",&u,&v,&weight);
      G[i]=create(u,v,weight);

    }
////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

int r, x;
scanf("%d",&r);
for(i=0;i<r;i++)
{
    scanf("%d", &x);
    G[x]->imp=1;
    if(noCycle(G[x]->v,G[x]->u,reach))
            {
              reach[G[x]->u][G[x]->v]=1;
              reach[G[x]->v][G[x]->u]=1;
              printf("%d %d added\n", G[x]->u, G[x]->v);
              reachable(reach, V);
                mst+=(G[x]->weight);
                 //if including the edge increment num
            }
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

printf("mst after necessary additon %d\n", mst);
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
sort(G,E);
printf("Sorting works fine\n");
for(i=0;i<E;i++)
{
    printf("%d %d %d\n", G[i]->u, G[i]->v, G[i]->weight);
}
    //at this point we have a weight sorted graph edges in G

makeMST(G,V,E,reach,r);

printf("%d\n",mst);



}
