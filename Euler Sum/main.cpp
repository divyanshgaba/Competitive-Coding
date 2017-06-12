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
        ll u,v;
        cin>>u>>v;
        ll n = u+v;

        ll sum = (n*(n+1))/2;
        ll ans = sum + (n-v+1);
        cout<<ans<<endl;
    }
	return 0;

}
