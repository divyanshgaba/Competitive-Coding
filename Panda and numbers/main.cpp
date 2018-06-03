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

ll mulmod(ll a, ll b, ll m) {
	ll q = (ll)(((long double)a*(long double)b)/(long double)m);
	ll r = a * b - q * m;
	if(r > m) r %= m; if( r < 0) r += m;
	return r;
}

ll power(ll a, ll n, ll m) {
	ll x = 1, p = a % m;
	while(n) {
		if(n & 1) x = mulod(x, p, m);
		p = mulod(p, p, m);
		n >>= 1;
	}
	return x;
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int n,m,q;
		cin>>n>>m>>q;
		vector<pi> v;
		for(int i = 0;i<q;i++)
        {
            pi a;
            cin>>a.F>>a.S;
            v.PB(a);
        }
        ll ans[n+1][10];
        for(int i = 0;i<10;i++)
        {
            ans[0][i]=
        }
    }
	return 0;

}
