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

const ll INF = 2000000000;
bool graph[251][251];
ll n,m,e;
bool bpm(ll u, bool seen[], ll matchR[])
{
    for (ll v = 0; v < n; v++)
    {
        if (graph[u][v] && !seen[v])
        {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
ll maxBPM()
{
    ll matchR[n];
    memset(matchR, -1, sizeof(matchR));
    ll result = 0;
    for (ll u = 0; u < m; u++)
    {
        bool seen[n];
        memset(seen, 0, sizeof(seen));
         if (bpm(u, seen, matchR))
            result++;
    }
    return result;
}
ll maxi(ll c[],ll d[],ll x)
{
    memset(graph,0,sizeof(graph));
    ll f[m];
    for(ll i =0;i<m;i++)
        f[i] = c[i]+x;
    for(ll i =0;i<m;i++)
    {
        for(ll j = 0;j<n;j++)
        {
            if(llabs(f[i] - d[j]) <= e)
                graph[i][j]=1;
        }
    }
    return maxBPM();
}

ll answer(ll c[],ll d[])
{
    if(lo>=hi)
        return -1;
    ll mid = (lo+hi)/2;
    ll ans = maxi(c,d,mid);
    ans = max(ans,max(answer(c,d,lo,mid-1),answer(c,d,mid+1,hi)));
    return ans;
}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        memset(graph,0,sizeof(graph));
        cin>>m>>n>>e;
        ll c[m],d[n];
        for(int i =0;i<m;i++)
            cin>>c[i];
        for(int i =0;i<n;i++)
            cin>>d[i];
        ll lo = d[0] - c[m-1] - e;
        ll hi = d[n-1] - c[0] + e;
        cout<<answer(c,d,lo,hi)<<endl;
        //cout<<maxi(c,d,3)<<" "<<maxi(c,d,5)<<endl;

    }
	return 0;

}
