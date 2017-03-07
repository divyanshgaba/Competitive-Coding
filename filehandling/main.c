#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch,i;
    FILE *fp=fopen("Divyansh.txt","w");
    for(i=1;i<50;i++)
        putw(i,fp);
    fclose(fp);
    FILE *fp2=fopen("Divyansh.txt","r");
    fseek(fp2,-4,SEEK_END);
    i=1;
    while(i++!=50)
    {
        printf("%d\t%ld\n",ch,ftell(fp2));
        fseek(fp2,-8,SEEK_CUR);
        ch=getw(fp2);
    }

    if (feof(fp2))
        printf("\n End of file reached.");
    else
        printf("\n Something went wrong.");
    fclose(fp2);
    return 0;
}
