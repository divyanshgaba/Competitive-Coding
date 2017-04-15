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
typedef pair<int,int> pi;

int n,m;
int a[50][50];

int grid[52][52];

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
    if(i!=m)
    {
        if(grid[i+1][j]==r)
            return 3;
    }
    if(j!=0)
    {
        if(grid[i][j-1]==r)
            return 4;
    }
    return 0;
}

int main()
{
	fast;
    cin>>n>>m;
    memset(grid,0,sizeof(grid));
    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    vi room;
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
    cout<<token-1<<endl;
    cout<<largest<<endl;
    int rooms = room.size();
    //for(auto it:room)        cout<<it<<" ";    cout<<endl;
    int lcom = 0;
    pair<pi,int> ans;
    for(int i =1;i<rooms;i++)
    {
        for(int j =i+1;j<=rooms;j++)
        {
            int flag =0;
            for(int k =0;k<m;k++)
            {
                for(int l =0;l<n;l++)
                {
                    if(grid[k][l] == i)
                    {
                        int temp =0;
                        if(temp = adjacant(k,l,j))
                        {
                            if(lcom <= room[i-1] + room[j-1])
                            {
                                ans = MP(MP(k,l),temp);
                                lcom = room[i-1]+room[j-1];
                               // cout<<i<<" "<<j<<endl;                                cout<<lcom<<endl;
                                flag =1;
                                break;
                            }
                        }
                    }
                }
            }

        }
    }
    cout<<lcom<<endl;
    cout<<ans.F.F<<" "<<ans.F.S<<" "<<ans.S<<endl;
    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;

}
