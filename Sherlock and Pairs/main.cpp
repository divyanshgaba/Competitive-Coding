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

map<pair<ll,ll>, ll> mp;

ll nCr(ll n,ll r)
{
    if(n < r)
        return 0;
    if(n==r || r==0)
        return 1;
    if(mp.count(MP(n,r)) > 0)
        return mp[MP(n,r)];
    return mp[MP(n,r)] = nCr(n-1,r-1) + nCr(n-1,r);
}


int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        ll a[n];
        unordered_map<ll,ll> m;
        for(int i = 0;i<n;i++)
            cin>>a[i],m[a[i]]++;
        ll ans = 0;
        for(auto i:m)
            ans+=nCr(i.S,2);
        cout<<2*ans<<endl;

    }
	return 0;

}
