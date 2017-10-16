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
const ll N = 1e5 + 10;
const ll INF = 1e13;
pair<ll,ll> con[N];
vector<ll> cycle[N];
ll size[N];
ll n;
vector< vector<ll> > wt_cycle;
ll wt_graph[N];
pair<pair<ll,ll>,ll> graph_edge[N];
ll left_con[N];
ll right_con[N];
void init()
{
    memset(con,0,sizeof(con));
    memset(size,0,sizeof(size));
    memset(wt_graph,0,sizeof(wt_graph));
    wt_cycle.clear();
    memset(graph_edge,0,sizeof(graph_edge));
    memset(left_con,0,sizeof(left_con));
    memset(right_con,0,sizeof(right_con));
}
void weight_process()
{
    for(ll i = 0;i<n;i++)
    {
        wt_cycle.PB(cycle[i]);
        for(ll j = 1;j < cycle[i].size();j++)
        {
            wt_cycle[i][j] += wt_cycle[i][j-1];
        }
        //for(auto x:wt_cycle[i])            cout<<x<<" ";        cout<<endl;
    }
}
ll cycle_sum(ll r,ll c)
{
    if(r<0)
        return 0;
    return wt_cycle[c][r];
}
ll distance_cycle(ll u,ll v,ll c)
{
    ll ans = INF;
    if(u>v) swap(u,v);
    ans = min(ans,cycle_sum(v-1,c)-cycle_sum(u-1,c));
    ans = min(ans,cycle_sum(size[c]-1,c)-cycle_sum(v-1,c) + cycle_sum(u-1,c));
   return ans;
}
ll graph_process()
{
    for(ll i = 0;i<n;i++)
    {
        ll j = (i+1)%n;
        wt_graph[i] = graph_edge[i].S;
        wt_graph[i] += distance_cycle(graph_edge[i].F.S,graph_edge[j].F.F,j);
        if(i)
            wt_graph[i] += (wt_graph[i-1]);
    }

}
ll graph_sum(ll r)
{
    if(r<0)
        return 0;
    return wt_graph[r];
}
ll distance_graph(ll u,ll v)
{
    if(u>v) swap(u,v);
    ll ans = graph_sum(v-1)-graph_sum(u-1);
    if(v!=n)
        ans -= distance_cycle(left_con[v],right_con[v],v);
    return ans;
}
ll query(ll v1,ll c1, ll v2,ll c2)
{
    ll ans = INF;
    if(c1>c2)        swap(c1,c2),swap(v1,v2);
    ans = min(ans,distance_cycle(v1,right_con[c1],c1) + distance_graph(c1,c2) + distance_cycle(left_con[c2],v2,c2));
    ans = min(ans,distance_cycle(v1,left_con[c1],c1) + distance_cycle(v2,right_con[c2],c2) + distance_graph(c2,n)+distance_graph(0,c1));
    return ans;
}

int main()
{
	fast;
	ll test=1;
	cin>>test;
	while(test--)
    {
        init();
		ll q;
		cin>>n>>q;
		for(ll i = 0;i<n;i++)
        {
            cycle[i].clear();
            ll a;
            cin>>a;
            size[i]=a;
            for(ll j=0;j<a;j++)
            {
                ll x;
                cin>>x;
                cycle[i].PB(x);
            }
        }
        weight_process();
        //cout<<distance_cycle(0,2,0)<<" "<<distance_cycle(1,2,0)<<"= "<<distance_cycle(0,0,0)<<" "<<distance_cycle(2,0,0)<<endl;
        for(ll i = 0;i<n;i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            right_con[i]=u;
            left_con[(i+1)%n]=v;
            graph_edge[i]={MP(u,v),w};
        }
        graph_process();
        //cout<<distance_graph(0,2)<<" "<<distance_graph(0,1)<<" "<<distance_graph(1,2)<<endl;
        while(q--)
        {
            ll v1,c1,v2,c2;
            cin>>v1>>c1>>v2>>c2;
            v1--,c1--,v2--,c2--;
            assert(query(v1,c1,v2,c2)>=0);
            cout<<query(v1,c1,v2,c2)<<endl;
        }
    }
	return 0;

}
