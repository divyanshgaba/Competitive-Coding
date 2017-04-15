#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;

const ll mod = 1e9 + 7;

int main()
{
	fast;
	ll test;
	cin>>test;
	while(test--)
    {
        int n,d,r;
        cin>>n>>d>>r;
        int q =0;
        while(r-- > 0)
        {
            while(n>=d) n-=d;
            int p = n = 5*n;
            for(q=0;n>d;n-=d)q++;
            while(p>=d)p-=d;
            n=p<<1;
        }
        for(;n>=0;n-=d)r++;
        cout<<(q<<1)+r<<endl;


    }
	return 0;

}
