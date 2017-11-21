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
int layer[101][101][101];
int h,w;
int score(int i,int j,int k)
{
    int ans = 0;
    if(i == 0)
        ans++;
    if(i==h-1)
        ans++;
    if(j == 0)
        ans++;
    if(j==w-1)
        ans++;
    if(i<h-1)
    {
        if(layer[i+1][j][k]==0)
            ans++;
    }
    if(i>0)
    {
        if(layer[i-1][j][k]==0)
            ans++;
    }
    if(j<w-1)
    {
        if(layer[i][j+1][k]==0)
            ans++;
    }
    if(j>0)
    {
        if(layer[i][j-1][k]==0)
            ans++;
    }
    return ans;
}
int main()
{
	fast;
	cin>>h>>w;
	int a[h][w];
	for(int i = 0;i<h;i++)
    {
        for(int j = 0;j<w;j++)
            cin>>a[i][j];
    }
    for(int i = 0;i<h;i++)
    {
        for(int j = 0;j<w;j++)
        {
            for(int k = 0;k<100;k++)
            {
                if(k<a[i][j])
                    layer[i][j][k]=1;
                else
                    layer[i][j][k]=0;
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<h;i++)
    {
        for(int j = 0;j<w;j++)
        {
            for(int k = 0;k<100;k++)
            {
                if(layer[i][j][k]==1)
                    ans += score(i,j,k);
            }
        }
    }
    cout<<ans+2*h*w<<endl;
	return 0;

}
