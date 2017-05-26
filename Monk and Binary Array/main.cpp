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
long long subarrayXor(int arr[], int n, int m)
{
    long long ans = 0;

    int *xorArr = new int[n];

    unordered_map <int, ll> mp;

    xorArr[0] = arr[0];

    for (int i = 1; i < n; i++)
        xorArr[i] = xorArr[i-1] ^ arr[i];

    for (int i = 0; i < n; i++)
    {
        int tmp = m ^ xorArr[i];
        ans = ans + mp[tmp];
        if (xorArr[i] == m)
            ans++;
        mp[xorArr[i]]++;
    }
    return ans;
}
int main()
{
	fast;
	int n;
	cin>>n;
	int a[n];
	for(int i =0;i<n;i++) cin>>a[i];
	ll ans = 0;
	for(int i =0;i<n;i++)
    {
        a[i] = a[i]==1?0:1;
        ans = max(ans,subarrayXor(a,n,1));
        a[i] =a[i]==1?0:1;
    }
	cout<<ans<<endl;
	return 0;

}
