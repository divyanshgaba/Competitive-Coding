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
const int N = 1e4+10;
vector<int> adj[N];
int c[N];
bool vis[N];
int dfs(int i,int k)
{
    if(vis[i])
        return 0;
    vis[i]=true;
    int ans = 0;
    for(auto u:adj[i])
    {
        ans+=dfs(u,c[i]);
    }
    if(c[i]!=k)
        ans++;
    return ans;
}
int main()
{
	fast;
	int n;
	cin>>n;
    for(int i = 1;i<n;i++)
    {
        int x;
        cin>>x;
        x--;
        adj[x].PB(i);
        adj[i].PB(x);
    }
    for(int i = 0;i<n;i++)
        cin>>c[i];
    cout<<dfs(0,-1)<<endl;
	return 0;

}
