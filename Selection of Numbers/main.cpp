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
    int k,n;
    cin>>k>>n;
    ll a[n+1],pre[n+1],suf[n+2];
    for(int i  = 1;i<=n;i++)
        cin>>a[i];
    pre[0]=0;
    for(int i = 1;i<n;i++)
        pre[i]=pre[i-1]+a[i];
    suf[n+1]=0;
    for(int i = n;i>=0;i--)
        suf[i]=suf[i+1]+a[i];
    ll ans = 0;
    for(int i = 0;i<=k;i++)
        ans = max(ans,pre[i]+suf[n-k+i+1]);
    cout<<ans<<endl;
	return 0;

}
