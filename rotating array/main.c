#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,k,q;
    scanf("%d %d %d",&n,&k,&q);
    int i;
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int z=1;
    while(k>=0)
    {
        int temp;
        temp=arr[k-1];
        arr[k-1]=arr[n-z];
        arr[n-z]=temp;
        z++;
        k--;
    }
    while(q--)
    {
        int m;
        scanf("%d",&m);
        printf("%d\n",arr[m]);


    }
}
