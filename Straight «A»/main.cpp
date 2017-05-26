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
	ll n,k;
	cin>>n>>k;
	ll a[n];
	ll sum = 0;
	for(int i =0;i<n;i++)
        cin>>a[i],sum+=a[i];
    cout<<max(0LL,2*k*n -n -2*sum)<<endl;


	return 0;

}
