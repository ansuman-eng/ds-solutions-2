#include <stdio.h>
#include <stdlib.h>

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

    int sum, count=0;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<n;j++)
            sum+=arr[i][j];
        if(sum%2!=0)
            count++;
    }

    if(count==0||count==2)
        printf("YES %d\n");
    else
        printf("NO\n");
}
