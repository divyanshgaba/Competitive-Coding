#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;

ll metn[100005];
ll metm[100005];



int main()
{
	fast;
	ll test;
	cin>>test;
	while(test--)
    {
        ll n,m,q;
        cin>>n>>m>>q;
        memset(metn,0,sizeof(metn));
        memset(metm,0,sizeof(metm));
        //vector<pi> met;
        priority_queue <ll, vector<ll>, greater<ll> > lon;
        priority_queue <ll, vector<ll>, greater<ll> > lat;
        lon.push(1);
        lon.push(n);
        lat.push(1);
        lat.push(m);
        metm[1]=metm[m]=1;
        metn[1]=metn[n]=1;
        for(ll i =0;i<q;i++)
        {
            ll x,y;
            cin>>x>>y;
            if(metn[x]!=1)
                lon.push(x);
            if(metm[y]!=1)
                lat.push(y);
            metn[x]=1;
            metm[y]=1;
        }
        ll regions = (lon.size()-1)*(lat.size()-1);
        ll a=0,b=0;
        ll xmax=0,xmin=10000000;
        ll ymax=0,ymin=10000000;
        a=lon.top();
        lon.pop();
        while(!lon.empty())
        {
            ll top = lon.top();
            lon.pop();
            xmax=max(xmax,abs(top-a));
            xmin=min(xmin,abs(top-a));
            a = top;
        }
        a=lat.top();
        lat.pop();
        while(!lat.empty())
        {
            ll top = lat.top();
            lat.pop();
            ymax=max(ymax,abs(top-a));
            ymin=min(ymin,abs(top-a));
            a = top;
        }
        cout<<regions<<" "<<xmin*ymin<<" "<<xmax*ymax<<endl;

    }
	return 0;

}
