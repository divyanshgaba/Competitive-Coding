#include <iostream>
#include <math.h>
using namespace std;
long long mod=1000000007;
long long lelpow(long long a, long long b)
{
    if(a==0)
        return 0;
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b==2)
        return (a*a)%mod;
    if(b%2==1)
        return (a*lelpow(a,b-1))%mod;
    if(b%2==0)
        return (lelpow((lelpow(a,b/2)%mod),2)%mod);
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        long long n,k;
        cin>>n>>k;
        long long g=lelpow(k-1,n-1);
        g%=mod;
        g=(k*g)%mod;
        cout<<g<<endl;

    }
    return 0;
}
