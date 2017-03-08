#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i;
    int a[100],count=0,trip;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)
            count++;
    }

    trip = ((count/2) + (count%2) + 1)/2 + ((count/2) + (count%2) + 1)%2;
    printf("%d\n",trip);
    return 0;
}
