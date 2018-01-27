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
	ll n,k;
	cin>>n>>k;
	ll ans = 0;
	if(n/k >= 1)
    {
        ll first = n/k;
        ans += ((k*first*(first-1))/2);
        ll second = n%k;
        ans += first*second;
    }
    cout<<ans<<endl;
	return 0;

}
