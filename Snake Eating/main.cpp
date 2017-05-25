#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
	int test;
	cin>>test;
	while(test--)
    {
        int n,q;
        cin>>n>>q;
        ll l[n];
        for(int i =0;i<n;i++)
            cin>>l[i];
        sort(l,l+n);
        ll pre[n+1];
        pre[0]=l[0];
        for(int i =1;i<n;i++)
        {
            pre[i] = pre[i-1]+l[i];
        }
        for(int i =0;i<q;i++)
        {
            ll k;
            cin>>k;
            ll ans = (lower_bound(l,l+n,k) - l);
            ll lo = 0,hi = ans-1;
            ll c = ans-1;
            ans = n-ans;
            ll iskans=0;
            while(lo < hi)
            {
                ll mid = (lo+hi)/2;
                if(pre[c]-pre[mid]+mid+1 >= k*(c-mid))
                {
                    iskans = c-mid;
                    hi = mid;
                }
                else
                {
                    lo = mid+1;
                }

            }
            ans += iskans;
            cout<<ans<<endl;
        }
    }
	return 0;

}
