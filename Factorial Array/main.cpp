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
const ll N = 1e5;
const ll rtN = 800;
ll n;
ll a[N];
const ll MOD = 1e9;
vector<vector<ll>> dp(rtN,vector<ll>(rtN,0));
ll p[rtN];
const ll up = 42;
unordered_map<ll,ll> m[rtN];
ll fac[up];
void init()
{
    ll f = 1;
    for(ll i = 1;i<up;i++)
    {
        f = (f*i);
        if(f>=MOD)
            f=(f%MOD);
        if(f<0)
            f+=MOD;
        fac[i]=f;
        //cout<<f<<endl;
    }
}
void apply(ll x)
{
    if(p[x]==0)
        return;
    if(x == (n-1)/rtN)
    {
        for(ll i = 0;i<n%rtN;i++)
        {
            if(dp[x][i]<up)
                m[x][dp[x][i]]--;
            dp[x][i] = (dp[x][i]+p[x]);
            if(dp[x][i]<up)
                m[x][dp[x][i]]++;
        }
        p[x]=0;
        return;
    }
    for(ll i = 0;i<rtN;i++)
    {
        if(dp[x][i]<up)
            m[x][dp[x][i]]--;
        dp[x][i] = (dp[x][i]+p[x]);
        if(dp[x][i]<up)
            m[x][dp[x][i]]++;
    }
    p[x]=0;
}
int main()
{
	init();
	ll q;
	scanf("%lld %lld",&n,&q);
	for(ll i = 0;i<n;i++)
    {
        scanf("%lld",&dp[i/rtN][i%rtN]);
        if(dp[i/rtN][i%rtN]<up)
            m[i/rtN][dp[i/rtN][i%rtN]]++;
    }
    while(q--)
    {
        ll t;
        scanf("%lld",&t);
        if(t==1)
        {
            ll l,r;
            scanf("%lld %lld",&l,&r);
            l--,r--;
            if(l/rtN == r/rtN)
            {
                apply(l/rtN);
                for(ll i = l%rtN;i<=r%rtN;i++)
                {
                    if(dp[l/rtN][i]<up)
                        m[l/rtN][dp[l/rtN][i]]--;
                    dp[l/rtN][i] = (dp[l/rtN][i]+1);
                    if(dp[l/rtN][i]<up)
                        m[l/rtN][dp[l/rtN][i]]++;
                }
            }
            else
            {
                apply(l/rtN),apply(r/rtN);
                for(ll i = l%rtN;i<rtN;i++)
                {
                    if(dp[l/rtN][i]<up)
                        m[l/rtN][dp[l/rtN][i]]--;
                    dp[l/rtN][i] = (dp[l/rtN][i]+1);
                    if(dp[l/rtN][i]<up)
                        m[l/rtN][dp[l/rtN][i]]++;
                }
                for(ll i = 0;i<=r%rtN;i++)
                {
                    if(dp[r/rtN][i]<up)
                        m[r/rtN][dp[r/rtN][i]]--;
                    dp[r/rtN][i] = dp[r/rtN][i]+1;
                    if(dp[r/rtN][i]<up)
                        m[r/rtN][dp[r/rtN][i]]++;
                }
                for(ll i = (l/rtN)+1;i<r/rtN;i++)
                {
                    p[i]++;
                }
            }

        }
        else if(t==2)
        {
            ll l,r;
            scanf("%lld %lld",&l,&r);
            l--,r--;
            ll ans = 0;
            if(l/rtN == r/rtN)
            {
                apply(l/rtN);
                for(ll i = l%rtN;i<=r%rtN;i++)
                {
                    if(dp[l/rtN][i]<up)
                        ans=(ans+fac[dp[l/rtN][i]])%MOD;
                }
            }
            else
            {
                apply(l/rtN),apply(r/rtN);
                for(ll i = l%rtN;i<rtN;i++)
                {
                    if(dp[l/rtN][i]<up)
                        ans=(ans+fac[dp[l/rtN][i]])%MOD;
                }
                for(ll i = 0;i<=r%rtN;i++)
                {
                    if(dp[r/rtN][i]<up)
                        ans=(ans+fac[dp[r/rtN][i]])%MOD;
                }
                for(ll i = l/rtN+1;i<r/rtN;i++)
                {
                    for(auto j : m[i])
                    {
                        if((j.F+p[i]>=up)||((j.F+p[i])<=0))
                            continue;
                        ans = (ans + (j.S*fac[(j.F+p[i])])%MOD )%MOD;
                    }
                }
            }
            ans = ans%MOD;
            printf("%lld\n",ans);

        }
        else
        {
            ll i,v;
            scanf("%lld %lld",&i,&v);
            i--;
            apply(i/rtN);
            if(dp[i/rtN][i%rtN]<up)
                m[i/rtN][dp[i/rtN][i%rtN]]--;
            dp[i/rtN][i%rtN]=v;
            if(dp[i/rtN][i%rtN]<up)
                m[i/rtN][dp[i/rtN][i%rtN]]++;
        }
        //for(int i = 0;i<n;i++)            cout<<dp[i/rtN][i%rtN]<<" - ";        cout<<endl;
    }

	return 0;

}
