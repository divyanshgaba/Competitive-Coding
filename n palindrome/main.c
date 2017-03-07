#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        char str[750];
        scanf("%d %s\n",&n,str);
        if(n==1&&strlen(str)%2==0)
        {
            printf("25\n");
            continue;
        }
        int temp=n/2;
        for(i=0;i<temp;i++)


    }
    return 0;
}
