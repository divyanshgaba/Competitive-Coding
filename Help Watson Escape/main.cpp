#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define MOD 1000000007

using namespace std;


long long power(long long x, long long y)
{
    long long res = 1;

    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;
    }
    return res;
}

int main()
{
	fast;
	long long test;
    cin>>test;
    while(test--)
    {
        long long k,n;
        cin>>n>>k;
        cout<<(k*power(k-1,n-1)%MOD)%MOD<<endl;
    }
	return 0;

}
