#include <iostream>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <cstdio>
#include <stdlib.h>

using namespace std;


int main()
{
    int test;
    cin>>test;
    while(test--)
    {
    char str[5001];int flag=0;
    cin>>str;
    int l,o=0,i,j,h=0;
    l=strlen(str);
    int psize=pow(2,l);
    char** arr = new char*[psize];
    for(i = 0; i < psize; ++i)
    arr[i] = new char[l];
    for( i=0;i<psize;i++,o++)
    {
        for( j=0,h=0;j<l;j++)
        {
            if(i&(1<<j))
            arr[o][h++]=str[j];

        }



    }
 // for(i=0;i<psize;i++)
    //  cout<<arr[i]<<endl;
   for(i=0;i<psize;i++)
   {
       for(j=0,flag=0;j<psize&&flag<2;j++)
       {
           if(strcmp(arr[i],arr[j])==0&&i!=j)
            {flag++;
          //  cout<<"flag="<<flag<<"@i="<<i"@j="<<j<<endl;
            }
       }
       if(flag==1)
        break;
   }
   if (flag==1)
    cout<<arr[i]/*<<"i="<<i*/<<endl;
   else
      cout<<"-1"<<endl;

    }
    return 0;
}
