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

void solve()
{
    int n;
    cin>>n;
    ll a[n];
    for(int i = 0;i<n;i++)
        cin>>a[i];
    ll curr = 1e15;
    ll ans = 0;
    for(int i = 0;i<n;i++)
    {
        if(curr >= a[i])
            ans++;
        curr = min(a[i],curr);
    }
    cout<<ans<<endl;
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        solve();
    }
	return 0;

}
