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


ll distance(ll x,ll y)
{
    return ceil(sqrt(x*x + y*y));
}

int main()
{
	fast;
    int n,k;
    cin>>n>>k;
    ll x[n],y[n];
    for(int i = 0;i<n;i++) cin>>x[i];
    for(int i = 0;i<n;i++) cin>>y[i];
    vector<ll> dist;
    for(int i = 0;i<n;i++) dist.PB(distance(x[i],y[i]));
    sort(dist.begin(),dist.end());
    cout<<dist[k-1]<<endl;
	return 0;

}
