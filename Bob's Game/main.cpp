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
const int N = 1e3;
char grid[N][N];
int dp[N][N];
bool vis[N][N];
int mex(set<int> s)
{
    int ret = 0;
    while(s.find(ret)!=s.end())
        ret++;
    return ret;
}
bool possible(pi i)
{
    if(i.F-1>=0 && grid[i.F-1][i.S]!='X')
        return true;
    if(i.S-1>=0 && grid[i.F][i.S-1]!='X')
        return true;
    if(i.F-1>=0&&i.S-1>=0 && grid[i.F-1][i.S-1]!='X')
        return true;
    return false;

}
int grundy(int i,int j)
{
    if(i<0||j<0||grid[i][j]=='X')
        return -1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    set<int> s;
    s.insert(grundy(i-1,j-1));
    s.insert(grundy(i-1,j));
    s.insert(grundy(i,j-1));
    return dp[i][j] = mex(s);

}
int main()
{
	//fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		vector<pi> K;
		memset(dp,~0,sizeof(dp));
		//cout<<dp[0][0]<<"<--\n";
		for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='K')
                    K.PB(MP(i,j));
            }
        }
        int ans = 0,k=0;
        for(auto i:K)
        {
            int t = grundy(i.F,i.S);
            ans=ans^t;
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]=='K')
                {
                    if(i&&j)
                        k+= (grid[i-1][j-1]!='X'&&((ans^grundy(i,j)^grundy(i-1,j-1))==0));
                    if(j)
                        k+= (grid[i][j-1]!='X'&&((ans^grundy(i,j)^grundy(i,j-1))==0));
                    if(i)
                        k+= (grid[i-1][j]!='X'&&((ans^grundy(i,j)^grundy(i-1,j))==0));
                }
            }
        }
        //for(int i = 0;i<n;i++,cout<<endl)            for(int j = 0;j<n;j++)                cout<<dp[i][j]<<" ";
        if(ans!=0)
            cout<<"WIN "<<k<<endl;
        else
            cout<<"LOSE"<<endl;

    }
	return 0;

}
