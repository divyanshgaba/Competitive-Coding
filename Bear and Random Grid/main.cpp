#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<pair<int,int>,int> pi;

int l,n;
char grid[1002][1002];
char mo[5005];

bool valid(int i,int j,int k)
{
    if(i<0||i>=n||j<0||j>=n||k>=l)
        return false;
    switch(mo[k])
    {
    case 'L':
        if(j==0)
            return false;
        if(grid[i][j-1] == '#')
            return false;
        return true;

    case 'R':
        if(j==n-1)
            return false;
        if(grid[i][j+1] == '#')
            return false;
        return true;

    case 'D':
        if(i==n-1)
            return false;
        if(grid[i+1][j] == '#')
            return false;
        return true;

    case 'U':
        if(i==0)
            return false;
        if(grid[i-1][j] == '#')
            return false;
        return true;
    }
}

bool opposite(int k )
{
    if(mo[k]=='L' && mo[k+1]=='R')
        return true;
    if(mo[k+1]=='L' && mo[k]=='R')
        return true;
    if(mo[k+1]=='U' && mo[k]=='D')
        return true;
    if(mo[k]=='U' && mo[k+1]=='D')
        return true;

    return false;
}

int sol(int i,int j, int k)
{
    if(valid(i,j,k))
    {
        if(k<l-1 && opposite(k))
        {
            return 2 + sol(i,j,k+2);
        }
        switch(mo[k])
        {
            case 'L': return 1+ sol(i,j-1,k+1);
            case 'R': return 1+ sol(i,j+1,k+1);
            case 'U': return 1+ sol(i-1,j,k+1);
            case 'D': return 1+ sol(i+1,j,k+1);
        }
    }
    return 0;
}
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        memset(grid,0,sizeof(grid));
        memset(grid,0,sizeof(mo));
        cin>>l>>n;
        cin>>mo;

        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                cin>>grid[i][j];
            }
        }
        int ans =0;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j]=='.')
                {
                    //cout<<sol(i,j,0)<<" ";
                    ans^=sol(i,j,0);
                }
                //else
                    //cout<<"# ";

            }

            //cout<<endl;
        }
        cout<<ans<<endl;

    }
	return 0;

}
