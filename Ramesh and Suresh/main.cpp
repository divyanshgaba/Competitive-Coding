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
unordered_map<ll,ll> mp;



int main()
{
	fast;
	int n;
	cin>>n;
	ll a[n];
	for(int i = 0;i<n;i++) cin>>a[i],mp[a[i]]++;
	ll sum = 0;
    set<ll,greater<ll> > s(a,a+n);
    for(auto i:s)
    {
        bool sett = false;
        ll ch = -1;
        ll ans = -1e16;
        ll ele = i;
        if(s.find(ele) != s.end()  &&mp[ele]!=0&& ele*mp[ele] > ans)
        {
            ans = ele*mp[ele];
            sett = true;
            ch = ele;
        }
        ele = i+1;
        if(s.find(ele) != s.end()  &&mp[ele]!=0&& ele*mp[ele] > ans)
        {
            ans = ele*mp[ele];
            sett=true;
            ch = ele;
        }
        ele = i-1;
        if(s.find(ele) != s.end() &&mp[ele]!=0&& ele*mp[ele] > ans)
        {
            ans = ele*mp[ele];
            sett=true;
            ch = ele;
        }
        if(sett)
            mp[ch] = mp[ch-1] = mp[ch+1] = 0;
        //cout<<i<<" "<<ans<<endl;
        if(sett)
            sum+=ans;
    }
    cout<<sum<<endl;

	return 0;

}
