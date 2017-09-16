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

const int N = 1e5+1;
int arr_size[N];
int n;
int arr[N];
void init()
{
    for(int i = 0;i<n;i++)
    {
        arr[ i ] = i ;
        arr_size[ i ] = 1;
    }
}
int getRoot(int i)
{
    while(arr[ i ] != i)
    {
        arr[ i ] = arr[ arr[ i ] ] ;
        i = arr[ i ];
    }
    return i;
}
void myunion(int A,int B)
{
    int root_A = getRoot(A);
    int root_B = getRoot(B);
    if(root_A == root_B)
        return;
    if(arr_size[root_A] < arr_size[root_B ])
    {
        arr[ root_A ] = arr[root_B];
        arr_size[root_B] += arr_size[root_A];
    }
    else
    {
        arr[ root_B ] = arr[root_A];
        arr_size[root_A] += arr_size[root_B];
    }
}

class Graph
{
public:
    int N;
	vector<int> *adj;
	Graph(int n)
	{
	    N = n;
	    adj = new vector<int>[N];

	}
	void addEdge(int a,int b)
	{
	    adj[a].PB(b);
	    adj[b].PB(a);
	}

};
bool dis[N];
int col[N];
bool dfs(Graph const &graph, int v)
{
	for (int u : graph.adj[v])
	{
		if (dis[u] == false)
		{
			dis[u] = true;
			col[u] = !col[v];
			if (dfs(graph, u) == false)
				return false;
		}
		else if (col[v] == col[u])
			return false;
	}

	return true;
}
int main()
{
    fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int q;
		cin>>n>>q;
		init();
		bool ans = true;
		vector<pair<int,int>> one;
		for(int i = 0;i<q;i++)
        {
            int a,b,val;
            cin>>a>>b>>val;
            a--,b--;
            if(a==b&&val!=0)
            {
                ans = false;
            }
            if(val==1)
            {
                one.PB(MP(a,b));
            }
            else
            {
                myunion(a,b);
            }
        }
        if(ans == false)
        {
            cout<<"no\n";
            continue;
        }
        Graph g(n);
        for(auto i:one)
        {
            g.addEdge(getRoot(i.F),getRoot(i.S));
        }
        memset(dis,0,n*sizeof(bool));
        memset(col,0,n*sizeof(int));
        for(int i = 0;i<n;i++)
        {
            if(dis[i] == false)
            {
                dis[i]=true;
                col[i]= 0;
                ans = ans&&dfs(g,i);
                if(!ans)
                    break;
            }
        }
        if(ans)
        {
            cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }
    }
	return 0;

}
