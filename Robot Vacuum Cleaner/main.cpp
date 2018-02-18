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
#define REP(i,a,b) for (ll i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;


ll ans(string s)
{
    ll n = s.length();
    ll suf[n];
    if(s[n-1]=='h')
        suf[n-1]=1;
    else
        suf[n-1]=0;
    for(ll i = n-2;i>=0;i--)
    {
        if(s[i]=='h')
            suf[i] = suf[i+1]+1;
        else
            suf[i]=suf[i+1];
    }
    ll cnt = 0;
    for(ll i = 0;i<n;i++)
    {
        if(s[i]=='s')
            cnt += suf[i];
    }
    return cnt;
}

bool cmp(string a,string b)
{
    return ans(a+b) > ans(b+a);
}

int main()
{
	fast;
	ll n;
	cin>>n;
	vector<string> s;
	for(ll i = 0;i<n;i++)
    {
        string k;
        cin>>k;
        s.PB(k);
    }
    sort(s.begin(),s.end(),cmp);
    string p="";
    for(auto i:s)
        p+=i;
    cout<<ans(p)<<endl;
	return 0;

}
