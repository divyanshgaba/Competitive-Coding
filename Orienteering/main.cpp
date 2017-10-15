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
const int N = 600;
const int P = 30;
int n,m;
double r[N][N];
double h[N][N];
double g[N][N][P];
const double E = 2.718281828;
pi got;
bool found;
struct node
{
    int i,j,x,y;
};
void floo(int i,int j,int x,int y,int t)
{
    if(i<0||j<0||i>=n||j>=m)
        return;
    //cout<<i<<" "<<j<<" "<<x<<" "<<y<<":  ";
    double hold = ((r[i][j]+r[x][y])/2);
    //cout<<hold<<" ";
    double temp = (h[i][j]-h[x][y])/10;
    temp += 0.05;
    temp = abs(temp);
    temp = pow(E,3.5*temp);
    hold *= temp;
    //cout<<hold<<" --- "<<endl;
    if(hold + g[x][y][t] < g[i][j][t])
       g[i][j][t]=hold+g[x][y][t],floo(i-1,j,i,j,t),floo(i+1,j,i,j,t),floo(i,j-1,i,j,t),floo(i,j+1,i,j,t);
}
double answer(int i,int j,int x,int y,int t)
{
    for(int l = 0;l<n;l++)
        for(int r = 0;r<m;r++)
            g[l][r][t]=1e9;
    got.F=x,got.S=y;
    found = false;
    g[i][j][t]=0;
    floo(i-1,j,i,j,t),floo(i+1,j,i,j,t),floo(i,j-1,i,j,t),floo(i,j+1,i,j,t);
    return g[x][y][t];
}

int main()
{
	fast;
	cin>>n>>m;
	int p;
	cin>>p;
	vector<pi> pos;
	for(int i = 0;i<=p;i++)
    {
        int a,b;
        cin>>a>>b;
        pos.PB(MP(a,b));
    }
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>r[i][j];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>h[i][j];
    double ans = 0;
    for(int i = 1;i<pos.size();i++)
    {
        ans+=answer(pos[i-1].F,pos[i-1].S,pos[i].F,pos[i].S,i);
    }
    cout<<ceil(ans)<<endl;
	return 0;

}
