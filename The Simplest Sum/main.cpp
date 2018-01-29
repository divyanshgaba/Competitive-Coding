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
const ll MOD = 1e9 + 7;
ll Logn(ll n, ll r)
{
   return log(n) / log(r);
}
ll logb(ll n,ll r)
{
    ll ans = Logn(n,r);
    if(n%r)
        ans++;
    return ans;
}
ll f(ll k,ll n) {
    ll sum = 0;

    for (ll i = 1; i <= n; i += 1) {
        sum =( sum+ i)%MOD;
        i *= k;
    }

    return sum;
}
ll mpow(ll b, ll e)
{
    if(e==0||b==1)
        return 1;
    if(e==1)
        return b;
    if(e==2)
        return (b*b)%MOD;
    if(e&1)
        return (b*(mpow(b,e-1)))%MOD;
    return mpow(mpow(b,e/2),2);
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        ll k,a,b;
        cin>>k>>a>>b;
        ll ans = 0;
        for(int i = a;i<=b;i++)
            ans = (ans + f(k,i))%MOD;
        cout<<ans<<endl;
    }
	return 0;

}
