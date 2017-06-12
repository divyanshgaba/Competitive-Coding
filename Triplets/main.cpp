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
const ll mod = 1000000007;

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int p,q,r;
        cin>>p>>q>>r;
        ll a[p],b[q],c[r];
        for(int i =0;i<p;i++)
            cin>>a[i];
        for(int i =0;i<q;i++)
            cin>>b[i];
        for(int i =0;i<r;i++)
            cin>>c[i];
        sort(a,a+p);
        sort(b,b+q);
        sort(c,c+r);
        ll x[p],z[r];
        x[0]=a[0];
        z[0]=c[0];
        for(int i =1;i<p;i++)
        {
            x[i] = x[i-1]+a[i];
            x[i]%=mod;
        }
        for(int i =1;i<r;i++)
        {
            z[i]=z[i-1]+c[i];
            z[i]%=mod;
        }
        ll sum =0;
        for(int i =0;i<q;i++)
        {
            ll y = b[i];
            int ix = upper_bound(a,a+p,y) - a -1;
            int iz = upper_bound(c,c+r,y) - c -1;
            if(ix <0 || iz < 0)
                continue;
            //cout<<y<<" "<<ix<<" "<<iz<<endl;            cout<<x[ix]<<" "<<z[iz]<<endl;
            sum = sum + (y*(((iz+1)*x[ix])%mod)%mod);
            sum%=mod;
            sum = sum + (x[ix]*z[iz])%mod;
            sum%=mod;
            sum = sum + ((ix+1)*(((iz+1)*((y*y)%mod))%mod)%mod);
            sum%=mod;
            sum = sum + (y*(((ix+1)*z[iz])%mod)%mod);
            sum%=mod;


        }
        cout<<sum<<endl;
    }
	return 0;

}
