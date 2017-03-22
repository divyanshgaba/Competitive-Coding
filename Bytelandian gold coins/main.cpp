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
map<ll,ll> mem;
ll answer(ll n)
{
    if(mem.count(n)!=0) //   mem[n] !=0 return mem[n];
        return mem[n];
    mem[n] =  max(n,answer(n/2)+answer(n/3)+answer(n/4));
    return mem[n];
}

int main()
{
	fast;
	ll n;
	while(cin>>n)
    {
        cout<<max(n,answer(n))<<"\n";
    }

	return 0;

}
