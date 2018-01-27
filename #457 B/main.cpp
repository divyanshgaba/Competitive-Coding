/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
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
	ll n,k;
	cin>>n>>k;
    priority_queue<ll> p;
    ll z = k;
    for(ll i = 63;i>=0;i--)
    {
        if(n&(1LL<<i))
            p.push(i),z--;
    }
    vector<ll> a;
    bool ans = true;
    while(z>0&&ans)
    {
        if(p.empty())
        {
            ans = false;
            break;
        }
        z--;
        ll i = p.top();
        p.pop();
        p.push(i-1);
        p.push(i-1);
    }
    if(!ans)
    {
        cout<<"No\n";
        return 0;
    }
    vector<ll> ps;
    while(!p.empty())
    {
        ps.PB(p.top());
        p.pop();
    }
    //assert(ps.size() == k);
    cout<<"Yes\n";
    for(auto i:ps)
        cout<<i<<" ";
    cout<<endl;
	return 0;

}
