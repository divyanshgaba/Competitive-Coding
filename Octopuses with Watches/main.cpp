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
int n,m;
int w[11][11];
int ans = 0;
void count()
{
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(w[i][j]==0)
                cnt++;
        }
    }
    ans = max(ans,cnt);
}
void col(int i,int cnt)
{
    ans = max(ans,cnt);
    if(i==m)
    {
        return;
    }
    for(int k = 0;k<3;k++)
    {
        int temp  = 0;
        for(int j = 0;j<n;j++)
        {
            if(w[j][i]==0&&k!=0)
                temp--;
            w[j][i]+=k;
            w[j][i]%=3;
            if(w[j][i]==0&&k!=0)
                temp++;
        }
        col(i+1,cnt+temp);
        for(int j = 0;j<n;j++)
        {
            w[j][i]-=k;
            if(w[j][i]<0)
                w[j][i]+=3;
        }
    }
}
void row(int i,int cnt)
{
    ans = max(ans,cnt);
    if(i==n)
    {
        col(0,cnt);
        return;
    }
    for(int k = 0;k<3;k++)
    {
        int temp = 0;
        for(int j = 0;j<m;j++)
        {
            if(w[i][j]==0&&k!=0)
                temp--;
            w[i][j]+=k;
            w[i][j]%=3;
            if(w[i][j]==0&&k!=0)
                temp++;
        }
        row(i+1,cnt+temp);
        for(int j = 0;j<m;j++)
        {
            w[i][j]-=k;
            if(w[i][j]<0)
                w[i][j]+=3;
        }
    }
}
int main()
{
	fast;
	cin>>n>>m;
	for(int i  = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>w[i][j];
            w[i][j]%=3;
        }
    }
    row(0,0);
    for(int i  = 0;i<n;i++,cout<<endl)
    {
        for(int j = 0;j<m;j++)
        {
            cout<<w[i][j]<<" ";
        }
    }
    cout<<ans<<endl;
	return 0;

}
