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

int n;
int grid[501][501];
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        cin>>n;
        pi one;
        map<int,pi> mp;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                cin>>grid[i][j];
                mp[grid[i][j]] = MP(i,j);
                if(grid[i][j]==1)
                    one = MP(i,j);
            }
        }
        int ans =0;
        pi temp = one;
        for(int i =2;i<=n*n;i++)
        {
            ans =ans + abs(mp[i].F - temp.F) + abs(mp[i].S-temp.S);
            temp = mp[i];
        }
        cout<<ans<<endl;

    }

	return 0;

}
