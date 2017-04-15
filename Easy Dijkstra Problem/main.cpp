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
typedef pair<int,int> pi;

const int INF = 1e9+7;
class graph
{
    int v;
    list<pi> *adj;
    public:
    graph(int n)
    {
        this->v = n;
        this->adj = new list<pi>[n];
    }
    void addEdge(int a,int b ,int c);
    vi shortestpath(int src);
};

void graph ::addEdge(int a,int b,int c)
{
    adj[a].PB(MP(b,c));
}
vi graph::shortestpath(int src)
{
    set<pi> setds;
    vi dist(v,INF);
    setds.insert(MP(0,src));
    dist[src] = 0;
    while(!setds.empty())
    {
        pi temp = *(setds.begin());
        setds.erase(setds.begin());
        int u = temp.S;
        for(auto i : adj[u])
        {
            int v = i.F;
            int w = i.S;
            if(dist[v] > dist[u] + w)
            {
                if(dist[v]!=INF)
                {
                    setds.erase(setds.find(MP(dist[v],v)));
                }
                dist[v] = dist[u]+w;
                setds.insert(MP(dist[v],v));
            }

        }
    }
    return dist;
}


int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int v,k;
        cin>>v>>k;
        graph g(v+1);
        for(int i =0;i<k;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            g.addEdge(a,b,w);
        }
        int a,b;
        cin>>a>>b;
        vi dist = g.shortestpath(a);
        if(dist[b] == INF)
            cout<<"NO\n";
        else
            cout<<dist[b]<<"\n";

    }
	return 0;

}
