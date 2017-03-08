#include <stdio.h>
#include <stdlib.h>
char hold[100][150][150]={};
int main()
{
    int n,m,k,i,j,h,temp;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);
    for(h=0;h<k;h++)
    {
        scanf("%c",&temp);
        for(i=0;i<m;i++)
        {
            //for(j=0;j<n;j++)
           // {

               scanf("%s",hold[temp][i]);
            //}
        }
    }
    int x;
    char string[505][2500];
    scanf("%d",&x);
    for(i=0;i<x;i++)
        scanf("%s",string[i]);
    int z;
    for(z=0;z<x;z++)
    {
        for(i=0;i<m;i++)
        {
            for(h=0;h<x;h++)
            {

                for(j=0;j<n;j++)
                {
                    printf("%c",hold[string[z][h]][h][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
