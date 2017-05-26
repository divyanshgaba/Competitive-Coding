#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
ll val=-1;
ll k,n;
ll power[65];
const ll mod = 1e9 +7;
ll a[100001];
ll cnt[65];
bool bit[100001][65];
ll countFact(ll n, ll p)
{
    ll k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}

long long pow(ll a, ll b, ll MOD)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

long long InverseEuler(ll n, ll MOD)
{
    return pow(n,MOD-2,MOD);
}

long long factMOD(ll n, ll MOD)
{
    long long res = 1;
    while (n > 0)
    {
        for (ll i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0)
            res = MOD - res;
    }
    return res;
}

long long C(ll n, ll r, ll MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;

    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) *
            InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}

void calc()
{
    ll t =1;
    for(ll i =0;i<64L;i++)
    {
        power[i] = t<<i;
        //cout<<power[i]<<" ";
    }
}

void cbit(int j)
{
    ll temp = a[j];
    for(int i =64;i>=0;i--)
    {
        if(temp >= power[i])
        {
            temp-= power[i];
            cnt[i]++;
            bit[j][i] =true;
        }
    }
}
ll num=0;
ll solve(int maxp)
{
    if(maxp == -1)
        return 0;
    vi h;
    ll temp = power[maxp];
    for(int i =0;i<n;i++)
    {
        if(bit[i][maxp])
            h.PB(i);
    }
    num = C(h.size(),k,mod);
    memset(cnt,0,sizeof(cnt));
    memset(bit,false,sizeof(bit));
    for(auto i : h)
    {
        cbit(i);
    }
    int te=-1;
    for(int i =maxp-1;i>=0;i--)
    {
        if(cnt[i] >= k)
        {
            //cout<<cnt[i]<<" "<<i<<" "<<power[i]<<endl;
            te=i;
            break;
        }
    }
    return temp + solve(te);


}

int main()
{
	fast;
	cin>>n>>k;
	calc();
	for(int i =0;i<n;i++)
        cin>>a[i],cbit(i);
    int maxp=-1;
    for(int i =64;i>=0;i--)
    {
        if(cnt[i] >= k)
        {
            //cout<<cnt[i]<<" "<<i<<" "<<power[i]<<endl;
            maxp=i;
            break;
        }
    }
    if(maxp == -1)
    {
        cout<<0<<" "<<C(n,k,mod)<<endl;
        return 0;
    }
    ll ans = 0;
    ans +=solve(maxp);
    cout<<ans<<endl;
    cout<<num<<endl;
	return 0;
}
