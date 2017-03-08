#include <stdio.h>
#include <stdlib.h>
/*This Program is made by:  Divyansh Gaba */
int divlen(char *a)
{
    if(*a!='\0')
        return 1+divlen(++a);
    else
        return 0;
}
void divcount(char a[],int len)
{
    int i,ch=0,dg=0,sp=0;
    for(i=0;i<l;i++)
    {if((a>=65&&a<=90)||(a>=97&&a<=122))
        ch++;
    else if(a>=48&&a<=57)
        dg++;
    else
        sp++;
    }
    printf("Number of Characters in given string are:\t%d"
           "Number of Digits in given string are:\t%d"
           "Number of Special Characters in given string are:\t%d",ch,dg,sp);
}
void divrev(char a[],int len)
{
    int i,n;
    for(i=0,n=len/2;i<n;i++,len--)
    {
        a[i]=a[i]+a[len]-(a[len]=a[i]);
    }

}



}
int main()
{
    int choice;
    do{
    printf("\t=====Menu=====\n"
          "1. To Reverse a string\n"
          "2. To Count characters, digits and special characters in a string\n"
          "3. To Check if a paragraph follows rules of English capitalisation\n");
    scanf("%d",choice);
    switch(choice)
    {
        case 1: printf("")
    }
    }
}
