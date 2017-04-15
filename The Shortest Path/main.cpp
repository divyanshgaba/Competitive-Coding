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

const int INF = 1e9;

class graph
{
    int v;
    list<pi> *adj;
public:
    graph(int V)
    {
        this->v = V;
        adj = new list<pi> [V];
    }
    int shortestpath(int src,int dst);
    void addEdge(int a,int b, int c);
};

void graph::addEdge(int a,int b,int c)
{
    adj[a].PB(MP(b,c));
    adj[b].PB(MP(a,c));
}

int graph::shortestpath(int src,int dst)
{
   priority_queue< pi,vector<pi> ,greater<pi> > pq;
   vi dist(v,INF);
   pq.push(MP(0,src));
   dist[src]=0;
   while(!pq.empty())
   {
       int u = pq.top().S;
       if(u==dst)
        return pq.top().F;
        pq.pop();
       for(auto it:adj[u])
       {
           int v = it.F;
           int w = it.S;
           if(dist[v] > dist[u]+w)
           {
               dist[v] = dist[u]+w;
               pq.push(MP(dist[v],v));

           }

       }
   }

}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        map<string,int> cities;
        int n;
        cin>>n;
        graph g(n+1);
        for(int i =1;i<=n;i++)
        {
            string s;
            cin>>s;
            cities[s] = i;
            int p;
            cin>>p;
            for(int j =0;j<p;j++)
            {
                int in,cost;
                cin>>in>>cost;
                g.addEdge(i,in,cost);
            }
        }
        int r;
        cin>>r;
        for(int i =0;i<r;i++)
        {
            string a,b;
            cin>>a>>b;
            int dist = g.shortestpath(cities[a],cities[b]);
            cout<<dist<<endl;
        }
    }
	return 0;

}
