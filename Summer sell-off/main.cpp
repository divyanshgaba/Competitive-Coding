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
	int n,f;
	cin>>n>>f;
	ll ans =0;
	priority_queue<ll> q;
	for(int i =0;i<n;i++)
	{
	    pair<ll,ll> kl;
	    cin>>kl.F>>kl.S;
	    ans += min(kl.F,kl.S);
        q.push(min(2*kl.F,kl.S) - min(kl.F,kl.S));
	}
	while(f--)
    {
        ans+=q.top();
        q.pop();
    }
    cout<<ans<<endl;


	return 0;

}
