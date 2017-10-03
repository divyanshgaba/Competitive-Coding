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

int g[301][301];
bool vis[301][301];
int n;
int main()
{
	fast;
	cin>>n;
	int m;
	cin>>m;
	while(m--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        for(int i = max(0,x-w+1);i<min(n,x+w);i++)
        {
            for(int j = max(0,y-w+1);j<min(n,y+w);j++)
            {
                g[i][j] += (w-max(abs(x-i),abs(y-j)));
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            ans = max(ans,g[i][j]);
    cout<<ans<<endl;
	return 0;

}
