/*
ID: divyans19
PROG: castle
LANG: C++11
*/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); fin.tie(0); fout.tie(0);
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
int a[50][50];

int grid[52][52];
ifstream fin("castle.in");ofstream fout("castle.out");
int getmax(int i,int j,int token)
{
    if(grid[i][j])
        return 0;
    grid[i][j]=token;
    int temp = a[i][j];
    int ans =1;
    if(temp>=8)
    {
        temp-=8;
    }
    else
    {
        ans = ans  + getmax(i+1,j,token);
    }
    if(temp>=4)
    {
        temp-=4;
    }
    else
    {
        ans= ans+getmax(i,j+1,token);
    }
    if(temp>=2)
    {
        temp-=2;
    }
    else
    {
        ans = ans+getmax(i-1,j,token);
    }
    if(temp>=1)
    {
        temp-=1;
    }
    else
    {
        ans = ans+getmax(i,j-1,token);
    }
    return ans;
}

int adjacant(int i, int j, int r)
{
    if(i!=0)
    {
        if(grid[i-1][j]==r)
            return 1;
    }
    if(j!=n)
    {
        if(grid[i][j+1] == r)
            return 2;
    }

    return 0;
}

pair<pi,int> rightpair(pair<pi,int> a, int i,int j, int dir)
{
    pair<pi,int> ans = MP(MP(i,j),dir);
    if(a.F.S < j)
        return a;
    if(a.F.S > j)
        return ans;
    if(a.F.F > i)
        return a;
    if(a.F.F < i)
        return ans;
    if(a.S < dir)
        return a;
    return ans;

}

int main()
{
	//fast;
    fin>>n>>m;
    memset(grid,0,sizeof(grid));
    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            fin>>a[i][j];
        }
    }
    vector<int> room;
    int token =1;
    int largest =0;
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(grid[i][j]==0)
            {
                int temp =getmax(i,j,token++);
                largest = max(largest,temp);
                room.PB(temp);
            }
        }
    }
    fout<<token-1<<endl;
    fout<<largest<<endl;
    //for(auto it:room)        fout<<it<<" ";    fout<<endl;
    int lcom = 0;
    pair<pi,int> ans;

    for(int j =0;j<n;j++)
    {
        for(int i =m-1;i>=0;i--)
        {
            if(i!=0)
            {
                if(grid[i][j] != grid[i-1][j] && lcom < room[ grid[i][j] - 1 ] + room[ grid[i-1][j] - 1] )
                {
                    //fout<<lcom<<" "<<room[grid[i][j]-1]<<" "<<room[grid[i-1][j]-1]<<endl;
                    lcom = room[grid[i][j]-1] + room[grid[i-1][j]-1];
                    ans = MP(MP(i,j),1);
                }
            }
            if(j!=n-1)
            {
                if(grid[i][j] != grid[i][j+1]&&lcom < room[grid[i][j]-1] + room[ grid[i][j+1]-1])
                {
                    //fout<<lcom<<" "<<room[grid[i][j]-1]<<" "<<room[grid[i][j+1]-1]<<endl;

                    lcom = room[grid[i][j]-1] + room[grid[i][j+1]-1];
                    ans = MP(MP(i,j),2);
                }
            }

        }
    }
    fout<<lcom<<endl;
    fout<<ans.F.F+1<<" "<<ans.F.S+1<<" ";
    if(ans.S == 1)
        fout<<"N\n";
    else if(ans.S == 2)
        fout<<"E\n";
    /*for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            fout<<grid[i][j]<<" ";
        }
        fout<<endl;
    }*/
	return 0;

}
