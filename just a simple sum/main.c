#include <stdio.h>
#include <stdlib.h>
long long m;
long long h=0;
long long merapow(long long num,long long x)
{
    h++;
    if(num==0)
        return 0;
    if(x==0)
        return 1;
    if(num==1)
        return 1;
    if(x==1)
        return num%m;
    if(x==2)
        return (num*num)%m;
    if(x%2==0)
        return merapow(merapow(num%m,x/2)%m,2)%m;
    return (num%m)*(merapow(num%m,x-1))%m;


}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long n,k;
        scanf("%lld%lld",&n,&k);
        m=k;
        long long i;
        long long sum=0;
        n=n%m;
        for(i=1;i<=n;i++)
        {
            sum+=merapow(i%m,i);
        }
    printf("%lld\n",sum);
    }
    printf("%lld",h);

}

