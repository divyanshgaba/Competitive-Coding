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
typedef pair<int,int> pi;
vector<ll> primes;
const ll MN = 1e12+1;
const ll N = 1e6+10;
bool vis[N];
unordered_map<ll,bool> m;
void sieve()
{
    vis[2]=true;
    primes.PB(2);
    for(int i = 4;i<N;i+=2)
        vis[i]=true;
    for(ll i = 3;i<N;i+=2)
    {
        if(!vis[i])
        {
            primes.PB(i);
            for(ll j = i+i;j<N;j+=i)
                vis[j]=true;
        }
    }
    for(auto i:primes)
    {
        ll k = i*i;
        while(k<=N)
            m[k]=true,k*=(i*i);
    }
}
bool sqr(ll n)
{
    ll sq = sqrt(n);
    if(sq*sq == n)
        return true;
    return false;
}
int main()
{
	fast;
	sieve();
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		ll p[n],s[n];
		unordered_map<ll,int> ind;
        for(int i = 0;i<n;i++)
            cin>>p[i];
        sort(p,p+n,greater<ll>());
        for(int i = 0;i<n;i++)
            ind[p[i]]=i+1;
        int k = 0;
        unordered_map<ll,bool> h;
        for(int i = 0;i<n;i++)
        {
            if(sqr(p[i]))
            {
                if(m[p[i]])
                {
                    h[p[i]]= true;
                    k++;
                }
            }
        }
        if(k==0)
            cout<<"No supporter found.\n";
        else
        {
            for(int i = 0;i<n;i++)
                if(h[p[i]])
                    cout<<ind[p[i]]<<" ";
            cout<<endl;
        }

    }
	return 0;

}
