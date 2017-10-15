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
int n,m;
char g[N][N][3];
void plus_option(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m||g[i][j][0]=='0')
        return;
    g[i][j][0]='0';
    plus_option(i+1,j),plus_option(i-1,j),plus_option(i,j+1),plus_option(i,j-1);
}
void cross(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m||g[i][j][1]=='0')
        return;
    g[i][j][1]='0';
    cross(i+1,j+1),cross(i-1,j-1),cross(i-1,j+1),cross(i+1,j-1);
}
void star(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m||g[i][j][2]=='0')
        return;
    g[i][j][2]='0';
    star(i+1,j),star(i-1,j),star(i,j+1),star(i,j-1);
    star(i+1,j+1),star(i-1,j-1),star(i-1,j+1),star(i+1,j-1);
}

//+
int ans1()
{
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(g[i][j][0]=='1')
                plus_option(i,j),cnt++;
        }
    }
    return cnt;
}
//x
int ans2()
{
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(g[i][j][1]=='1')
                cross(i,j),cnt++;
        }
    }
    return cnt;
}
//*
int ans3()
{
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(g[i][j][2]=='1')
                star(i,j),cnt++;
        }
    }
    return cnt;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		cin>>m>>n;
		for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                cin>>g[i][j][0];
                g[i][j][1]=g[i][j][2]=g[i][j][0];
            }
        }
        cout<<ans1()<<" "<<ans2()<<" "<<ans3()<<endl;
    }
	return 0;

}
