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
ll x,y,z,a,b,c;
ll val(ll x,ll y,ll z)
{
    if(x<0||y<0||z<0)
        return 1e16;
    ll ans = 1e16;
    if(z<=x+y)
    {
        if((z+x+y)&1)
            ans = min(ans, ((x+y+z-1)/2)*b+a);
        else
            ans = min(ans,((x+y+z)/2)*b);
    }
    ans = min(ans,(x+y)*b + (z-x-y)*a);
    return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
		cin>>x>>y>>z>>a>>b>>c;
		priority_queue<ll> q;
		q.push(x),q.push(y),q.push(z);
		z = q.top(),q.pop();
		y=q.top(),q.pop();
		x=q.top(),q.pop();
		ll ans = val(x,y,z);
		ll r[] = {x,x+y-z-1,x+y-z,x-1,x};
		for(int i = 0;i<5;i++)
            ans = min(ans,val(x-r[i],y-r[i],z-r[i])+r[i]*c);
        cout<<ans<<endl;

    }
	return 0;

}
