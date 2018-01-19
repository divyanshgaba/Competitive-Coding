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
vector<int> adj[N];
ll dep[N];
bool vis[N];
void dfs_depth(int h,int depth)
{
    if(vis[h])
        return;
    vis[h]=true;
    dep[h]=depth;
    for(auto i:adj[h])
        dfs_depth(i,depth+1);
}
ll weight[N];
ll dfs_weight(int h)
{
    if(vis[h])
        return 0;
    vis[h]=true;
    int wt = 1;
    for(auto i:adj[h])
        wt+=dfs_weight(i);
    weight[h]=wt;
    return wt;
}
double ans(ll n)
{
    double k = 0;
    double answer = 0;
    for(int i = 0;i<n;i++)
    {
        k+=dep[i];
        answer += double(dep[i]*(n-weight[i]));
    }
    answer = answer/k;
    return answer;

}
int main()
{
	fast;
	int n;
	cin>>n;
	for(int i = 1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[b].PB(a);
        adj[a].PB(b);
    }
    dfs_depth(0,0);
    memset(vis,false,sizeof(vis));
    dfs_weight(0);
    cout<<fixed<<setprecision(12)<<ans(n)<<endl;
	return 0;

}
