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
int n,p,q,s1,s2,b1,b2;
const ll mod = 1e9 + 7;
ll dp[111][61][61][61];
ll solve(int l,int box, int bs1,int bs2)
{
    if(bs1 < 0 || bs2 < 0 || box < 0)
        return 0;
    if(l == n)
        return 1;
    if(l > n)
        return 0;
    if(dp[l][box][bs1][bs2]!=-1)
        return dp[l][box][bs1][bs2];
    ll temp = 0;
    for(int i = 1;i<=min(s1,bs1);i++)
    {
        for(int j = 1;j<=min(s2,bs2);j++)
        {
            temp += solve(l+i+j,box-1,bs1-i,bs2-j);
            if(temp>=mod)
                temp%=mod;
        }
    }
    return dp[l][box][bs1][bs2] = temp;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        memset(dp,~0,sizeof(dp));
		cin>>p>>q>>n>>b1>>b2>>s1>>s2;
        ll ans = 2*solve(0,min(b1,b2),p,q);
        for(int i = 1;i<=min(s1,p);i++)
        {
            ans += solve(i,min(b1-1,b2),p-i,q);
            if(ans>=mod)
                ans%=mod;
        }
        for(int i = 1;i<=min(s2,q);i++)
        {
            ans+= solve(i,min(b1,b2-1),p,q-i);
            if(ans>=mod)
                ans%=mod;
        }
        cout<<ans<<endl;
    }
	return 0;

}
