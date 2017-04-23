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

int candy[101][101];
int n,m,t;
ll dp[101][101][1001];
ll solve(int i , int j , int t)
{
    if(t==0)
    {
        if(i == n-1 && j == m-1)
        {
            return candy[i][j];
        }
        else
            return -1e9;
    }
    if(i<0 ||j<0||i==n  || j == m)
        return -1e9;
    if(dp[i][j][t] != 0)
        return dp[i][j][t];
    ll temp = max(solve(i,j,t-1),solve(i-1,j,t-1));
    temp = max(temp,solve(i+1,j,t-1));
    temp =max(temp,solve(i,j-1,t-1));
    temp =max(temp,solve(i,j+1,t-1));
    temp += candy[i][j];
    dp[i][j][t] = temp;
    return temp;
}

int main()
{
	fast;
	cin>>n>>m>>t;
	for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
            cin>>candy[i][j];
	ll ans =solve(0,0,t);
	if(ans < 0)
        cout<<"Too late\n";
    else
        cout<<ans<<"\n";
	return 0;

}
