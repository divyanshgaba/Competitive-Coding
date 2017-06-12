#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)


using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
vector<ll> primes;
vector<ll> factor[5001];
const ll mod = 1e9+7;
void pre()
{
    bool isprime[100001];
    memset(isprime,true,sizeof(isprime));
    for(int i =2;i<100001;i++)
    {
        if(isprime[i])
        {
            primes.PB(i);
            for(int j = i+i;j<100001;j+=i)
                isprime[j]=false;
        }
    }
}
map<ll,ll> mp;
void primefactor(ll n)
{
    for(auto it:primes)
    {
        while(n%it ==0)
        {
            n/=it;
            mp[it]++;

        }
        if(n==1)
            break;
    }
    if(n>=2)
        mp[n]++;
}

ll power(ll a,ll b)
{
    if(b==0)
        return 1;
    if(b == 1)
        return a;
    if(b==2)
        return (a*a)%mod;
    if(b&1)
        return (a*power(a,b-1))%mod;
    return power(power(a,b/2)%mod,2)%mod;
}


int main()
{
	fast;
	int n;
	pre();
	cin>>n;
	ll a;
	for(int i =0;i<n;i++)
        cin>>a,primefactor(a);
    ll ans = 1;
    bool justdoit =true;
    for(auto i :mp)
    {
        if(i.S%n)
            justdoit = false;
        if(i.S %(n+1))
            ans *= power(i.F,n+1 - (i.S%(n+1))),ans%=mod;
    }
    if(justdoit)
        cout<<"justdoit\n";
    else
        cout<<ans<<endl;
	return 0;

}
