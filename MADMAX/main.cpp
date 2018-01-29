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

const int N = 111;
vector<pair<int,char>> adj[N];

int dp[N][N][130][2];
//1 max true, 0 lucas false
int answer(int i,int j,char a,bool t)
{
    if(dp[i][j][a][t]!=-1)
        return dp[i][j][a][t];
    int node;
    if(t)
        node = i;
    else
        node = j;
    bool ans = !t;
    for(auto v : adj[node])
    {
        if(v.S>=a)
        {
            bool an;
            if(t)
                an = answer(v.F,j,v.S,!t);
            else
                an = answer(i,v.F,v.S,!t);
            if(t==an)
                ans = t;
        }
    }
    return dp[i][j][a][t] = ans;
}

int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	memset(dp,~0,sizeof(dp));
	for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        char w;
        cin>>w;
        adj[u].PB({v,w});
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(answer(i,j,'0',true))
                cout<<"A";
            else
                cout<<"B";

        }
        cout<<endl;
    }
	return 0;

}
