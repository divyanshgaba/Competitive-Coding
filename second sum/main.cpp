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
const ll N = 2e6;
ll n;
ll t[2*N];
ll s[2*N];
void build()
{
    for(ll i = n-1;i>0;i--)
        t[i]=t[i<<1]+t[i<<1|1], s[i]=s[i<<1]+s[i<<1|1];
}
ll queryT(ll l,ll r)
{
    ll ans = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            ans+=t[l++];
        if(r&1)
            ans+=t[--r];
    }
    return ans;
}
ll queryS(ll l,ll r)
{
    ll ans = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            ans+=s[l++];
        if(r&1)
            ans+=s[--r];
    }
    return ans;
}
void updateT(ll p,ll x)
{
    for(t[p+=n]=x;p>1;p>>=1) t[p>>1] = t[p]+t[p^1];
}
void updateS(ll p,ll x)
{
    for(s[p+=n]=x;p>1;p>>=1) s[p>>1] = s[p]+s[p^1];
}
int main()
{
	fast;
	//ifstream cin("test8.in");	ofstream cout("test8.out");
	cin>>n;
	assert(1<=n && n<=500000);
	for(ll i = 0;i<n;i++)
    {
        ll x;
        cin>>x;
        assert(0<=x && x <= 1000000000);
        if(i&1)
            s[i+n]=x;
        else
            t[i+n]=x;
    }
    build();
    ll q;
    cin>>q;
    assert(1<=q && q<=500000);
    while(q--)
    {
        ll ty;
        cin>>ty;
        assert(0<=ty && ty <=1);
        if(ty==0)
        {
           ll p,x;
           cin>>p>>x;
           assert(1<=p && p<=500000);
            assert(0<=x && x <= 1000000000);
           p--;
           if(p&1)
            updateS(p,x);
            else updateT(p,x);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            assert(1<=l && l<=n && l<=r && r<=n);
            l--,r--;
            if(l&1)
                cout<<queryS(l,r+1);
            else
                cout<<queryT(l,r+1);
            cout<<endl;
        }
    }
    //cout<< "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

	return 0;

}
