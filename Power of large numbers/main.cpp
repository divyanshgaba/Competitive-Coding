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

const ll MOD = 1e9 +7;

ll mod_pow(ll a,ll b)
{
    if(a==0)
        return 0;
    if(a == 1 || b==0)
        return 1;
    if(b== 1)
        return a%MOD;
    if(b==2)
        return (a*a)%MOD;
    if(b&1)
        return (a*mod_pow(a,b-1))%MOD;
    return mod_pow(mod_pow(a,b/2),2)%MOD;
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		string a,b;
		cin>>a>>b;
        ll x = 0;
        for(auto i:a)
        {
            x = (x*10 + i-'0')%MOD;
        }
        ll ans = 1;
        for(auto i:b)
        {
            ans = mod_pow(ans,10);
            ans = (ans*mod_pow(x,i-'0'))%MOD;
        }
        cout<<ans<<endl;
    }
	return 0;

}
