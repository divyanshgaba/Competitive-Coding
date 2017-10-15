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
typedef pair<int,ll> pi;
const int N = 2e4+2;
const int MAXN = 200;
const int INF = 1e13;

bool vis[MAXN+1];
vector<ll> primes;
vector<int> ans;
int n,m;
void sieve()
{
    primes.PB(2);
    for(ll i = 3;i<=sqrt(MAXN);i+=2)
    {
        if(!vis[i])
        {
            vis[i]=true;
            primes.PB(i);
            for(ll j = i+i;j<=MAXN;j+=i)
                vis[j]=true;
        }
    }
    for(ll i =3;i<=MAXN;i+=2)
        if(!vis[i])
            primes.PB(i);
}
ll key[N];
unordered_map<int,ll> val;
vector<pi> g[N];
bool mark[N];
void dijkstra(int s,int dest)
{

        vector<ll> d (n, INF);
        vector<int>  p (n);
        d[s] = 0;
        vector<char> u (n);
        for (int i=0; i<n; ++i) {
            int v = -1;
            for (int j=0; j<n; ++j)
                if (!u[j] && (v == -1 || d[j] < d[v]))
                    v = j;
            if (d[v] == INF)
                break;
            u[v] = true;
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first,
                    len = g[v][j].second;
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                }
            }
        }
    for (int v=dest; v!=s; v=p[v])
        ans.push_back (v);
    ans.push_back (s);

}
int check(ll n)
{
    int cnt = 0;
    ll ans = 1;
    for(auto i:primes)
    {
        ans*=i;
        if(ans<=n)
            cnt++;
        else
            break;
    }
    return cnt;
}
int main()
{
	fast;
	sieve();
    cin>>n>>m;
    ll src = 1e18;
    ll dest = 0;
    for(int i = 0;i<n;i++)
        cin>>key[i],val[key[i]]=i,src=min(src,key[i]),dest=max(dest,key[i]);
    for(int i = 0;i<m;i++)
    {
        int a,b;
        ll w;
        cin>>a>>b>>w;
        g[val[a]].PB({val[b],w});
    }
    dijkstra(val[src],val[dest]);
    int answer = 0;
    for(auto i:ans)
    {
        //cout<<i<<" ";
        answer+=check(key[i]);
    }
    cout<<answer<<endl;
	return 0;

}
