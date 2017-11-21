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
const int N = 1e5+5;
int n;
ll a[N];
vector<ll> v;
ll seg[2*N];
bool visited[N];
int st[N],en[N];
int t = 0;
vector<int> adj[N];
unordered_map<int,int> ind;
void addEdge(int u,int v)
{
    adj[u].PB(v);
    adj[v].PB(u);
}
void dfs(int src)
{
    ind[src] = v.size();
    v.PB(a[src]);
    visited[src] =true;
    st[src] = t++;
    for(auto i:adj[src])
        if(!visited[i])
            dfs(i);
    en[src] = t;
}
void build()
{
    for(int i = n-1;i>0;--i) seg[i] = seg[i<<1]+seg[i<<1|1];
}
ll query(ll l,ll r)
{
    ll ans = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            ans+=seg[l++];
        if(r&1)
            ans+=seg[--r];
    }
    return ans;
}
void modify(int p,ll x)
{
    for(seg[p+=n]=x;p>1;p>>=1) seg[p>>1]=seg[p]+seg[p^1];
}
int main()
{
	fast;
	int m;
	cin>>n>>m;
	for(int i = 0;i<n;i++)
        cin>>a[i];
    for(int i = 0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u-1,v-1);
    }
    dfs(0);
    for(int i = 0;i<n;i++)
        seg[i+n]=v[i];
    build();
    while(m--)
    {
        char c;
        cin>>c;
        if(c=='U')
        {
            int node,x;
            cin>>node>>x;
            modify(ind[node-1],x);
        }
        else
        {
            int node;
            cin>>node;
            node--;
            cout<<query(st[node],en[node])<<endl;
        }
    }
	return 0;

}
