#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;

const ll INF = 1e16;
int n,k,x,m,s;
class graph
{
    int v;
    list<pi> *adj;
public:
    graph(int v);
    void addEdge(int u,int v,int w);
    void shortestPath(int s);
};
graph::graph(int n)
{
    this->v = n;
    adj = new list<pi> [n];
}

void graph::addEdge(int u,int v,int w)
{
    adj[u].PB(MP(v,w));
    adj[v].PB(MP(u,w));
}

void graph::shortestPath(int src)
{
    set<pi> setds;
    vi dist(v,INF);
    setds.insert(MP(0,src));
    dist[src]=0;
    while(!setds.empty())
    {
        pi tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.S;
        list<pi>::iterator i;
        for(i = adj[u].begin();i!=adj[u].end();i++)
        {
            int v = (*i).F;
            int we = (*i).S;
            if(dist[v]>dist[u]+we)
            {
                if(dist[v]!=INF)
                {
                    setds.erase(setds.find(MP(dist[v],v)));
                }
                dist[v]=dist[u] +we;
                setds.insert(MP(dist[v],v));
            }
        }
    }

    for(int i =1;i<v;i++)
        cout<<dist[i]<<" ";
    cout<<"\n";


}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {

       cin>>n>>k>>x>>m>>s;
       graph g(n+1);
       for(int i =1;i<=k;i++)
       {
           for(int j =i+1;j<=k;j++)
           {
               g.addEdge(i,j,x);
           }
       }
       for(int i =0;i<m;i++)
       {
           int u,v,w;
           cin>>u>>v>>w;
           g.addEdge(u,v,w);
       }
       g.shortestPath(s);
    }
	return 0;

}
