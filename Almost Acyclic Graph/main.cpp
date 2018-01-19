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
typedef  pair<int, int> iPair;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;
    vector< pair<int, iPair> > edges;
    void DFS(int v, bool visited[]);

public:
    Graph(int V);

    void addEdge(int u, int v, int w);

    bool isConnected();

    bool reverseDeleteMST();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
    edges.push_back({w, {u, v}});
}

void Graph::DFS(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}

bool Graph::isConnected()
{
    bool visited[V];
    memset(visited, false, sizeof(visited));
    DFS(0, visited);
    for (int i=1; i<V; i++)
        if (visited[i] == false)
            return false;
    return true;
}

bool Graph::reverseDeleteMST()
{
    int cnt = 0;
    for (int i=edges.size()-1; i>=0; i--)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        adj[u].remove(v);
        //adj[v].remove(u);
        if (isConnected() == false)
        {
            adj[u].push_back(v);
            //adj[v].push_back(u);
         }
        else
            cnt++;
    }
    cout<<cnt<<endl;
    if(cnt<=1)
        return true;
    return false;
}
int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	Graph g(n);
	for(int i = 0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        g.addEdge(x,y,1);
    }
    if(g.reverseDeleteMST())
        cout<<"YES\n";
    else
        cout<<"NO\n";
	return 0;

}
