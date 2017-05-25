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
const ll mod = 1e9 +7;

int n;
ll arr[300001];

ll smax()
{
    ll sum = arr[n-1];
    for (int i = n-2; i >=0; --i)
    {
        sum = ((2*sum)%mod + arr[i])%mod;
    }
    return sum;
}
ll smin()
{
    ll sum = arr[0];
    for(int i =1;i<n;++i)
    {
        sum = ((2*sum)%mod + arr[i])%mod;
    }
    return sum;
}
int main()
{
	fast;
	cin>>n;
	for(int i =0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    //for(int i =0;i<n;i++)        cout<<arr[i]<<" ";
    //cout<<smax()<<" "<<smin()<<"\n";
    ll ans = smax()-smin();
    if(ans > mod)
        ans %=mod;
    else if(ans< 0)
        ans+=mod;
    cout<<ans<<endl;
	return 0;

}
