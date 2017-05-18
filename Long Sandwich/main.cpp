#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,n) for(ll i=0;i<n;i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MODMAX 1000003
#define MPX 320

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
vector<pi>mylist[MODMAX+9];
ll table[MODMAX+9];
bool ifV[MODMAX+9];

void init()
{
    ll ct;
    for(ll i =0;i<MODMAX;i++)
        table[i]=i;
    for(ll i=2;i<=MPX;i++)
    {
        if(!ifV[i])
        {
            for(ll j=i+i;j<=MODMAX;j+=i)
            {
                ct=0;
                while(table[j]%i==0)
                {
                    ct++;
                    table[j]/=i;
                }
                if(ct!=0)
                    mylist[j].PB(MP(i,ct));
                ifV[j]=1;
            }
        }
    }
    for(ll i=2;i<MODMAX;i++)
    {
        if(!ifV[i])
        {
            mylist[i].PB(MP(i,1));
        }
        else if(table[i]!=1)
        {
            mylist[i].PB(MP(table[i],1));
        }
    }
}

inline ll BGM(ll n, ll m, ll mod)
{
    if(m<0)
        return 1;
	ll ans = 1;
	ll k = n;
	while(m!=0){
		if(m & 1) {
			ans *= k;
			if(ans>mod) ans %= mod;
		}
		k *= k;
		if(k>mod) k %= mod;
		m >>= 1;
	}
	return ans;
}
map<pair<ll,ll>,ll>mp;
ll bin(ll n,ll r,ll m)
{
    if(r==0)
        return 1%m;
    if(n>m)
        n%=m;
    if(n<0)
        n+=m;
    if(mp.count(MP(n,r)) > 0)
        return mp[MP(n,r)];
    for(ll i =0;i<MODMAX;i++)
        table[i]=0;
    for(ll i=max(r,n-r)+1;i<=n;i++)
    {
        for(ll j=mylist[i].size()-1;j>=0;j--)
        {
            table[mylist[i][j].F]+=mylist[i][j].S;
        }
    }
    for(ll i=min(r,n-r);i>=2;i--)
    {
        for(ll j=mylist[i].size()-1;j>=0;j--)
        {
            table[mylist[i][j].F]-=mylist[i][j].S;
        }
    }
    ll ret=1;
    for(ll i=2;i<MODMAX;i++)
    {
        if(table[i] && !ifV[i])
        {
            ret=(ret * BGM((ll)i,(ll)table[i],m))%m;
        }
    }
    mp[MP(n,r)] = ret;
    return ret;
}

ll answer(ll n,ll k,ll w,ll m)
{
    ll sum =0;
    ll cn=0;
    ll c=1;
    for(ll i =0;i<=till;i++)
    {
        sum = (sum + c*bin(k,i,m)*bin(n-i*w-1,k-1,m));
        c=-c;
        if(sum<0)
            sum+=m;
        else if(sum>m)
            sum%=m;
    }
    return sum%m;
}
/*
ll feem(ll b, ll e, ll m)
{
    ll r =1;
    while(e>0)
    {
        if(e&1==1)
            r=(r*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return r;
}
ll fee(ll n,ll p)
{
    ll ie =0,fu=p,ft=n;
    while(fu<ft)
    {
        ie+=ft/fu;
        fu*=p;
    }
    return ie;
}

vi gbd(ll n, ll b)
{
    vi d;
    while(n>0)
    {
        d.PB(n%b);
        n/=b;
    }
    return d;
}
pi egcd(ll a,ll b)
{
    ll x=0,y=1,u=1,v=0;
    while(a!=0)
    {
        ll q=b/a,r=b%a;
        ll m=x-u*q,n=y-v*q;
        b=a,a=r,x=u,y=v,u=m,v=n;
    }
    return MP(x,y);
}

ll crt(auto cng)
{
    ll m =1;
    for(auto cn:cng)
    {
        m*=cn.S;
    }
    ll res =0;
    for(auto cn:cng)
    {
        auto st = egcd(m/cn.S,cn.S);
        res+=(cn.F*st.F*m)/cn.S;
    }
    return res%m;
}

ll fba(ll n,ll k,ll p)
{
    ll num_d = fee(n,p) - fee(n-k,p);
    ll den_d = fee(k,p);
    if(num_d>den_d)
        return 0;
    if(k>n)
        return 0;
    ll num =1;
    for(ll i =n;i>n-k;i--)
    {
        ll cur =i;
        while(cur%p==0)
            cur/=p;
        num=(num*cur)%p;
    }
    ll denom =1;
    for(ll i =1;i<=k;i++)
    {
        ll cur =i;
        while(cur%p==0)
            cur/=p;
        denom =(denom*cur)%p;
    }
    return (num*feem(denom,p-2,p))%p;

}
ll lcb(ll n,ll k,ll p)
{
    auto np = gbd(n,p);
    auto kp = gbd(k,p);
    ll bans=1;
    for(ll i = np.size()-1;i>=0;i--)
    {
        ll ni = np[i];
        ll ki =0;
        if(i<kp.size())
            ki=kp[i];
        bans = (bans*fba(ni,ki,p))%p;
    }
    return bans;
}
ll binom(ll n,ll k,auto facts)
{
    vector<pi> cng;
    for(auto p:facts)
    {
        cng.PB(MP(lcb(n,k,p),p));
    }
    return crt(cng);
}
vector<ll> parter(ll n)
{
    vector<ll> parts;
    ll d =2;
    while(d*d<=n)
    {
        if(n%d==0)
            parts.PB(d);
        while(n%d==0)
        {
            n/=d;
        }
        d+=1;
    }
    if(n>1)
    {
        parts.PB(n);
    }
    return parts;


}
ll f(ll n,ll k, ll w,ll m)
{
    if(w>=n)
        return 1;
    ll sum =0;
    ll c =1;
    auto parts = parter(m);
    for(ll i =0;i<=(n-k)/w;i++)
    {
        sum = (sum + c*(binom(k%m,i,parts)*binom((n-i*w-1)%m,k-1,parts))%m);
        if(sum<0)
            sum+=m;
        else if(sum>m)
            sum%=m;
        c=-c;
    }
    return sum%m;
}

bool isprime(ll m)
{
    for(ll i =2;i<=sqrt(m);i++)
    {
        if(m%i==0)
            return false;
    }
    return true;
}*/

int main()
{
    fast;
    ll test;
    init();
    cin>>test;
    while(test--)
    {
        ll n,k,m;
        cin>>n>>k>>m;
        mp.clear();
        ll seg = ceil(double(n)/double(k));
        ll ans = seg;
        //if(!isprime(m))
        cout<<ans<<" "<<answer(n,seg,k,m)%m<<endl;
        /*else
            cout<<ans<<" "<<f(n,seg,k,m)%m<<endl;*/

    }
    return 0;
}
