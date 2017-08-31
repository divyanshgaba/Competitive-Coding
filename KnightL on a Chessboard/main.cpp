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

int ans[25][25];
bool vis[25][25];
const int INF = 1e9;
int n;
int knight(int i,int j,int x,int y)
{
    if(x>=n || y>=n || x<0 || y<0)
        return INF;
    if(x==n-1 && y == n-1)
        return 0;
    int &t = ans[x][y];
    if(vis[x][y])
        return INF;

    if(t !=0)
        return t;
    vis[x][y] = true;
    int ele = min(INF,knight(i,j,x+i,y+j));
    ele = min(ele,knight(i,j,x-i,y+j));
    ele = min(ele,knight(i,j,x-i,y-j));
    ele = min(ele,knight(i,j,x+i,y-j));
    ele = min(ele,knight(i,j,x+j,y+i));
    ele = min(ele,knight(i,j,x+j,y-i));
    ele = min(ele,knight(i,j,x-j,y+i));
    ele = min(ele,knight(i,j,x-j,y-i));
    t = 1+ele;

    return t;
}
int main()
{
	fast;
	cin>>n;
    for(int i = 1;i<n;i++)
    {
        for(int j = 1;j<n;j++)
        {
            memset(vis,false,sizeof(vis));
            memset(ans,0,sizeof(ans));
            int x = knight(min(i,j),max(i,j),0,0);
            if( x< INF)
                cout<< x<<" ";
            else
                cout<<-1<<" ";
        }
        cout<<endl;
    }

	return 0;

}
