#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptr;
    int a[100],i,even[100];
    ptr= fopen("Divyansh.txt","r");
    for(i=0;i<25&&ptr!=EOF;i++)
    {
            a[i]=getw(ptr);
            printf("%d ",a[i]);
            fseek(ptr,0,SEEK_CUR);


    }

    fclose(ptr);

    return 0;
}
