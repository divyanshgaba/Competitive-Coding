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
#define REP(i,a,b) for (ll i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
const ll N = 1e5 + 1;
ll fr[N][26];
const ll M = 1e9+7;
ll fac[N+2];
void init()
{
    fac[0]=1;
    for(ll i = 1;i<=N;i++)
    {
        fac[i] = (fac[i-1]*i)%M;
    }
}
ll gcdExtended(ll a, ll b, ll *x, ll *y);

// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x%m + m) % m;
    return res;
}

// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
int main()
{
	fast;
	init();
	string s;
	cin>>s;
	ll q;
	cin>>q;
	ll n = s.length();
	for(ll i = 0;i<n;i++)
    {
        fr[i][s[i]-'a']++;
    }
    for(ll i = 1;i<n;i++)
    {
        for(ll j = 0;j<26;j++)
        {
            fr[i][j]+=fr[i-1][j];
        }
    }
	while(q--)
    {
        ll l,r;
        cin>>l>>r;
        l--,r--;
        ll ev = 0,od = 0;
        vector<ll> p;
        for(ll i = 0;i<26;i++)
        {
            ll g = fr[r][i];
            if(l)
                g -= fr[l-1][i];
            if(g&1)
                od++;
            ev+=g/2;
            if(g>3)
                p.PB(g/2);
        }
        ll ans = fac[ev];
        for(auto i:p)
        {
            ll kk = modInverse(fac[i],M);
            ans = ((ans)%M*(kk)%M)%M;
        }
        if(od)
            ans = (od*ans)%M;
        assert(ans>=1);
        cout<<ans<<endl;
    }
	return 0;

}
