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
const ll N = 1e6+1;
const ll PN = 78498;
vi primes;
unordered_map<ll,ll> idx;
ll sp[N];
bool isprime[N];
void pre()
{
    primes.PB(2);
    for(ll i =2;i<N;i+=2) sp[i] = 2;
    for(ll i =3;i<N;i+=2)
    {
        if(!isprime[i])
        {
            primes.PB(i);
            sp[i]=i;
            for(ll j = i+i;j<N;j+=i)
            {
                sp[j] = i;
                isprime[j] = true;
            }
        }
    }
    ll cnt = 0;
    for(auto i:primes)
    {
        idx[i] = cnt++;
    }
}
vi fac[2*PN+1];
void factorize(ll a,ll i)
{
    while(a!=1)
    {
        fac[idx[sp[a]] + PN].PB(i);
        a/=sp[a];
    }
}

void build()
{
    for(ll i = PN-1;i>0;i--)
    {
        merge(fac[i<<1].begin(),fac[i<<1].end(),fac[i<<1|1].begin(),fac[i<<1|1].end(),back_inserter(fac[i]));
    }
}
ll query(ll l, ll r, ll x, ll y)
{
    x = lower_bound(primes.begin(),primes.end(),x) -primes.begin();
    y = upper_bound(primes.begin(),primes.end(),y) -primes.begin();
    //cout<<x<<" "<<y<<endl;    cout<<primes[x]<<" "<<primes[y]<<endl;
    ll res = 0;
    for(x+=PN,y+=PN; x<y;x>>=1,y>>=1)
    {
        if(x&1)
        {
            res+=(upper_bound(fac[x].begin(),fac[x].end(),r) - lower_bound(fac[x].begin(),fac[x].end(),l));
            x++;
        }
        if(y&1)
        {
            y--;
            res+=(upper_bound(fac[y].begin(),fac[y].end(),r) - lower_bound(fac[y].begin(),fac[y].end(),l));
        }
    }
    return res;
}
int main()
{
	fast;
	pre();
	//ofstream cout("output.txt");
	//cout<<primes.size();
	ll n;
	cin>>n;
	ll a[n];
	for(ll i =0;i<n;i++)
        cin>>a[i],factorize(a[i],i);
    /*for(ll i =0;i<10;i++)
    {
        for(auto j :fac[i+PN])
            cout<<j<<" ";
        cout<<endl;
    }*/
    ll q;
    cin>>q;
    build();
    for(ll i =0;i<q;i++)
    {
        ll l,r,x,y;
        cin>>l>>r>>x>>y;
        l--,r--;
        cout<<query(l,r,x,y)<<endl;
    }
	return 0;

}
