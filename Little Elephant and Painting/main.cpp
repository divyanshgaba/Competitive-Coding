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
double dp[51][51][101];
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {

        int n,c,k;
		cin>>n>>c>>k;
		memset(dp,0,sizeof(dp));
		for(int i = 1;i<=n;i++)
        {
            dp[0][i][1] = 1;
        }
		for(int i = 1;i<=k;i++)
        {
            int l,r;
            cin>>l>>r;
            for(int j = 0;j<c;j++)
            {

                for(int h = 1;h<=l-1;h++)
                    dp[i][h][j] += dp[i-1][h][j];
                for(int h = r+1;h<=n;h++)
                    dp[i][h][j] += dp[i-1][h][j];
                for(int h = l;h<=r;h++)
                {
                    for(int m = 0;m<c;m++)
                        dp[i][h][(m*j)%c] += dp[i-1][h][m]/(2*c);
                    dp[i][h][j] += dp[i-1][h][j]/2;
                }
            }

        }
        double ans = 0;
        for(int i = 1;i<=n;i++)
            for(int j = 0;j<c;j++)
                ans+= j*dp[k][i][j];
        cout<<fixed<<setprecision(9)<<ans<<endl;
    }
	return 0;

}
