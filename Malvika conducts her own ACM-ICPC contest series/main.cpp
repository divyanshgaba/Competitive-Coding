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

bool poss(int c,int e,int m,int h)
{
    if(e <0 || m < 0)
        return false;
    int t = ceil(double(c)/2);
    if(c <= min(t,e) + min(t,m) + min(t,h))
        return true;
    return false;
}

void solve()
{
    int e,m,h;
    cin>>e>>m>>h;
    int ans = 0;
    int lo = 0, hi = 1e6;
    while(lo<hi)
    {
        int mid = (lo+hi)/2;
        if(poss(mid,e-mid,m-mid,h))
        {
            lo = mid+1;
            ans = mid;
        }
        else
        {
            hi = mid;
        }
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
