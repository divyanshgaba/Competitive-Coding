#include <iostream>
#include <stdlib.h>
#define MOD 1000000007
using namespace std;
long long mpow(long long x,long long n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return mpow((x*x)%MOD,n/2);
    else                             //n is odd
        return (x*mpow((x*x)%MOD,(n-1)/2))%MOD;

}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,k;
        cin>>n>>k;
        long long a[n];
        long long sum=0;
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i =0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                long long d = abs(a[i]-a[j]);
                sum+=2*mpow(d,k);
                sum%=MOD;

            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
