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
map<pi,bool> mera;
int NIL = -1;
class graph_class
{
    public:
    int V;
    list<int> *adj;
    void helper(int v, bool vis[], int disc[], int low[],
                    int p[]);
    graph_class(int V);
    void addEdge(int v, int w);
    void bridge();
};

graph_class::graph_class(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void graph_class::addEdge(int v, int w)
{
    adj[v].PB(w);
    adj[w].PB(v);  }


void graph_class::helper(int u, bool vis[], int disc[],
                                  int low[], int p[])
{
    static int time = 0;

    vis[u] = true;

    disc[u] = low[u] = ++time;

    for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
        if (!vis[v])
        {
            p[v] = u;
            helper(v, vis, disc, low, p);

            low[u]  = min(low[u], low[v]);

            if (low[v] > disc[u])
              mera[MP(u,v)]=true;//cout<<u<<" "<<v<<endl;
        }

        else if (v != p[u])
            low[u]  = min(low[u], disc[v]);
    }
}

void graph_class::bridge()
{
    bool *vis = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *p = new int[V];

    for (int i = 0; i < V; i++)
    {
        p[i] = NIL;
        vis[i] = false;
    }
    for (int i = 0; i < V; i++)
        if (vis[i] == false)
            helper(i, vis, disc, low, p);
}
int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	graph_class g(n);
	for(int i = 0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        g.addEdge(a,b);
    }
    g.bridge();
    set<int> s;
    for(int i = 0;i<n;i++)
    {
        bool ans = true;
        for(auto j:g.adj[i])
        {
            if(mera[MP(i,j)]!=true&&mera[MP(j,i)]!=true)
            {
                ans = false;
                break;
            }
        }
        if(ans)
            s.insert(i+1);
    }
    for(auto i:s)
        cout<<i<<endl;
	return 0;

}
