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
const ll N = 5e4+5;
ll sum[N];
ll a[N];
ll *st;

ll gcd(ll a, ll b)
{
    a= llabs(a);
    b=llabs(b);
    if (a < b)
        swap(a, b);
    if (b==0)
        return a;
    return gcd(b, a%b);
}

ll n;
ll t[2*N];
void build()
{
    for(int i=n-1; i>0;i--)
        t[i]=max(t[i<<1],t[i<<1|1]);
}
ll query(ll l,ll r)
{
    ll ans = -(1e16);
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            ans = max(ans,t[l++]);
        if(r&1)
            ans = max(ans,t[--r]);
    }
    return ans;
}
ll gcc[2*N];
void build2()
{
    for(int i = n-1;i>0;i--)
        gcc[i]=gcd(gcc[i<<1],gcc[i<<1|1]);
}
ll query2(ll l,ll r)
{
    ll ans = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
        {
            ans = gcd(ans,gcc[l++]);
        }
        if(r&1)
        {
            ans = gcd(ans,gcc[--r]);
        }
    }
    return ans;
}
int main()
{
	fast;
    cin>>n;
    for(ll i = 0;i<n;i++)
    {
        cin>>a[i];
        sum[i]+=a[i];
        if(i)
            sum[i]+=sum[i-1];
        t[i+n]=a[i];
        gcc[i+n]=a[i];
    }
    build();
    build2();
    ll ans = -(1e16);
    for(ll i =0;i<n;i++)
    {
        for(ll j = i;j<n;j++)
        {
            ll gc = query2(i,j+1);
            ll s = sum[j];
            if(i)
                s-=sum[i-1];
            ll maxs = query(i,j+1);
            ans = max(ans,gc*(s-maxs));
        }

    }
    cout<<ans<<endl;
	return 0;

}
