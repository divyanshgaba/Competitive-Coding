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
const int INF = 1e7;
int x[]={-1,0,1},y[] = {-1,0,1};
int grid[182][182],ans[182][182];
int n,m;
void bfs(pi a)
{
    queue<pi> q;
    q.push(a);
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        int xi = top.F,yj =top.S;
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                if(abs(x[i]) == abs(y[j]))
                    continue;
                if(xi + x[i] <0 || xi + x[i] >=n || yj + y[j] <0 || yj +y[j]>=m)
                    continue;
                if(ans[xi][yj] + 1 < ans[xi+x[i]][yj+y[j]])
                    q.push(MP(xi+x[i],yj+y[j])), ans[xi+x[i]][yj+y[j]] = ans[xi][yj] +1;
            }
        }
    }
}

int main()
{

	int test;
	cin>>test;
	while(test--)
    {
        memset(grid,0,sizeof(grid));
        memset(ans,0,sizeof(ans));
        cin>>n>>m;
        vector<pi> v;
        for(int i = 0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j = 0;j<m;j++)
            {
                grid[i][j] = s[j] - '0';
                ans[i][j] = INF;
                if(grid[i][j])
                    v.PB(MP(i,j)),ans[i][j]=0;
            }
        }
        for(auto i:v)
            bfs(i);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }




    }
	return 0;

}
