#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n,i;
    scanf("%d",&n);
    long long item;
    scanf("%lld",&item);
    long long rev=0,max=item,temp=item,count=1;

    for(i=1;i<n;i++)
        {
           scanf("%lld",&item);
           if(item<max)
                {
                    max=item;count+=1;
                }

            if(temp>=rev)
           {

             rev=temp;
                count=0;
           }

        }
temp=max*count;
if(temp>=rev)
                rev=temp;
    printf("%lld\n",rev);
    return 0;

}
