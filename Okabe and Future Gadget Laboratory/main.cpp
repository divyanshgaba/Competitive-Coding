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
int n;
int a[51][51];
bool is_true(int r,int c,int ele)
{
    for(int i = 0;i<n ;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(a[r][i] + a[j][c] == ele)
                return true;
        }
    }
    return false;
}


void solve()
{
    cin>>n;
    for(int i = 0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    bool ans = true;
    for(int i = 0;i<n&&ans;i++)
    {
        for(int j=0;j<n&&ans;j++)
        {
            if(a[i][j]!=1)
            {
                ans = false;
                ans = is_true(i,j,a[i][j]);
            }

        }
    }
    if(ans)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

int main()
{
	fast;
	int test=1;
	//cin>>test;
	while(test--)
    {
        solve();
    }
	return 0;

}
