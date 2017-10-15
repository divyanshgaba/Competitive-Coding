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
const int R = 201;
int g[R][R];
pi dp[R][R];
int r,c;
const int INF = 1e9;
int main()
{
	fast;
	cin>>r>>c;
	for(int i = 0;i<r;i++)
    {
        for(int j = 0;j<c;j++)
        {
            cin>>g[i][j];

        }
    }
    for(int i = 1;i<c;i++)
        dp[0][i].F = dp[0][i-1].F + g[0][i],dp[0][i].S=min(0,dp[0][i].F);
    for(int i = 1;i<r;i++)
        dp[i][0].F = dp[i-1][0].F + g[i][0],dp[i][0].S=min(0,dp[i][0].F);
    for(int i = 1;i<r;i++)
    {
        for(int j = 1;j<c;j++)
        {
            if(dp[i-1][j].F < dp[i][j-1].F)
            {
                dp[i][j].F = dp[i][j-1].F +g[i][j];
                dp[i][j].S = min(dp[i][j-1].S,dp[i][j].F);
            }
            else if(dp[i-1][j].F>dp[i][j-1].F)
            {
                dp[i][j].F = dp[i-1][j].F +g[i][j];
                dp[i][j].S = min(dp[i-1][j].S,dp[i][j].F);
            }
            else
            {
                dp[i][j].F=dp[i-1][j].F+g[i][j];
                dp[i][j].S = max(dp[i-1][j].S,dp[i][j-1].S);
                dp[i][j].S = min(dp[i][j].F,dp[i][j].S);
            }

        }
    }
    /*for(int i = 0;i<r;i++)
    {
        for(int j = 0;j<c;j++)
        {
            cout<<dp[i][j].F<<"-"<<dp[i][j].S<<" ";
        }
        cout<<endl;
    }*/
    cout<<abs(dp[r-1][c-1].S)+1<<endl;


	return 0;

}
