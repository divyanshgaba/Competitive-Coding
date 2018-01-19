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
const int N = 5005;
int dp[N][N][2];
int n,m;
string x[2];
int solve(int i,int j,bool t)
{
    if(i<=0&&j<=0)
        return 1;
    if(dp[i][j][t])
        return dp[i][j][t];
    int ans = 2*(n+m);
    if(i>0)
    {
        int temp = solve(i-1,j,false);
        if(t)
        {
            if(x[0][i]!=x[1][j+1])
                temp++;
        }
        else
        {
            if(x[0][i]!=x[0][i+1])
                temp++;
        }
        ans = min(ans,temp);
    }
    if(j>0)
    {
        int temp = solve(i,j-1,true);
        if(t)
        {
            if(x[1][j] != x[1][j+1])
                temp++;
        }
        else
        {
            if(x[1][j]!=x[0][i+1])
                temp++;
        }
        ans = min(ans,temp);
    }
    //cout<<i<<" "<<j<<" "<<t<<" "<<ans<<endl;
    return dp[i][j][t]=ans;

}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n>>m;
        cin>>x[0]>>x[1];
        x[0]=" "+x[0];
        x[1]=" "+x[1];
        cout<<min(solve(n-1,m,false),solve(n,m-1,true))<<endl;

    }
	return 0;

}
