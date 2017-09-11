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
	ll n,m,k;
	cin>>n>>m>>k;
	unordered_map<ll,vector<pair<ll,ll>>> mp;
	for(int i = 0;i<k;i++)
    {
        ll r,c1,c2;
        cin>>r>>c1>>c2;
        mp[r].PB(MP(c1,c2));
    }
    long long ans = n*m;
    for(auto i:mp)
    {
        sort(i.S.begin(),i.S.end());
        ll s =0,e=0;
        for(auto j:i.second)
        {
            if(e < j.second)
            {
                s = max(j.first,s);
                e=j.second;
                ans -=(e-s + 1);
                s = e+1;
            }
        }
    }
    cout<<ans<<endl;
	return 0;

}
