#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void swap(char *str1, char *str2)
{
  char *temp = str1;
  str1 = str2;
  str2 = temp;
}
int val(char *sym,char c)
{
    int i;
    for(i=0;sym[i]!='\0';i++)
        if(c==sym[i])
            return i;
        return 0;
}
int main()
{
    int b;
    scanf("%d",&b);
    char sym[b+1],c;;
    c=getchar();
    int i;
    for(i=0;i<b;i++)
    {
        sym[i]=getchar();
    }
    sym[i]='\0';int fswap=0;
    char *fi=calloc(1000000,1);
    char *se=calloc(1000000,1);
    fscanf(stdin,"%s\n",fi);
    fscanf(stdin,"%s",se);
    if(se[0]=='+'&&se[1]=='\0')
    {
        fswap=1;
        fscanf(stdin,"%s\n",se);
    }
    char *in=calloc(1000000,1);
    fscanf(stdin,"%s",in);
    char *q=calloc(1000000,1);
    fscanf(stdin,"%s",q);
    char *ans=calloc(1000005,1);
    int j=0;
    i=0;
    int carry=0;



    int filen=strlen(fi);
    int selen=strlen(se);
    int anslen;
    if(filen>selen)
        {
            ans[filen]='\0';anslen=filen;
        }
    else
        {
            ans[selen]='\0';anslen=selen;
        }
    int temp=0;
    int za=anslen-1;
    if(fswap==0){
    for(i=filen-1,j=selen-1;i>=0&&j>0&&za>=0;i--,j--)
    {
        int x=val(sym,fi[i]);
        int y=val(sym,se[j]);
        int z=x+y+temp;
        temp=z/b;
        z=z%b;
        ans[--za]=sym[z];

    }
    while(i>=0&&za>=0)
    {
        int x=val(sym,fi[i]);
        int z=x+temp;
        temp=z/b;
        z=z%b;
        ans[--za]=sym[z];
    }
    while(j>0&&za>=0)
    {
        int x=val(sym,se[j--]);
        int z=x+temp;
        temp=z/b;
        z=z%b;
        ans[--za]=sym[z];
//printf("hi");
    }
    while(temp>0)
    {

        int x=val(sym,ans[za]);
        int z=x+temp;
        temp=z/b;
        z=z%b;
        ans[za--]=sym[z];
    }}
    if(fswap==1)
    {
            for(i=filen-1,j=selen-1;i>=0&&j>0&&za>=0;i--,j--)
        {
            int x=val(sym,fi[i]);
            int y=val(sym,se[j]);
            int z=x+y+temp;
            temp=z/b;
            z=z%b;
            ans[--za]=sym[z];

        }
        while(j>=0&&za>=0)
        {
            int x=val(sym,se[j--]);
            int z=x+temp;
            temp=z/b;
            z=z%b;
            ans[--za]=sym[z];
    //printf("hi");
        }
        while(i>=0&&za>=0)
        {
            int x=val(sym,fi[i--]);
            int z=x+temp;
            temp=z/b;
            z=z%b;
            ans[za--]=sym[z];
        }
    while(temp>0)
    {

        int x=val(sym,ans[za]);
        int z=x+temp;
        temp=z/b;
        z=z%b;
        ans[za--]=sym[z];
    }

    }

    printf("%d %s\n",b,sym);
    if(fswap==0){
    for(i=0;i<(selen-filen);i++)
        printf(" ");
    if(filen>selen)
        printf(" ");
    printf("%s\n",fi);
    printf("%s\n",se);
    printf("%s\n",in);
    //printf("%s\n",q);
    printf(" %s\n",ans);
    }
    else
    {
        if(filen>selen)
        printf(" ");
        printf("%s\n",fi);
        printf("+");
        for(i=0;i<abs(selen-filen);i++)
            printf(" ");
        printf("%s\n",se);
        printf("%s\n",in);
        //printf("%s\n",q);
        printf(" %c",fi[0]);
        printf("%s\n",ans);


    }

}
