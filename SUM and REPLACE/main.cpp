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
const ll MAXN = 1e6+7;
const ll rtN = 715;
ll spf[MAXN];
struct node{
    ll sum;
    unordered_map<int,bool> s;
    node()
    {
        sum = 0;
        s.clear();
    }
};
ll d[MAXN];
node block[rtN];
int main()
{
	fast;
	ll n,q;
	cin>>n>>q;
	for(int i  = 1;i<MAXN;i++)
    {
        for(int j = i;j<MAXN;j+=i)
            d[j]+=1;
    }
	ll a[n];
	for(ll i = 0;i<n;i++)
    {
        cin>>a[i];
        block[i/rtN].sum+=a[i];
        block[i/rtN].s[i]=true;
    }
    while(q--)
    {
        ll t,l,r;
        cin>>t>>l>>r;
        l--,r--;
        //replace
        if(t==1)
        {
            while (l<r and l%rtN!=0 and l!=0)
            {
                ll hold = d[a[l]];
                if(a[l]!=hold)
                {
                    block[l/rtN].sum = block[l/rtN].sum - a[l] + hold;
                    a[l]=hold;
                }
                else
                {
                    if(block[l/rtN].s[l])
                        block[l/rtN].s.erase(l);
                }
                l++;
            }
            while (l+rtN <= r)
            {
                vector<ll> v;
                for(auto i:block[l/rtN].s)
                {
                    ll hold = d[(a[i.F])];
                    if(hold!=a[i.F])
                        block[l/rtN].sum=block[l/rtN].sum - a[i.F] + hold,a[i.F]=hold;
                    else
                    {
                        v.PB(i.F);

                    }
                }
                for(auto i:v)
                    block[l/rtN].s.erase(i);
                l += rtN;
            }
            while (l<=r)
            {
                ll hold = d[(a[l])];
                if(a[l]!=hold)
                {
                    block[l/rtN].sum = block[l/rtN].sum - a[l] + hold;
                    a[l]=hold;
                }
                else
                {
                    if(block[l/rtN].s[l])
                        block[l/rtN].s.erase(l);
                }
                l++;
            }
        }
        //sum
        else
        {
            ll ans = 0;
            while (l<r and l%rtN!=0 and l!=0)
            {
                ans += a[l];
                l++;
            }
            while (l+rtN <= r)
            {
                ans += block[l/rtN].sum;
                l += rtN;
            }
            while (l<=r)
            {
                ans += a[l];
                l++;
            }
            cout<<ans<<endl;
        }
    }
	return 0;

}
