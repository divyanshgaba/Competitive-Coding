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

ll n;

ll getSum(ll BITree[], ll index)
{
    ll sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(ll BITree[], ll n, ll index, ll val)
{
    index = index + 1;
    while (index <= n)
    {
        BITree[index] += val;

        index += index & (-index);
    }
}
ll sum(ll x, ll BITTree1[], ll BITTree2[])
{
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);
}


void updateRange(ll BITTree1[], ll BITTree2[], ll n,
                 ll val, ll l, ll r)
{
    updateBIT(BITTree1,n,l,val);
    updateBIT(BITTree1,n,r+1,-val);
    updateBIT(BITTree2,n,l,val*(l-1));
    updateBIT(BITTree2,n,r+1,-val*r);
}

ll rangeSum(ll l, ll r, ll BITTree1[], ll BITTree2[])
{
    return sum(r, BITTree1, BITTree2) -
           sum(l-1, BITTree1, BITTree2);
}
ll *constructBITree(ll n)
{

    ll *BITree = new ll[n+1];
    for (ll i=1; i<=n; i++)
        BITree[i] = 0;

    return BITree;
}

int main()
{
	fast;
	ll test;
	cin>>test;
	while(test--)
    {
        ll c;
        cin>>n>>c;
        ll *bit1 = constructBITree(n),*bit2 = constructBITree(n);
        while(c--)
        {
            ll x;
            cin>>x;
            if(x==0)
            {
                ll p,q;
                cin>>p>>q;
                p--,q--;
                ll v;
                cin>>v;
                updateRange(bit1,bit2,n,v,p,q);

            }
            else
            {
                ll p,q;
                cin>>p>>q;
                p--,q--;
                cout<<rangeSum(p,q,bit1,bit2)<<endl;
            }
        }

    }
	return 0;

}
