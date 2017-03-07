#include <stdio.h>
#include <stdlib.h>

int min(int *arr,int i,int n,int p1,int p2)
{
    int j;
    int p1c,p2c;
    for(j=i;j<n;j++)
    {
        if(arr[j]==p1)
            return 1;
        if(arr[j]==p2)
            return 0;
    }
    return 0;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        scanf("%d",&n);
        int arr[n];
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int p1=-1,p2=-1;
        int count=0;
        for(i=0;i<n;i++)
        {
            if(p1==arr[i]||p2==arr[i])
                continue;
            if(min(arr,i+1,n,p1,p2)==0)
            {
                p1=arr[i];
                count++;
            }
            else
            {
                p2=arr[i];
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
