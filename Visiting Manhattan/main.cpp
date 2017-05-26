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

ll memx[1000002],memy[1000002];
int main()
{
	fast;
	ll x,y,l,h;
	cin>>x>>y>>l>>h;
	ll sx=0,sy=0;
	ll la[l],lb[l];
	for(int i =0;i<l;i++)
    {

        cin>>la[i]>>lb[i];
    }
    sort(la,la+l);
    sort(lb,lb+l);
    memx[0] =la[0];
    memy[0] = lb[0];
    for(int i =1;i<l;i++)
    {
        memx[i] =memx[i-1] + la[i];
        memy[i] =memy[i-1] + lb[i];
    }
    ll ans=1;
    ll tx=1e17,ty=1e17;
    for(int i =0;i<h;i++)
    {
        ll a,b;
        cin>>a>>b;
        int x = lower_bound(la,la+l,a) - la;
        int y = lower_bound(lb,lb+l,b) - lb;
        ll tmpx = abs((x)*a - memx[x-1]) + abs(memx[l-1] -memx[x-1]- (l-x)*a);
        ll tmpy = abs((y)*b - memy[y-1]) + abs(memy[l-1] -memy[y-1]- (l-y)*b);
        if(tx + ty > tmpx+tmpy)
        {
            tx = tmpx;
            ty = tmpy;
            ans = i+1;
        }

    }
    cout<<ans<<endl;

	return 0;

}
