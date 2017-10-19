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
const int INF = 1e9;
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int nk,n;
		cin>>nk;
		int h[nk],kt[nk];
		for(int i = 0;i<nk;i++) cin>>h[i];
		for(int i = 0;i<nk;i++) cin>>kt[i];
		set<int> s(kt,kt+nk);
        vector<vector<int>> dp(nk,vector<int>(1001,INF));
        int k[n=s.size()];
        int l = 0;
        for(auto i:s)
            k[l++]=i;
        for(int i = 0;i<n;i++)
            dp[i][0] = 0;
        for(int i = 1;i<=1000;i++)
        {
            if(i>=k[0] && i%k[0]==0)
                dp[0][i] = i/k[0];
        }
        for(int i = 1;i<n;i++)
        {
            for(int j = 1;j<=1000;j++)
            {
                dp[i][j] = dp[i-1][j];
                int l = 1;
                while(j-l*k[i]>=0)
                {
                    dp[i][j] = min(dp[i][j],dp[i-1][j-l*k[i]] + l);
                    l++;
                }
            }
        }

        int ans = 0;
        for(int i = 0;i<nk;i++)
        {
            ans += dp[n-1][h[i]<<1];
            //cout<<dp[n-1][h[i]<<1]<<" ";

        }
        cout<<ans<<endl;
    }
	return 0;

}
