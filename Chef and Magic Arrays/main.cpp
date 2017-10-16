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
#define REP(i,a,b) for (ll i = a; i <= b; i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
const int INF = 1e16;
int main()
{
    fast;
    ll test = 1;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        vector<ll> in[n+1];
        for(ll i = 1;i<=n;i++)
        {
            ll a;
            cin>>a;
            for(ll j = 0;j<a;j++)
            {
                ll t;
                cin>>t;
                in[i].PB(t);
            }
        }
        ll dp[n+1][2];
        memset(dp,0,sizeof(dp));
        dp[1][0]=*max_element(in[1].begin(),in[1].end());
        dp[1][1]=-(*min_element(in[1].begin(),in[1].end()));
        for(ll i =2;i<=n;i++)
        {
            dp[i][0]=dp[i][1]=-INF;
            ll s = in[i].size();
            for(ll j = 0;j<s;j++)
            {
                ll temp = j-1;
                if(temp<0)
                    temp+=s;
                dp[i][0]=max(dp[i][0],in[i][j]*(i-1)+dp[i-1][1]+i*in[i][temp]);
                dp[i][0]=max(dp[i][0],-in[i][j]*(i-1)+dp[i-1][0]+i*in[i][temp]);
                dp[i][1]=max(dp[i][1],in[i][j]*(i-1)+dp[i-1][1]-i*in[i][temp]);
                dp[i][1]=max(dp[i][1],-in[i][j]*(i-1)+dp[i-1][0]-i*in[i][temp]);
            }
        }
        ll last_min = *min_element(in[n].begin(),in[n].end());
        ll last_max = *max_element(in[n].begin(),in[n].end());
        cout<<max(dp[n-1][0]-(n-1)*last_min,dp[n-1][1]+(n-1)*last_max)<<endl;
    }
    return 0;

}
