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

bool visited[1000002];
int nodes;
vi a[1000002];
void dfs(int n)
{
    if(visited[n])
        return;
    nodes++;
    visited[n] = true;
    for(auto it: a[n])
    {
        dfs(it);
    }
}
int main()
{
	fast;
	int q;
	cin>>q;
	for(int i =0;i<q;i++)
    {
        ll n,m,clib,croad;
        cin>>n>>m>>clib>>croad;
        memset(a,0,sizeof(a));
        memset(visited,0,sizeof(visited));
        for(int j = 0;j<m;j++)
        {
            int x,y;
            cin>>x>>y;
            a[x].PB(y);
            a[y].PB(x);
        }
        ll ans =0;


        for(int j =1;j<=n;j++)
        {
            if(!visited[j])
            {
                nodes=0;
                dfs(j);
                ans += min(clib + (nodes-1)*croad, nodes*clib);
            }
        }
        cout<<ans<<endl;

    }
	return 0;

}
