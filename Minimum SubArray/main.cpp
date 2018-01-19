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
const ll INF = 1e10;
const ll N = 1e5+10;
const ll rtN = sqrt(N);
vector<vector<ll>> dp(rtN,vector<ll>(rtN,-INF));
ll dpSum[rtN+1];
ll sub(int i,ll n, ll x)
{
    ll curr_sum = 0, min_len = n+1;
    ll start = 0, end = 0;
    while (end < n)
    {
        while (curr_sum <=x && end < n)
        {
            if (curr_sum <= 0 && x > 0)
            {
                start = end;
                curr_sum = 0;
            }
            curr_sum += dp[i][end++];
        }
        while (curr_sum >= x && start < n)
        {
            if (end!=start&&end - start < min_len)
                min_len = end - start;

            curr_sum -= dp[i][start++];
        }
    }
    return min_len;
}
ll n,d;
void init(ll n)
{
    for(ll i = 0;i<n;i++)
        dp[i/rtN][i%rtN]=-INF,dpSum[i/rtN + 1] = 0;
}
vector<ll> v(2*rtN);
ll sub(ll n, ll x)
{
    ll curr_sum = 0, min_len = n+1;
    ll start = 0, end = 0;
    while (end < n)
    {
        while (curr_sum <=x && end < n)
        {
            if (curr_sum <= 0 && x > 0)
            {
                start = end;
                curr_sum = 0;
            }
            curr_sum += v[end++];
        }
        while (curr_sum >= x && start < n)
        {
            if (end!=start&&end - start < min_len)
                min_len = end - start;

            curr_sum -= v[start++];
        }
    }
    return min_len;
}
int main()
{
	ifstream cin("input.txt");	ofstream cout("output.txt");
	fast;
	ll test=1;
	cin>>test;
	while(test--)
    {
        init(n);
		cin>>n>>d;
		ll a[n];
		for(ll i = 0;i<n;i++)
        {
            cin>>a[i];
            dp[i/rtN][i%rtN] = a[i];
            dpSum[i/rtN + 1]+= a[i];
        }
        ll nBlock = n/rtN + 1;
        ll ans = n+1;
        for(ll i = 0;i<nBlock-1;i++)
        {
            ans = min(ans,sub(i,rtN,d));
        }
        ans = min(ans,sub(n/rtN,n%rtN,d));
        for(ll i = 0;i<nBlock;i++)
        {
            for(ll j = i+1;j<nBlock;j++)
            {
                ll x = d - dpSum[j] + dpSum[i];
                int k = 0;
                for(k = 0;k<rtN;k++)
                    v[k]=dp[i][k];
                if(j!=nBlock)
                {
                    for(;k<2*rtN;k++)
                        v[k]=dp[j][k-rtN];
                }
                else
                {
                    for(int h = 0;h<n%rtN;h++)
                        v[k++]=dp[j][h];
                }
                ans = min(ans,sub(k,x) + (j-i)*rtN);
            }
        }
        if(ans>n)
            cout<<-1<<"\n";
        else
            cout<<ans<<"\n";
        //if(test%1000==0)        std::cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms"<<endl;

    }
    std::cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms"<<endl;
	return 0;

}
