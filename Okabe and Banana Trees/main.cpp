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

ll sum_of_series(ll n)
{
    return (n*(n+1))/2;
}
ll ans(ll x,ll y)
{
    return sum_of_series(x)*(y+1) + sum_of_series(y)*(x+1);
}
void solve()
{
    ll m,b;
    cin>>m>>b;
    ll x = m*b;
    ll y = b;
    ll sol = max(ans(x,0),ans(0,y));
    //cout<<sol<<endl;
    if(x&1 && y&1)
    {
        //cout<<"if"<<endl;
        sol = max(sol,ans((x+1)/2,(y/2)));
        //cout<<sol<<endl;
        sol = max(sol,ans((y+1)/2,x/2));
        //cout<<sol<<endl;
    }
    else if(x&1)
    {
        sol = max(sol,ans(y/2,(x+1)/2));
    }
    else if(y&1)
    {
        sol = max(sol,ans((y+1)/2,x/2));
    }
    else
    {
        sol = max(sol,ans(x/2,y/2));
    }
    cout<<sol<<endl;
}

int main()
{
	fast;
	int test=1;
	//cin>>test;
	while(test--)
    {
        solve();
    }
	return 0;

}
