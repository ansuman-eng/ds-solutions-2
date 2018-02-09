 #include <stdio.h>
#include <stdlib.h>
int count=0;
int outdegree(int c, int **adj, int n)
{
    int sum=0;
    int j;
    for(j=0;j<n;j++)
    {
        sum+=adj[c][j];
    }

    return sum;
}



void initnext(float *current, int **adj, int n)
{
    float *next = (int *)malloc(n*sizeof(float));
    int i,j;
    for(i=0;i<n;i++)
        next[i]=0;
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
    for(i=0;i<n;i++)
    {
        if(outdegree(i,adj,n)==0)
        {
            for(j=0;j<n;j++)
                next[j]+=(current[i]/n);

        }
        else if(outdegree(i,adj,n)>0)
        {
            for(j=0;j<n;j++)
            {
                if(adj[i][j]==1)
                {
                    next[j]+=(current[i]/outdegree(i,adj,n));
                }
            }
        }




    }

    for(i=0;i<n;i++)
        current[i]=next[i];


 //   for(i=0;i<n;i++)
    //printf("%f ", current[i]);
  //  printf("\n");
//
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    int n;
    scanf("%d",&n);

    int *a = (int *)malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++)
        a[i]=i;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
    int **adj=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        adj[i]=(int *)malloc(n*sizeof(int));
    }

    int j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        adj[i][j]=0;
//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
    int k;
    scanf("%d",&k);
    int c,d;
    while(k!=0)
    {
        scanf("%d %d", &c, &d);
        adj[c][d]=1;
        k--;

    }
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

    float *current = (float *)malloc(n*sizeof(float));
    for(i=1;i<n;i++)
    {
        current[i]=0;
    }

    current[0]=1;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

        for(i=0;i<65000;i++){
        initnext(current, adj, n);

        }




    for(i=0;i<n;i++)
    printf("%f ", current[i]);


}
