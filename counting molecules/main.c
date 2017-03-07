#include <stdio.h>
#include <stdlib.h>
int min(int a,int b,int c)
{
    if(a<=b&&a<=c)
        return a;
    if(b<=a&&b<=c)
        return b;
    return c;

}
int mini(int a,int b)
{
    if(a>=b)
        return a;
    return b;
}
int main()
{
    int c,h,o;
    scanf("%d %d %d",&c,&h,&o);
    int glu=0,co=0,ho=0;

    co=mini(c,floor(o/2));
    if(co>0)
    {
        c-=co;
        o-=2*co;
    }
    ho=mini(o,floor(h/2));
    if(ho>0)
    {
        h-=2*ho;
        o-=ho;
    }
    glu=min(floor(c/6),floor(h/12),floor(o/6));
    if(glu>0)
    {
        c-=6*glu;
        h-=12*glu;
        o-=6*glu;
    }
   if(c!=0||h!=0||o!=0)
        printf("Error\n");
    else
        printf("%d %d %d\n",glu,co,ho);


    return 0;

}
