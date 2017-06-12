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
char grid[21][21];
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        cin>>n>>m;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                cin>>grid[i][j];
            }
        }
        cout<<answer(0,0,0)<<endl;
    }
	return 0;

}
