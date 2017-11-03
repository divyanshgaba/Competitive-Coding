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
	int n;
	cin>>n;
	ll a[n];
	for(int i = 0;i<n;i++) cin>>a[i];
	int m;
	cin>>m;
	ll b[m];
	for(int i = 0;i<m;i++) cin>>b[i];
	ll ele = *max_element(b,b+m) + 1;
	ll ans = 0;
	for(int i = 0;i<n;i++)
    {
        if(a[i]<ele)
            ans += (ele-a[i]);
    }
    cout<<ans<<endl;
	return 0;

}
