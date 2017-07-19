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
const ll INF = 1e9 + 7;
bool visited[100001];
list<int> adj1[100001],adj2[100001];
ll ans[100001],a[100001],p[100001];

void dfs1(int i, int j)
{
    if(i!=j)
        ans[i] += ans[j];
    for(auto u :adj1[i])
    {
        dfs1(u,i);
    }

}

void dfs2(int i,ll cur)
{
    visited[i]= true;
    ans[i] = min(a[i],cur);
    for(auto u: adj1[i])
    {
        if(!visited[u])
            dfs2(u,ans[i]);
    }
}


int main()
{
	fast;
	ll n;
	cin>>n;
	for(ll i =1;i<n;++i)
    {
        cin>>p[i];
        p[i]--;
        adj1[p[i]].PB(i);
        adj2[i].PB(p[i]);
    }
	for(ll i =0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i = 0;i<n;i++)
    {
        if(!visited[i])
            dfs2(i,INF);
    }
    for(int i = 0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    dfs1(0,0);
    for(int i = 0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;


	return 0;

}
