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
const ll INF = 1e15;
const ll mod = 1e9+7;
class Graph
{
    ll V;
    list< pair<ll, ll> > *adj;

public:
    Graph(ll V);

    void addEdge(ll u, ll v, ll w);

    void shortestPath(ll s);
};

Graph::Graph(ll V)
{
    this->V = V;
    adj = new list<pi> [V];
}

void Graph::addEdge(ll u, ll v, ll w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(ll src)
{
    priority_queue< pi, vector <pi> , greater<pi> > pq;

    vector<ll> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();

        list< pair<ll, ll> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            ll v = (*i).first;
            ll weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }


    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pi>> ans;
    ll sum = 0;
    for (ll i = 0; i < V; ++i)
        sum=(sum+dist[i])%mod, ans.push(MP(dist[i],i));
    while(!ans.empty())
    {
        cout<<ans.top().second + 1<<" ";
        ans.pop();
    }
    cout<<endl<<sum<<endl;
}
int main()
{
	fast;
	ll n,k;
	cin>>n>>k;
	Graph g(n);
	ll a,b,c;
	cin>>a;
	while(a!=0)
    {
        cin>>b>>c;
        g.addEdge(a-1,b-1,c);
        cin>>a;
    }
    g.shortestPath(k-1);

	return 0;

}
