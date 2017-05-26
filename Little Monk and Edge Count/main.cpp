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
typedef pair<ll,ll> pi;

vector<int> adj[100001];
bool marked[100001];
vector<pi> pairs;
int cc[100001];
int dfs(int src)
{
    marked[src]=true;
    int ans = 1;
    for(auto it:adj[src])
    {
        if(!marked[it])
            ans+=dfs(it);
    }
    return cc[src] = ans;
}


int main()
{
	fast;
	ll n,q;
	cin>>n>>q;
	for(int i =1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        pairs.PB(MP(a,b));
        adj[a].PB(b);
        adj[b].PB(a);

    }
    dfs(1);
	for(int i =0;i<q;i++)
    {
        int x;
        cin>>x;
        x--;
        ll a = pairs[x].F;
        ll b = pairs[x].S;
        ll ans ;
        if(cc[a]>cc[b])
        {
            a = n-cc[b];
            b= cc[b];
            ans = (n*(n-1))/2 -(a*(a-1))/2 -(b*(b-1))/2;
        }
        else
        {
            b=n-cc[a];
            a=cc[a];
            ans = (n*(n-1))/2 - (a*(a-1))/2 - (b*(b-1))/2;
        }
        cout<<ans<<endl;

    }
	return 0;

}
