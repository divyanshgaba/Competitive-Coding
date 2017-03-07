#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FIXED 0.666666
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int s,v;
        double time=0;
        scanf("%d %d",&s,&v);
        double sf=s,vf=v;
        time=FIXED*(sf/vf);

        printf("%f\n",time);
    }
}
