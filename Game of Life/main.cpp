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
int g[26][26][2];
int n,m,c;
inline int val(int i,int j,int t)
{
    if(i<0)
        i+=n;
    if(j<0)
        j+=m;
    if(i>=n)
        i%=n;
    if(j>=m)
        j%=m;
    return g[i][j][t];
}
inline pi inval(int i,int j)
{
    if(i<0)
        i+=n;
    if(j<0)
        j+=m;
    if(i>=n)
        i%=n;
    if(j>=m)
        j%=m;
    return MP(i,j);
}
inline int calc(int i,int j,int t)
{
    int alive = 0;
    for(int x=-1;x<=1;x++)
    {
        for(int y = -1;y<=1;y++)
        {
            if(x==0&&y==0)
                continue;
            alive += val(i+x,j+y,t);
        }
    }
    if(g[i][j][t] == 1)
    {
        if(alive<2)
            return 0;
        if(alive == 2 || alive == 3)
            return 1;
        if(alive>3)
            return 0;
    }
    else
    {
        if(alive == 3)
            return 1;
    }
    return 0;
}
vector<pi> change[2];
inline void iterate(int t)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            int temp =g[i][j][t]=calc(i,j,t==1?0:1);
            if(g[i][j][t==1?0:1]!=temp)
                change[t].PB(MP(i,j));
        }
    }
}
inline void iteratefurther(int t)
{
    int x = t==1?0:1;
    int vis[25][25]={0};
    change[t].clear();
    for(auto i: change[x])
    {
        for(int l = -1;l<=1;l++)
        {
            for(int k=-1;k<=1;k++)
            {
                auto a = inval(i.F+l,i.S+k);
                if(vis[a.F][a.S])
                    continue;
                vis[a.F][a.S]=1;
                int temp = g[a.F][a.S][t]=calc(a.F,a.S,t==1?0:1);
                if(temp!=g[a.F][a.S][x])
                    change[t].PB(a);
            }
        }
    }
}
int main()
{
	fast;
	cin>>n>>m>>c;
	for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            char c;
            cin>>c;
            g[i][j][0] = c=='*'?1:0;
        }
    }
    int t = 0;
    iterate(1);
    for(int i = 1;i<c;i++)
    {
        iteratefurther(t);
        t=t==1?0:1;
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(g[i][j][t==1?0:1])
                cout<<'*';
            else
                cout<<'-';
        }
        cout<<"\n";
    }
	return 0;

}
