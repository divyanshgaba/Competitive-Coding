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
#define root 0


using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
const ll N = 100101;
const ll LN = 20;

vector<ll> adj[N], costs[N], indexes[N];
ll base[N], ptr;
ll chainNo, chain_index[N], chain_heads[N], posIn[N];
ll tree_depth[N], pa[LN][N], subtree_size[N];
vector<pair<ll,ll> > st[2*N];

void mymerge(vector<pair<ll,ll> > &a,vector<pair<ll,ll> > &b, vector<pair<ll,ll> > &c)
{
    ll an = a.size(),bn = b.size();
    assert(c.size()==0);
    ll i,j,k;
    i=j=k=0;
    ll prev = 0;
    while(i < an && j < bn)
    {
        if(a[i].F<b[j].F)
        {
            c.PB(MP(a[i].F,a[i].F^prev));
            prev = a[i].F^prev;
            i++;
        }
        else
        {
            c.PB(MP(b[j].F,b[j].F^prev));
            prev = b[j].F^prev;
            j++;
        }
    }
    while(i<an)
    {
        c.PB(MP(a[i].F,a[i].F^prev));
        prev = a[i++].F^prev;
    }
    while(j<bn)
    {
        c.PB(MP(b[j].F,b[j].F^prev));
        prev = b[j++].F^prev;
    }
}

void build()
{
    for(int i = 0;i<ptr;i++)
        st[i+ptr].PB(MP(base[i],base[i]));
    for(int i = ptr-1;i>0;i--) mymerge(st[i<<1],st[i<<1|1],st[i]);
}

bool cmp(ll val,pair<ll,ll> a)
{
    return val<a.F;
}

ll query_tree(ll l,ll r,ll k)
{
    ll ans = 0;
    for(l+=ptr,r+=ptr;l<r;l>>=1,r>>=1)
    {
        if(l&1)
        {
            int ind = upper_bound(st[l].begin(),st[l].end(),k,cmp) - st[l].begin();
            if(ind != 0)
                ans ^=st[l][ind-1].S;
            l++;
        }
        if(r&1)
        {
            r--;
            int ind = upper_bound(st[r].begin(),st[r].end(),k,cmp) - st[r].begin();
            if(ind != 0)
                ans ^= st[r][ind-1].S;
        }
    }
    return ans;
}

ll query_up(ll u, ll v,ll k)
{
    if ( u == v) return 0;
    ll uchain, vchain = chain_index[v],ans = 0;
    while(1)
    {
        uchain = chain_index[u];
        if(uchain == vchain)
        {
            if(u == v)
                break;
            ans ^= query_tree(posIn[v]+1,posIn[u]+1,k);
            break;
        }
        ans^=query_tree(posIn[chain_heads[uchain]],posIn[u]+1,k);
        u=chain_heads[uchain];
        u=pa[0][u];
    }
    return ans;

}
ll LCA(ll u,ll v)
{
    if(tree_depth[u]<tree_depth[v]) swap(u,v);
    ll diff = tree_depth[u] - tree_depth[v];
    while(diff>0)
    {
        int rai = log2(diff);
        u = pa[rai][u];
        diff -= (1<<rai);
    }
    if(u==v) return u;
    for(ll i = LN-1;i>=0;i--)
    {
        if(pa[i][u]!=-1 && pa[i][u] != pa[i][v])
        {
            u=pa[i][u];
            v=pa[i][v];
        }
    }
    return pa[0][u];
}

ll query(ll u,ll v,ll k)
{
    ll lca = LCA(u,v);
    //cout<<"lca("<<u<<","<<v<<") "<<lca<<endl;
    ll ans1 = query_up(u,lca,k);
    ll ans2 = query_up(v,lca,k);
    ll ans = ans1^ans2;
    return ans;
}

void HLD(ll curNode, ll cost, ll prev)
{
    if(chain_heads[chainNo] == -1)
    {
        chain_heads[chainNo] = curNode;
    }
    chain_index[curNode] = chainNo;
    posIn[curNode] = ptr;
    base[ptr++] = cost;
    ll sc = -1,ncost;
    for(ll i = 0; i < adj[curNode].size();i++)
    {
        if(adj[curNode][i] != prev)
        {
            if(sc == -1 || subtree_size[sc] < subtree_size[adj[curNode][i]])
            {
                sc = adj[curNode][i];
                ncost = costs[curNode][i];
            }
        }
    }

    if(sc != -1)
    {
        HLD(sc, ncost, curNode);
    }
    for(ll i=0; i<adj[curNode].size();i++)
    {
        if(adj[curNode][i] != prev)
        {
            if(sc != adj[curNode][i])
            {
                chainNo++;
                HLD(adj[curNode][i], costs[curNode][i], curNode);
            }
        }
    }
}

void dfs(ll cur, ll prev,ll dep =0)
{
    pa[0][cur] = prev;
    tree_depth[cur] = dep;
    subtree_size[cur] = 1;
    for(ll i = 0;i<adj[cur].size();i++)
    {
        if(adj[cur][i] != prev)
        {
            dfs(adj[cur][i],cur,dep+1);
            subtree_size[cur] += subtree_size[adj[cur][i]];
        }
    }
}
void init(ll n)
{
    ptr = 0;
    for(ll i = 0;i<=n;i++)
    {
        adj[i].clear();
        costs[i].clear();
        indexes[i].clear();
        chain_heads[i] = -1;
        for(ll j = 0;j <LN;j++) pa[j][i] = -1;
        st[i].clear();
    }
    for(ll i = n;i<2*N;i++)
    {
        st[i].clear();
    }
}

int main()
{
    fast;
	ll test=1;
	cin>>test;
	while(test--)
    {
		ll n;
		cin>>n;
		init(n);
        for(ll i = 0;i<n-1;i++)
        {
            ll u,v,c;
            cin>>u>>v>>c;
            u--,v--;
            adj[u].PB(v);
            costs[u].PB(c);
            indexes[u].PB(i);
            adj[v].PB(u);
            costs[v].PB(c);
            indexes[v].PB(i);
        }
        chainNo = 0;
        dfs(root, -1);
        HLD(root, 0, -1);
        build();
        for(ll i = 1;i<LN;i++)
            for(ll j = 0;j<n;j++)
                if(pa[i-1][j]!=-1)
                    pa[i][j] = pa[i-1][pa[i-1][j]];
        ll q;
        cin>>q;
        while(q--)
        {
            ll u,v,k;
            cin>>u>>v>>k;
            u--,v--;
            cout<<query(u,v,k)<<"\n";
        }
    }
	return 0;

}
