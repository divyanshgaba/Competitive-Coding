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
int flood[N][N];
int n,m;

void fill(int i, int j,int val)
{
    if(i<0||j<0||i>=n||j>=m|| flood[i][j]!=0||grid[i][j]=='~')
        return;
    flood[i][j] = val;
    for(int l = -1;l<=1;l++)
        for(int k=-1;k<=1;k++)
            if(l!=0&&k!=0)
                fill(i+l,j+k,val);
}

void init()
{
    int val = 1;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(grid[i][j]=='O'&&flood[i][j]==0)
            {
                fill(i,j,val++);
            }
        }
    }
}
int main()
{
	fast;
	int q;
	cin>>n>>m>>q;
	for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    init();
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cout<<flood[i][j]<<" ";
        }
        cout<<endl;
    }
    while(q--)
    {

    }
	return 0;

}
