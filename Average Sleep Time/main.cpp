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
	int n,k;
	cin>>n>>k;
	double a[n];
	for(int  i=0;i<n;i++)
    {
        cin>>a[i];
    }
    double ans =0;
    double hold[n-k+1];
    memset(hold,0,sizeof(hold));
    for(int i =0;i<k;i++)
    {
        hold[0]+=a[i];
    }
    ans = hold[0]/(n-k+1);
    for(int i = 1 ;i<n-k+1;i++)
    {
        hold[i] = hold[i-1] - a[i-1] + a[i+k-1];
        ans+=(hold[i]/(n-k+1));
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;


	return 0;

}
