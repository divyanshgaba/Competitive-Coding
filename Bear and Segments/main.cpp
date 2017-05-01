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
int main()
{
	fast;
	ll test;
	cin>>test;
	while(test--)
    {
        ll n,p;
        cin>>n>>p;
        ll a[n];
        for(int i =0;i<n;i++)
        {
            cin>>a[i];

        }
        map<ll,ll> mp;
        mp[0]=1;
        mp[p]=1;
        ll now =0;
        ll ele=0;
        ll cnt=0;
        for(int i =0;i<n;i++)
        {
            now = (now + a[i])%p;
            auto x = *(mp.lower_bound((now+1+p)%p));
            if((now-x.first+p)%p > ele)
            {
                ele = (now-x.first + p )%p;
                cnt = x.second;
            }
            else if( (now-x.first+p)%p == ele)
                cnt+=x.second;
            mp[now]++;
        }
        cout<<ele<<" "<<cnt<<endl;
    }
	return 0;

}
