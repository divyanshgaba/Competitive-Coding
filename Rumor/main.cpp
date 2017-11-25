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
const int N = 1e5;
int n,m;
ll c[N];
bool vis[N];
vector<int> adj[N];
ll dfs(int i)
{
    vis[i] = true;
    ll temp = c[i];
    for(auto j : adj[i])
    {
        if(!vis[j])
        {
            temp = min(temp,dfs(j));
        }
    }
    return temp;
}
int main()
{
	fast;
    cin>>n>>m;
    for(int i = 0;i<n;i++)
        cin>>c[i];
    for(int i = 0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    ll ans = 0;
    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            ans += dfs(i);
        }
    }
    cout<<ans<<endl;
	return 0;

}
