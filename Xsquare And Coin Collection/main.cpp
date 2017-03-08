#include <iostream>

using namespace std;
long long dp[1000001];
int main()
{
    long long test;
    cin>>test;
    while(test--)
    {
        long long n,k;
        cin>>n>>k;
        long long a[n];
        for(long long i =0;i<n;i++) {cin>>a[i];dp[i]=0;}
        long long x = 0;
        for(long long i =0;i<n;i++)
        {
            if(a[i]<=k)
                dp[i]=dp[i-1]+a[i];
            x = max(dp[i],x);
        }
        cout<<x<<endl;
    }
    return 0;
}
