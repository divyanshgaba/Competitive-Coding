#include <stdio.h>
#include <stdlib.h>
int cache[1001][1001]={0};
int temp;
int arr[1001][1001];
int solve(int i,int j)
{
    if(i>temp)
        return 0;
    if(cache[i][j]>0)
        return cache[i][j];
    int t1=solve(i+1,j);
    int t2=solve(i+1,j+1);
    int t=t1>t2?t1:t2;
    t=t + arr[i][j];
    cache[i][j]=t;
    return t;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int i,j,n;
        for(i=0;i<101;i++)
            for(j=0;j<101;j++)
                cache[i][j]=0;
        scanf("%d",&n);
        temp=n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        int path=solve(0,0);
        printf("%d\n",path);
    }
    return 0;
}
