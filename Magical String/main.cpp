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
const ll mod = 1e9 + 7;
bool buf[10];
ll mul(ll a, ll b, ll c) {
	ll res = (ll)a * b;
	return (res >= c ? res % c : res);
}
ll power(long long a, long long n, ll m) {
	ll x = 1, p = a % m;
	while(n) {
		if(n & 1LL) x = mul(x, p, m);
		p = mul(p, p, m);
		n >>= 1LL;
	}
	return x;
}

int main()
{
	fast;
	string s;
	cin>>s;
	for(auto i:s)
    {
        buf[i-'0'] = true;
    }
    ll odd = 0, even = 0;
    for(int i = 0;i<10;i++)
    {
        if(buf[i])
        {
            if(i&1)
                odd++;
            else
                even++;
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        if(n==1LL)
        {
            cout<<0<<endl;
        }
        else if(n==2LL)
        {
            cout<<odd*even<<endl;
        }
        else
        {
            ll allans = ((even)*(odd+even-buf[0])*(power(odd+even,n-2,mod)))%mod;
            ll evenans = ((even-buf[0])*power(even,n-1,mod))%mod;
            ll ans = (allans - evenans)%mod;
            if(ans < 0)
                ans+=mod;
            cout<<ans<<endl;
        }

    }
	return 0;

}
