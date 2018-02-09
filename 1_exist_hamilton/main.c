#include<stdlib.h>
#include<stdio.h>
count=0;
void permute(int *array,int i,int length, int **adj) {
  if(count>0)
    return;

  if (length == i)
    {//printArray(array,length);
     if(check(array,length,adj)==1)
        {count++; printArray(array,length);
        printf("%d",array[0]);}


     return;}

  int j = i;
  for (j = i; j < length; j++) {
     swap(array+i,array+j);
     permute(array,i+1,length,adj);
     swap(array+i,array+j);
  }
  return;
}


int check(int *a,int n, int **adj)
{   int counter=0,i;
    for(i=0;i<n-1;i++)
        if(adj[a[i]][a[i+1]]!=1)
    {
        counter=1;
        break;
    }

    if(adj[a[0]][a[n-1]]!=1)
    counter=1;



    return !counter;
}
void swap(int *a, int *b)
{

    int x = *a;
    *a=*b;
    *b=x;
}

void printArray(int* a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d",a[i]);

}

int main()
{

    int n;
    scanf("%d",&n);
    int *a = (int *)malloc(n*sizeof(int));
    int i,j;
    for(i=0;i<n;i++)
        a[i]=i;
/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
    int **adj=(int **)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        adj[i]=(int *)malloc(n*sizeof(int));
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        adj[i][j]=0;

    int k,c,d;
    scanf("%d", &k);
    while(k!=0)
    {
        scanf("%d %d",&c,&d);
        adj[c][d]=1;
        adj[d][c]=1;
        k--;

    }
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
 /*for(i=0;i<n;i++)
        {for(j=0;j<n;j++)
         printf("%d",adj[i][j]);
         printf("\n");
        } */
   permute(a,0,n,adj);




}
