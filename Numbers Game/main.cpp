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
typedef pair<ll,ll> pi;


const ll m= 1e9+7;
int main()
{
	fast;
	int n;
    cin>>n;
    ll sum = 0;
    pi dp[n];
    ll b[n];
    for(int i = 0;i<n;i++)
    {
        cin>>b[i],sum+=b[i];
    }
    dp[0] = MP(b[0]/2 + 1, b[0]/2 + b[0]%2);
    for(int i = 1;i<n;i++)
    {
        ll even = b[i]/2 + 1;
        ll odd = b[i]/2 + b[i]%2;
        dp[i] = MP( ((dp[i-1].F*even)%m + (dp[i-1].S*odd)%m)%m, (dp[i-1].S*even)%m + (dp[i-1].F*odd)%m);
    }
    ll cnt = 1;
    ll a[n];
    for(int i = 0;i<n;i++)
    {
        cnt *= max(1LL,ll(log2(b[i])-1));
        cnt = cnt%m;
    }
    cout<<(dp[n-1].F - 1 + sum/2 + sum%2 -cnt)%m<<endl;
	return 0;

}
