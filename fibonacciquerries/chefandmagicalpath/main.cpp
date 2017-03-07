#include <iostream>
#include <math.h>
#define mod 1000000007
using namespace std;
long long int lolpow(long long a, long long b)
{

    if(b==0)
        return 1;
    if(b==2)
        return (a*a)%mod;
    if(b%2)
    return a*lolpow(a,b-1)%mod;
    if(!b%2)
        return lolpow(lolpow(a,b/2),2)%mod;


}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
      long long n,k;
      cin>>n>>k;
      cout<<k*lolpow(k-1,n-1)<<endl;


    }

    return 0;
}
