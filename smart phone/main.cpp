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
    ll n;
    cin>>n;
    ll a[n];
    for(ll i =0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    ll rev =0;
    for(ll i =0;i<n;i++)
    {
        rev = max(rev,a[i]*(n-i));
    }
    cout<<rev<<endl;
}
