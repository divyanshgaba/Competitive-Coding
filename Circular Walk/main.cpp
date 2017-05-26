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

const int INF = 1e9;
int n,s,t;
ll r[10000001];
void build(int n,ll g, ll seed,ll p)
{
    for(int i =1;i<n;i++)
    {
        r[i] = (r[i-1]*g +seed)%p;
    }
}
ll memo[10000001];
bool marked[10000001];
ll solve(int i)
{
    cout<<i<<endl;
    if(marked[i])
        return INF;
    if(i == t)
        return 0;
    if(r[i] == 0)
        return INF;
    if(memo[i]!=0)
        return memo[i];
    ll temp = INF;

    for(int j = -r[i];j<=r[i];j++)
    {
        if(j==i)
            continue;
        int h = i + j;
        if(h>=n)
            h%=n;
        if(h<0)
            h+=n;
        marked[i]=true;
        temp = min(temp,1+solve(h));
        marked[i]=false;
    }
    memo[i]=temp;
    return temp;

}


int main()
{
	fast;

	cin>>n>>s>>t;
	ll g,seed,p;
	cin>>r[0]>>g>>seed>>p;
	build(n,g,seed,p);
    cout<<solve(s)<<endl;
	return 0;

}
