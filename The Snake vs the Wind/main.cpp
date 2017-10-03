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

int grid[60][60];
int n;
bool possible(int x,int y)
{
    if(x<0||y<0||x>=n||y>=n||grid[x][y]!=0)
        return false;
    return true;
}

int main()
{
	fast;
	cin>>n;
	char wind;
	cin>>wind;
	int x,y;
	cin>>x>>y;
	for(int i = 1;i<=n*n;i++)
    {
        grid[x][y] = i;
        if(wind == 'n')
        {
            if(possible(x-1,y))
            {
                x=x-1;
            }
            else if(possible(x,y-1))
            {
                y=y-1;
            }
            else if(possible(x,y+1))
            {
                y=y+1;
            }
            else
                x=x+1;
        }
        if(wind == 's')
        {
            if(possible(x+1,y))
            {
                x=x+1;
            }
            else if(possible(x,y-1))
            {
                y=y-1;
            }
            else if(possible(x,y+1))
            {
                y=y+1;
            }
            else
                x=x-1;
        }
        if(wind == 'e')
        {
            if(possible(x,y+1))
            {
                y+=1;
            }
            else if(possible(x-1,y))
            {
                x-=1;
            }
            else if(possible(x+1,y))
            {
                x+=1;
            }
            else
                y-=1;
        }
        if(wind == 'w')
        {
            if(possible(x,y-1))
            {
                y-=1;
            }
            else if(possible(x-1,y))
            {
                x=x-1;
            }
            else if(possible(x+1,y))
            {
                x=x+1;
            }
            else
                y=y+1;
        }
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
	return 0;

}
