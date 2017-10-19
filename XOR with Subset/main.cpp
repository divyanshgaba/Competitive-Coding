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
const int N = 1e3 +1;
vector<vector<int>> dp;
int n;
int p[N];
int ans(int i,int k)
{
    if(i>n)
        return k;
    if(dp[i][k]!=-1)
        return dp[i][k];
    return dp[i][k] = max(ans(i+1,k),ans(i+1,k^p[i]));

}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int k;
		cin>>n>>k;
		for(int i = 1;i<=n;i++) cin>>p[i];
		dp = vector<vector<int>>(n+1,vector<int>(1024,-1));
		cout<<ans(1,k)<<endl;


    }
	return 0;

}
