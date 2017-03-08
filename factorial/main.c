#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int array[200000];
        int m;
        int n;
        int i;
        int index;
        scanf("%d",&n);
        array[0]=1;
        m=1;
        i=1;
        while(i<=n)
        {
            int temp=0;
            for(index=0;index<m;index++)
            {
                int x= i*array[index] +temp;
                array[index]=x%10;
                temp=x/10;
            }
            while(temp!=0)
            {
                array[m++]=temp%10;
                temp/=10;
            }
            i++;
        }
        for(i=m-1;i>=0;i--)
        {
            printf("%d",array[i]);
        }
        printf("\n");



    }
    return 0;
}
