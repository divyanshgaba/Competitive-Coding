#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
bool ans = true;
const ll N = 1e5;

ll n;
ll arr[N];
ll block;
ll load[100001];
vi seg[2*N+1];

void pre()
{
    for(ll i = 0;i<=2*N;i++)
        seg[i].clear();
}
void build()
{

    for(ll i = n-1;i>0;i--)
        merge(seg[i<<1].begin(),seg[i<<1].end(),seg[i<<1|1].begin(),seg[i<<1|1].end(),back_inserter(seg[i]));
}

bool query(ll l,ll r,ll x,ll y)
{
    ll res =0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            res+=(lower_bound(seg[l].begin(),seg[l].end(),y) - lower_bound(seg[l].begin(),seg[l].end(),x)),l++;
        if(res > 1)
            return false;
        if(r&1)
            --r,res+=(lower_bound(seg[r].begin(),seg[r].end(),y) - lower_bound(seg[r].begin(),seg[r].end(),x));
        if(res > 1)
            return false;

    }
    //cout<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<res<<endl;
    return true;

}

int main()
{
	//fast;
	ll test;
	cin>>test;
	while(test--)
    {
        ll q;
        cin>>n>>q;
        pre();
        for(ll i =0;i<n;i++)
            cin>>arr[i],seg[i+n].PB(arr[i]);
        build();
        for(ll i = 0;i<q;i++)
        {
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            a--,b--,c--,d--;
            if(a == b || (a == c))
            {
                cout<<"YES\n";
                continue;
            }
            ll ta = a,tb = b;
            if(a<c)
            {
                if(b>=c)
                {
                    ll t = b;
                    b = c-1;
                    c = t+1;
                }
            }
            else if(d>=a)
            {
                ll t = d;
                d = a-1;
                a = d+1;
            }
            ll hold[100001] = {0};
            ll maxi = 0,mini = 0;
            for(ll  i=a;i<=b;i++)
            {
                maxi+=arr[i];
                hold[arr[i]]++;
            }
            ll fl =0;
            for(ll i = c;i<=d;i++)
            {
                hold[arr[i]]--;
                if(hold[arr[i]]<0)
                {
                    mini = arr[i];
                    fl++;
                }
                else
                {
                    maxi-=arr[i];
                }
                if(fl>1)
                {
                    break;
                }
            }
            if(fl>1)
            {
                cout<<"NO\n";
                continue;
            }
            if(fl == 0)
            {
                cout<<"YES\n";
                continue;
            }
            else
            {
                if(query(ta,tb+1,maxi,mini)&&query(ta,tb+1,mini,maxi))
                {
                    cout<<"YES\n";
                    continue;
                }

            }
            cout<<"NO\n";


        }



    }
	return 0;

}
