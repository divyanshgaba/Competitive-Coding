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
const ll mod = 1e9+7;
ll mod_pow(ll b,ll e)
{
    if(b==0)
        return 0;
    if(e==0||b==1)
        return 1;
    if(e==1)
        return b%mod;
    if(e==2)
        return (((b)%mod)*((b)%mod))%mod;
    if(e&1)
        return ((b%mod)*(mod_pow(b,e-1)%mod))%mod;
    return mod_pow(mod_pow(b,e/2)%mod,2)%mod;
}
unordered_map<ll,ll> primefactors(ll n)
{
    unordered_map<ll,ll> temp;
    ll l = n;
    for(ll i = 2;i*i<=l;i++)
    {
        ll cnt = 0;
        while(n%i == 0)
        {
            n/=i;
            cnt++;
        }
        if(cnt!=0)
            temp[i]=cnt;
    }
    if(n>2)
        temp[n]=1;
    return temp;
}
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        auto afactors = primefactors(a), bfactors = primefactors(b);
        ll ans = 1;
        for(auto i : bfactors)
        {
           ans = (ans * mod_pow(i.F,max(i.S*c-afactors[i.F],0LL)));
           if(ans>mod)
                ans%=mod;
        }
        cout<<ans<<endl;
    }
	return 0;

}
