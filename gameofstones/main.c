#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int g;
        scanf("%d",&g);
        int i;
        int count=0;
        for(i=0;i<g;i++)
        {
            int p;
            scanf("%d",&p);
            int piles[p];
            int j;
            for(j=0;j<p;j++)
            {
                scanf("%d",&piles[j]);
                while(piles[j]>1)
                {
                    piles[j]-=2;
                    count++;
                }
            }

        }
        if(count%2!=0)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
