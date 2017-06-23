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
const int N = 1e6;
const ll mod = 1e9 +7;
ll a[N];
ll mod_exp(ll a,ll b)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    if(b == 2)
        return (a*a)%mod;
    if(b&1)
        return (a*mod_exp(a,b-1))%mod;
    return mod_exp(mod_exp(a,b/2)%mod,2)%mod;
}
int main()
{
	fast;
	string s;
	cin>>s;
	int n = s.length();
	if(s[0]=='a')
        a[0]=1;
	for(int i = 1;i<n;i++)
    {
        if(s[i] == 'a')
            a[i] = a[i-1] + 1;
        else
            a[i] = a[i-1];

    }
    ll ans = 0;
    for(int i = n-1;i>0;i--)
    {
        if(s[i]=='b')
            ans = (ans + mod_exp(2LL,a[i-1])-1)%mod;
    }
    cout<<ans<<endl;

	return 0;

}
