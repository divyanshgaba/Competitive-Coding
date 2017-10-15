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
int g[N][N];
int n,m,k;
void add(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m)
        return;
    g[i][j]+=1;
}
void sub(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m)
        return;
    g[i][j]-=1;
}
int main()
{
	fast;
	cin>>n>>m>>k;
	vector<pi> lions;
	for(int i = 0;i<k;i++)
    {
        int r,c,d;
        cin>>r>>c>>d;
        r--,c--;
        lions.PB(MP(r,c));
        for(int j = 0;j<=d;j++)
        {
            add(r+j,max(0,c-d+j));
            if(j)
                add(r-j,max(c-d+j,0));
            sub(r+j,c+d-j+1);
            if(j)
                sub(r-j,c+d-j+1);

        }
        //cout<<i<<" -----\n";        for(int i = 0;i<n;i++,cout<<endl)        for(int j =0 ;j<m;j++)            cout<<g[i][j]<<" ";
    }
    //for(int i = 0;i<n;i++,cout<<endl)        for(int j =0 ;j<m;j++)            cout<<g[i][j]<<" ";
    for(int i = 0;i<n;i++)
    {
        for(int j = 1;j<m;j++)
            g[i][j]+=g[i][j-1];
    }
    //for(int i = 0;i<n;i++,cout<<endl)        for(int j =0 ;j<m;j++)            cout<<g[i][j]<<" ";
    int lion = 1;
    int w = g[lions[0].F][lions[0].S];
    for(int i = 1;i<lions.size();i++)
    {
        if(w < g[lions[i].F][lions[i].S])
            lion = i+1,w=g[lions[i].F][lions[i].S];
    }
    cout<<lion<<" "<<w-1<<endl;
	return 0;

}
