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

int main()
{
	fast;
	int test=1;
	cin>>test;
	ll answer = 0;
	while(test--)
    {
		ll a;
		cin>>a;
		vector<ll> f;
		ll h = a;
		for(int i = 2;i<=sqrt(a);i++)
        {
            while(h%i==0)
                f.PB(i),h/=i;
        }
        if(h>1)
            f.PB(h);
        sort(f.begin(),f.end(),greater<ll>());
        ll ans = 0;
        ll cnt = 1;
        for(auto i:f)
        {
            ans+=cnt;
            cnt *=i;
        }
        ans+=cnt;
        answer+=ans;
    }
    cout<<answer<<endl;
	return 0;

}
