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
const ll N = 20000;
vector<ll> primes;
bool vis[N+8];
int main()
{
	fast;
	for(ll i = 4;i<=N;i+=2LL)
    {
        vis[i]=true;
    }
    primes.PB(4);
    for(ll i = 3;i<=N;i+=2LL)
    {
        if(!vis[i])
        {
            for(ll j = i*i;j<=N;j+=i)
                vis[j]=true;
        }
    }
    for(ll i = 3;i<=N;i+=2)
    {
        if(!vis[i])
            primes.PB(i*i);
    }
    ll limit[] = {0, 3, 39, 392, 3917, 39206, 392074, 3920709, 39207306};
    ll n;
	cin>>n;
	ll st = 1;
	for(int i = 0;i<9;i++)
    {
        if(n>limit[i])
            st = 10*st;
    }
    cout<<st<<endl;
	return 0;

}
