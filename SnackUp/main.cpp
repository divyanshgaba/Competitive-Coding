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

int grid[101][101];

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n;
        memset(grid,0,sizeof(grid));
        cin>>n;
        int cnt = 0;
        cout<<n<<endl;
        for(int i = 0;i<n;i++)
        {
            cout<<n<<endl;
            for(int j=0;j<n;j++)
            {
                cout<<j+1<<" "<<cnt%n + 1<<" "<<(cnt+1)%n + 1<<endl;
                grid[j][cnt%n]++;
                grid[j][(cnt+1)%n]++;
                cnt = (cnt+1)%n;
            }
            cnt = (cnt+1)%n;
        }


    }
	return 0;

}
