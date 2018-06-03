#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
const int N = 1e5+7;
const ll MOD = 1e9+7;
ll fib[N];
void init()
{
    fib[0]=1;
    fib[2]=1;
    for(int i = 3;i<N;i++)
        fib[i] = (fib[i-1] + fib[i-2])%MOD;
}
int main()
{
	fast;
	init();
	int test;
	cin>>test;
	while(test--)
    {
		ll m,n;
		cin>>m>>n;
		ll a,b;
		ll ai = 0, bi = 0, aj = 0;
		for(int i = 0;i<m;i++)
            cin>>a,ai=(ai+a)%MOD;
        for(int i = 0;i<m;i++)
            cin>>b,bi=(bi+b)%MOD;
        ai = (ai*m)%MOD;
        bi = (bi*m)%MOD;
        ll ans = ((ai*fib[n-1])%MOD + (bi*fib[n])%MOD )%MOD;
        cout<<ans<<endl;
    }
	return 0;

}
