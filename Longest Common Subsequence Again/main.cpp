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
string a,b;
const int N = 505;
int dp[N][N][22];
int ans(int i,int j,int k)
{
    if(i==0||j==0)
        return 0;
    int temp = 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    if(a[i]==b[j])
        temp = 1 + ans(i-1,j-1,k);
    else
        temp = max(max(ans(i-1,j,k),ans(i,j-1,k)),((k>0)?1 + ans(i-1,j-1,k-1):0));
    return dp[i][j][k]=temp;
}

int main()
{
	fast;
	memset(dp,~0,sizeof(dp));
	cin>>a>>b;
	a=" "+a;
	b=" "+b;
	int k1,k2;
	cin>>k1>>k2;
	cout<<ans(a.length()-1,b.length()-1,k1+k2)<<endl;
	return 0;

}
