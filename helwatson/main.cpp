#include <iostream>
#include <math.h>
long long mod=1000000007
using namespace std;

int main()
{
    int test;
    while(test--)
    {
        long long n,k;
        cin>>n>>k;
        long long g=pow(k-1,n-1)%mod;
        g=(k*g)%mod;
        cout<<k%mod;

    }
    return 0;
}
