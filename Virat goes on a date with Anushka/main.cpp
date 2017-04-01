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


int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int temp;
	int ans=0;
	for(int i =0;i<n;i++)
    {
        temp = 1e9;
        for(int j =0;j<m;j++)
        {
            cin>>a[i][j];
            temp = min(temp,a[i][j]);
        }
        ans = max(temp,ans);
    }
    cout<<ans<<endl;

	return 0;

}
