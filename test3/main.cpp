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


int main()
{
	fast;
	int n;
	cin>>n;
	int a[n+1];
	memset(a,0,sizeof(a));
	int t;
	cin>>t;
	while(t--)
    {
        int x,y;
        cin>>x>>y;
        a[x]+=y;
    }
    int ans[n+2];
    memset(ans,0,sizeof(ans));
    for(int i =n;i>0;i--)
    {
        if(a[i]>=i)
        {

            ans[i] += a[i]/i;
            a[i] %=i;
        }
        ans[i]+=ans[i+1];
        a[a[i]]+=a[i];

    }
    for(int i =1;i<=n;i++)
        cout<<ans[i]<<" ";

	return 0;

}
