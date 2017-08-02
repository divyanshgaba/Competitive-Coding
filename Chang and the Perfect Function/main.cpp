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
const ll N = 1e6;
vector<ll> sq;
void pre()
{
    ll i = 0;
    while(i*i <= N*N + N)
    {
        sq.PB(i*i);
        i++;
    }
}



int main()
{
	fast;
	pre();
    ll a,b;
    cin>>a>>b;
    ll ans = 0;
    for(int i = 1;i<=a;i++)
    {
        ll ele = sq[i] + b;
        ans += (upper_bound(sq.begin(),sq.end(),ele) - upper_bound(sq.begin(),sq.end(),sq[i]));
    }
    cout<<ans<<endl;
	return 0;

}
