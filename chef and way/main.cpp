#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
ll m = 1000000007;
int main()
{
    int n,k;
    cin>>n>>k;
    ll a[n];

    for(int i =0;i<n;i++)
        cin>>a[i];
    ll ans = a[n-1]*a[0];
    n-=k;
    while(n>=1)
    {
        ans=(ans*a[n-1])%m;
        n-=k;
    }
    cout<<ans<<endl;
    return 0;
}
