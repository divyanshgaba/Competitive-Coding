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


int main()
{
	fast;
	ll n;
	cin>>n;
	ll a[n];
	map<ll,vector<ll> > mp;
    ll suf[n],pre[n];
    memset(suf,0,sizeof(suf));
    memset(pre,0,sizeof(pre));
	for(ll i =0;i<n;++i)
    {
        cin>>a[i];
        (mp[a[i]]).PB(i);
    }
    suf[0]=a[0];
    pre[n-1LL]=a[n-1LL];
    for(ll i =n-2LL;i>=0;--i)
        pre[i]=pre[i+1]+a[i];
    for(ll i =1LL;i<n;++i)
        suf[i]=suf[i-1LL]+a[i];
    /*for(auto i:suf)
        cout<<i<<" ";
    cout<<endl;
    for(auto i:pre)
        cout<<i<<" ";
    cout<<endl;*/
    bool ans = false;
    for(ll i =0;i<n-1LL&&!ans;i++)
    {
        if(suf[i] == pre[i+1LL])
        {
            ans = true;
            break;
        }
        else
        {
            ll t = (suf[i]-pre[i+1LL]);
            if(llabs(t)%2LL!=0)
                continue;
            t/=2LL;
            //cout<<t<<endl;
            if(mp.count(llabs(t)) > 0)
            {
                auto j = mp[llabs(t)];
                if(j.size()==0)
                    continue;
                if(t<0)
                {
                    for(auto k:j)
                    {
                        if(k>i)
                        {
                            ans = true;
                            break;
                        }
                    }
                }
                else if(t>0)
                {
                    for(auto k:j)
                    {
                        if(k<=i)
                        {
                            ans = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(ans)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


	return 0;

}
