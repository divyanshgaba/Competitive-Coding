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

int components;
int degree[100001];
int arr[100001];
int size[100001];
int active[100001];
int root(int i)
{
    while(arr[i]!=i)
    {
        while(arr[i]!=i)
        {
            arr[i] = arr[arr[i]];
            i=arr[i];
        }
    }
    return i;
}
void dsu(int u,int v)
{
    int ru = root(u),rv = root(v);
    if(ru == rv)
        return;
    if(size[ru] > size[rv]) swap(ru,rv);
    arr[ru]=arr[rv];
    size[rv]+=size[ru];
    components--;
}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n,m;
        cin>>n>>m;
        memset(degree,0,sizeof(degree));
        memset(arr,0,sizeof(arr));
        memset(active,0,sizeof(active));
        list<int> adj[n];
        for(int i =0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            degree[u]++;
            degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> d[n];
        components =n;
        int ans[n];
        for(int i =0;i<n;i++)
        {
            arr[i] = i;
            size[i]=1;
            active[i]=0;
            d[degree[i]].PB(i);
        }
        for(int i =n-1;i>=0;i--)
        {
            ans[i] = components-1;
            for(auto u: d[i]) active[u]=1;
            for(auto u: d[i])
            {
                for(auto v : adj[u])
                {
                    if(active[v] == 0) continue;
                    dsu(u,v);
                }
            }
        }
        for(int i =0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;

    }
	return 0;

}
