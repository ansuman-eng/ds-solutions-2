#include <stdio.h>
#include <stdlib.h>

int top=-1;

void push(int *a, int n)
{
    a[++top]= n;
}
int notthere(int *a, int n, int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
            break;
    }

    if(i==n)
        return 1;
    else
        return 0;
}


int main()
{

  int n;

    scanf("%d",&n);

    int **arr = (int **)malloc(n*sizeof(int *));
    int i,j;
    for(i=0;i<n;i++)
        arr[i]=(int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        arr[i][j]=0;


    int k,a,b;
    scanf("%d",&k);
    while(k!=0)
    {
            scanf("%d %d",&a,&b);
            arr[a][b]=1;
            arr[b][a]=1;
            k--;

    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

for(i=0;i<n;i++)
    for(j=0;j<n;j++)
{
    if(arr[i][j]==1)
    {
        for(k=0;k<n;k++)
            if(arr[j][k]==1)
        {arr[i][k]=1; arr[k][i]=1;}
    }
}

scanf("%d %d", &a, &b);
if(arr[a][b]==1)
    printf("YES\n");
else
    printf("NO\n");

}
