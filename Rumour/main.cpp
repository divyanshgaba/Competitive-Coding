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
ll INF = 1e9;
ll bin(vector<ll> a,ll ele)
{
    ll low = 0,high = a.size()-1;
    while(low<=high)
    {
        ll mid = (low+high)/2;
        if(ele==a[mid])
            return mid;
        else if(ele<a[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return INF;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		ll a,b;
		cin>>a>>b;
		vector<ll> pa,pb;
		while(a)
        {
            pa.PB(a);
            a/=2;
        }
        while(b)
        {
            pb.PB(b);
            b/=2;
        }
        ll ans = 1e9;
        for(int i = 0;i<pa.size();i++)
        {
            ans = min(ans,bin(pb,pa[i])+i);
        }
        cout<<ans<<endl;
    }
	return 0;

}
