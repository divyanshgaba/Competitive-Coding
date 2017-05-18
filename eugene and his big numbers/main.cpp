#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

ll m;
ll exp(ll b,ll e)
{
    ll r =1;
    while(e>0)
    {
        if(e&1)r=(r*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return r%m;1;
}
ll c;
ll solve(ll a,ll n)
{
    if(n==1)
        return a%m;
    ll t = solve(a,n/2);
    if(n & 1)
        return ((exp(10,c)*((t*exp(10,c*(n/2))%m+t)%m))%m+a%m)%m;
    return ((t*exp(10,c*(n/2)))%m+t)%m;
}
int main()
{
    fast;
    int test;
    cin>>test;
    while(test--)
    {
        ll a,n;
        cin>>a>>n>>m;
        c = log10(a)+1;
        cout<<solve(a,n)<<endl;
    }
    return 0;
}
