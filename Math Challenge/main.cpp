/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const ll mod = 1e9+7;
ll modInverse(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        q = a / m;

        t = m;

        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    if (x1 < 0)
       x1 += m0;

    return x1;
}
map<pair<ll,ll>,ll> m;
ll mod_pow(ll a,ll b)
{
    if(b==0||a==1)
        return 1;
    if(b==1)
        return a;
    if(b==2)
        return (a*a)%mod;
    if(b&1)
        return (a*mod_pow(mod_pow(a,(b-1)/2)%mod,2))%mod;
    return mod_pow(mod_pow(a,b/2)%mod,2)%mod;
}
ll answer(ll a,ll b,ll c)
{
    if(b==c||c==0)
        return a;
    if(c==1)
        return m[MP(b,c)] = mod_pow(a,b);
    if(m.count(MP(b,c))>0)
        return m[MP(b,c)];
    return m[MP(b,c)]=(answer(a,b-1,c-1)*answer(a,b-1,c))%mod;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        m.clear();
		ll a,b,c;
		cin>>a>>b>>c;
		ll ans = answer(a,b,c);
        cout<<ans<<endl;
    }
	return 0;

}
