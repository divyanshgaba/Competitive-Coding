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
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		bool dp[n][n][2];
		for(int i = 0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char c;
                cin>>c;
                if(c=='.')
                    dp[i][j][0]=dp[i][j][1]=true;
                else
                    dp[i][j][0]=dp[i][j][1]=false;
            }
        }
        for(int i = n-2;i>=0;i--)
        {
            dp[i][n-1][0] &= dp[i+1][n-1][0];
            dp[n-1][i][1] &= dp[n-1][i+1][1];
        }
        for(int i = n-2;i>=0;i--)
        {
            for(int j = n-2;j>=0;j--)
            {
                dp[i][j][0] &= dp[i+1][j][0];
                dp[i][j][1] &= dp[i][j+1][1];
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                ans+=dp[i][j][0]&dp[i][j][1];
        cout<<ans<<endl;
    }
	return 0;

}
