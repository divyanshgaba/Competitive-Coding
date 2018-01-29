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
int a[N][N];
int x[] = {0,-1,1,0};
int y[] = {-1,0,0,1};
bool ans[N][N];
int n,m;
void fill(int i, int j,int k)
{
    if(k<a[i][j] || k==-1 || i<0 || j<0||i>=n || j>=m)
        return;
    if((k==a[i][j]) && ans[i][j])        return;
    a[i][j] = k;
    ans[i][j]=true;
    for(int z=0;z<4;z++)
    {
        if(a[i+x[z]][j+y[z]] !=-1)
            fill(i+x[z],j+y[z],k-1);
    }
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		cin>>n>>m;
		memset(ans,0,sizeof(ans));
		priority_queue<pair<int,pair<int,int>>> p;
		for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin>>a[i][j],(a[i][j]>0)?p.push(MP(a[i][j],MP(i,j))):0;
        while(!p.empty())
        {
            auto i = p.top();
            if(i.F <= 0)
                break;
            fill(i.S.F,i.S.S,a[i.S.F][i.S.S]);
            p.pop();
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(a[i][j]==-1)
                    cout<<"B";
                else
                {
                    if(ans[i][j])
                        cout<<"Y";
                    else
                        cout<<"N";
                }
            }
            cout<<endl;
        }
    }
	return 0;

}
