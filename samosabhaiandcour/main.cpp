#include <iostream>
#include <stdlib.h>
#include <cstdio>
long long mod =1000000007;

using namespace std;




inline long long lelpow(long long x, long long y)
{   long long h;

    if(x==0)
    return 0;
    else if(y==0)
    return 1;
    else if(y==1)
    return x;
    else if(y==2)
    return (x*x)%mod;
    else if (y%2==1)
    return x*(lelpow(x,y-1)%mod);
    else
    return (lelpow((lelpow(x,y/2)%mod),2))%mod;

}
int main(void) {
    long long test;
    scanf("%lld",&test);
    while(test--)
    {
        long long n,k,i,a[100001],sum=0,j,l=2,m;
        scanf("%lld %lld",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);

             for(j=i-1;j>=0;j--)
                {   m=abs(a[j]-a[i]);
                    sum=sum+lelpow(m,k);
                    sum%=mod;
                }
        }

        sum=(sum*l)%mod;
        printf("%lld\n",sum);

            }

    return 0;
}
