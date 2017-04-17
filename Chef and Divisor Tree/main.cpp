#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

map<ll,ll> sc;
vector<ll> primes;
void sieve(ll n)
{
    bool pr[n+1];
    memset(pr,true,sizeof(pr));
    for(ll p = 2;p*p<=n;p++)
    {
        if(pr[p]==true)
        {
            primes.PB(p);
            for(ll i =p*2;i<=n;i+=p)
                pr[i]=false;
        }
    }
}
ll score(ll n)
{
    if(n==1)
        return 1;
    if(sc.count(n)>0)
        return sc[n];
    ll temp =1;
    ll next =1;
    ll hold = n;
    for(auto it: primes)
    {
        ll m =1;
        //if(n%it==0)cout<<it<<endl;
        while(n%it==0)
        {
            n/=it;
            m++;
        }
        temp*=m;
    }
    //cout<<n<<endl;
    if(n>2)
        temp*=2;
    for(auto it:primes)
    {
        if(hold%it==0)
        {
            if(score(next)<score(hold/it))
                next=hold/it;
        }
    }
    //cout<<next<<endl;
    temp = temp + score(next);
    sc[hold] =temp;
    return temp;
}

int main()
{
	fast;
	ll a,b;
	cin>>a>>b;
	sieve(sqrt(b)+1);
	//sort(primes.begin(),primes.end());
	ll ans =0;
	for(ll i =a;i<=b;i++)
    {
        //cout<<i<<" "<<score(i)<<endl;
        ans+=(score(i)-1);
        //cout<<score(i);
    }
    cout<<ans;
	return 0;

}

