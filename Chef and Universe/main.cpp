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
    ll numb = x + min(y,(z+y-x)/2);
    ll ans =  min(b*(numb) + (x+y+z-2*numb)*a,(x+y+z)*a);
    return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
		cin>>x>>y>>z>>a>>b>>c;
		if(x>y)
            swap(x,y);
        if(x>z)
            swap(x,z);
        if(y>z)
            swap(y,z);
		ll ans = val(x,y,z);
		ll n = min(x,min(y,z));
		for(int i = 0;i<100;i++)
        {
            ll o = val(x-i,y-i,z-i)+i*c;
            ll t = val(x-n+i,y-n+i,z-n+i)+(n-i)*c;
            ll j = 1e16;
            if((n/2-i)>=0)
                j = val(x-n/2+i,y-n/2+i,z-n/2+i)+(n/2-i)*c;
            ll k = val(x-n/2-i,y-n/2-i,z-n/2-i)+(n/2+i)*c;
            ans = min(ans,min(o,min(t,min(j,k))));
        }
        cout<<ans<<endl;

    }
	return 0;

}
