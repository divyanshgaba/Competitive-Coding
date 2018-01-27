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
const ll N = 1e7 +2;
const ll INF = 1e9;
vector<ll> primes;
bool vis[N+7];
void sieve()
{
    for(int i=4;i<=N;i+=2)
        vis[i]=true;
    for(int  i = 3;i<=sqrt(N);i+=2)
    {
        if(!vis[i])
        {
            for(int j = i+i;j<=N;j+=i)
                vis[j]=true;
        }
    }
    for(int i = 2;i<=N;i++)
        if(!vis[i])
            primes.PB(i);
}

int main()
{
	fast;
	sieve();
	ll n,m;
	cin>>n>>m;
	ll sp = 0,mstw = 0;
	vector<pair<ll,pair<ll,ll>>> ans;
    for(ll i = 1;i<n-1;i++)
    {
        sp+=1;
        mstw+=1;
        ans.PB(MP(1,MP(i,i+1)));
    }
    ll cur = 0;
    for(auto i:primes)
    {
        if(i>sp)
        {
            cur = i-sp;
            sp = i,mstw=i;
            break;
        }
    }
    ans.PB(MP(cur,MP(n,n-1)));
    m-=(n-1);
    for(int i = 1;i<=n;i++)
    {
        for(int j = i+2;j<=n&&m>0;j++)
        {
            ans.PB(MP(INF,MP(i,j)));
            m--;
        }
    }
    cout<<sp<<" "<<mstw<<endl;
    for(auto i:ans)
    {
        cout<<i.S.F<<" "<<i.S.S<<" "<<i.F<<endl;
    }
	return 0;

}
