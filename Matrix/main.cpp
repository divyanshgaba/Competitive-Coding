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
int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	char c;
	ll grid[n][m];
	for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
         cin>>c,grid[i][j]=c-'0';
    ll f[n][m],g[n][m];
    for(int i = 0;i<m;i++)
    {
        g[n-1][i]=grid[n-1][i];
        for(int j = n-2;j>=0;j--)
        {
            if(grid[j][i]==1 && grid[j+1][i]==1)
            {
                g[j][i] = g[j+1][i] + 1;
            }
            else
            {
                g[j][i]=grid[j][i];
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        f[i][0] = grid[i][0];
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 1;j<m;j++)
        {
            //if(grid[i][j]==1)
            f[i][j] = min(f[i][j-1]+1,g[i][j]);
            //else
                //f[i][j] = 0;
        }
    }
    ll ans = 0;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            ans+=f[i][j];
    cout<<ans<<endl;
	return 0;

}
