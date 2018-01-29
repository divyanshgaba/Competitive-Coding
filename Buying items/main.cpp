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
const ll INF = 1e13;
const ll N = 505;
ll item[N][N];
ll n,m;
ll c[N];
ll masks[N];
const ll one = 1;
void masker()
{
    for(ll i = 0;i<n;i++)
    {
        for(ll j = 0;j<m;j++)
        {
            masks[i] = masks[i]|(item[i][j]<<j);
        }
    }
}
unordered_map<ll,ll> dp[N];
ll answer(ll i,ll mask)
{
    if(mask == ((one<<m)-one))
        return 0;
    if(i == n)
        return INF;
    if(dp[i][mask])
        return dp[i][mask];
    return dp[i][mask] = min(answer(i+one,mask), c[i] + answer(i+one,mask|masks[i]));
}
ll ans;
bool valid(ll mask)
{
    vector<bool> v(m,false);
    for(ll i = 0;i<n;i++)
    {
        if((one<<i)&mask)
        {
            for(ll j = 0;j<m;j++)
                v[j] = (v[j]||(item[i][j]==one));
        }
    }
    for(auto i:v)
        if(i==false)
            return false;
    return true;
}
ll cost(ll mask)
{
    ll cost = 0;
    for(ll i = 0;i<n;i++)
    {
        if((one<<i)&mask)
        {
            cost+=c[i];
        }
    }
    return cost;
}
ll brute()
{
    vector<ll> v;
    for(ll i = one;i<=((one<<n));i++)
    {
        v.PB(i);
    }
    ll temp = INF;
    for(auto i:v)
    {
        if(valid(i))
        {
            temp = min(temp,cost(i));
        }
    }
    return temp;
}
int main()
{
	fast;
	cin>>m>>n;
	for(ll i = 0;i<n;i++)
    {
        for(ll j = 0;j<m;j++)
        {
            cin>>item[i][j];
        }
        cin>>c[i];
    }
    if(n<=10)
        cout<<brute()<<endl;
    else
        masker(),cout<<answer(0,0LL)<<endl;
	return 0;

}
