#include <iostream>
#define MOD 1000000007
using namespace std;
int fac[1001];
int answer(int n, int k)
{
    int res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i)%MOD;
        res /= (i + 1)%MOD;
    }

    return res;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,p;
        cin>>n>>p;
        int ans=0;
        for(int i =0;i<=p;i++)
        {
            ans+=answer(n,i);
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
