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

bool marked[100001];
vector<int> adj[100001];

int dfs(int src)
{
    marked[src] = true;
    int cnt = adj[src].size();
    for(auto it:adj[src])
    {
        if(!marked[it])
        {
            cnt+=dfs(it);
        }
    }
    return cnt;
}

int main()
{
	fast;
	int n,m;
	cin>>n>>m;
    for(int i =0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    int ans =0;
    for(int i =1;i<=n;i++)
    {
        if(!marked[i])
        {
            ans = max(ans,dfs(i)/2);
        }
    }
    cout<<ans<<endl;
	return 0;

}
