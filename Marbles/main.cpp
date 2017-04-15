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

ll comb(ll n,ll k)
{
    if(k>n) return 0;
    if(k*2>n) k = n-k;
    if(k==0) return 1;
    ll result = n;
    for(int i =2;i<=k;i++)
    {
        result*=(n-i+1);
        result/=i;
    }
    return result;
}


int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        ll a,b;
        cin>>a>>b;
        ll ans;
        cout<<comb(a-1,a-b)<<endl;
    }
	return 0;

}
