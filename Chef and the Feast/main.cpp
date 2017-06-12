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
	int test;
	cin>>test;
	while(test--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i =0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        ll ans = 0;
        ll sum[n],pre[n];
        pre[0]=a[0];
        sum[n-1]=a[n-1];
        for(ll i =n-2;i>=0;--i)
            sum[i]=sum[i+1]+a[i];
        for(ll i =1;i<n;i++)
            pre[i] = pre[i-1]+a[i];
        for(ll i = n-1;i>=0;i--)
        {
            if(ans <= sum[i]*(n-i))
                ans = sum[i]*(n-i);
            else
            {
                ans +=pre[i];
                break;
            }
        }
        cout<<ans<<endl;
    }
	return 0;

}
