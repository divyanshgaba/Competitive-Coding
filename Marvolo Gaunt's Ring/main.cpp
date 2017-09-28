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
	ll n,p,q,r;
	cin>>n>>p>>q>>r;
	ll a[n];
	for(int i = 0;i<n;i++) cin>>a[i];
	ll maxim[n],minim[n];
	maxim[0]=minim[0]=a[0];
	for(int i = 1;i<n;i++)
    {
        maxim[i] = max(maxim[i-1],a[i]);
        minim[i] = min(minim[i-1],a[i]);
    }
    ll premaxim[n],preminim[n];
    premaxim[n-1]=preminim[n-1] = a[n-1];
    for(int i = n-2;i>=0;i--)
    {
        premaxim[i] = max(premaxim[i+1],a[i]);
        preminim[i] = min(preminim[i+1],a[i]);
    }
    ll ans = p*a[0]+q*a[0]+r*a[0];
    for(int i = 0;i<n;i++)
    {
        ans = max(ans, max(p*minim[i],p*maxim[i]) + q*a[i] + max(r*preminim[i],r*premaxim[i]));
    }
    cout<<ans<<endl;
	return 0;

}
