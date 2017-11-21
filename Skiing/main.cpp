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
const int N = 1e3;
int h[N][N];
bool vis[N][N];
int n,m;
void setTrue(int i,int j)
{
    if(vis[i][j])
        return;
    vis[i][j]=true;
    if(i!=0 && h[i-1][j]<=h[i][j])
        setTrue(i-1,j);
    if(i!=n-1&& h[i+1][j]<=h[i][j])
        setTrue(i+1,j);
    if(j!=0&& h[i][j-1]<=h[i][j])
        setTrue(i,j-1);
    if(j!=m-1&& h[i][j+1]<=h[i][j])
        setTrue(i,j+1);

}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		cin>>n>>m;
        priority_queue<pair<int,pi>>q;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin>>h[i][j],q.push({h[i][j],{i,j}});
        memset(vis,false,sizeof(vis));
        int ans = 0;
        while(!q.empty())
        {
            auto p = q.top();q.pop();
            if(vis[p.S.F][p.S.S])
                continue;
            ans++;
            setTrue(p.S.F,p.S.S);
        }
        cout<<ans<<endl;
    }
	return 0;

}
