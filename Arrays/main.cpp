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
struct node
{
    ll a,b,c;
    ll ans;
};
ll k,n;
const int N = 3e5+5;
node g[N];

ll f(ll a,ll b,ll c,ll t)
{
    int ans =  (a+t)%k + (b+t)%k  + (c+t)%k ;
    cout<<a<<" "<<b<<" "<<c<<" "<<t<<" "<<ans<<endl;
    return ans;
}

int main()
{
	fast;
	cin>>n>>k;
	ll answer = 0;
	for(int i = 0;i<n;i++)
    {
        cin>>g[i].a>>g[i].b>>g[i].c;
    }
    for(int i = 0;i<k;i++)
    {
        for(int j = 0;j<n;j++)
            f(g[j].a,g[j].b,g[j].c,i);
        cout<<endl;
    }

	return 0;

}
