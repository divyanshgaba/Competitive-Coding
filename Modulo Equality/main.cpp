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
typedef pair<ll,ll> pi;
bool cmp (pi a, pi b)
{
    return a.F<b.F;
}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
	{
	    int n;
	    cin>>n;
	    ll a[n],b[n];
	    for(int i = 0;i<n;i++)
            cin>>a[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        pair<ll,ll> c[n];
        for(int i = 0;i<n;i++)
            c[i].F=a[i]%b[i],c[i].S=b[i];
        sort(c,c+n);
        ll ans = 1e17;
        ll sum[n],pre[n];
        pre[0]=c[0].S;
        sum[0]=c[0].F;
        for(int i = 1;i<n;i++)
            sum[i]=sum[i-1]+c[i].F,pre[i]=pre[i-1]+c[i].S;
        for(int i = 0;i<n;i++)
        {
            ll left = lower_bound(c,c+n,MP(c[i].F,0),cmp)-c;
            ll right = upper_bound(c,c+n,MP(c[i].F,0),cmp)-c;
            ll temp = (pre[n-1]-pre[right-1])-(sum[n-1]-sum[right-1]);
            if(left)
                temp +=(left*c[i].F-sum[left-1]);
            temp += (n-right)*c[i].F;
            ans = min(temp,ans);
        }
        cout<<ans<<endl;
	}
	return 0;
}
