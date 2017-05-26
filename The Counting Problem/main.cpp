#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)
using namespace std;
typedef long long ll;
ll merge(ll a[],ll b[],ll l,ll m,ll r)
{
    ll i,j,k,inv=0;
    i=l,j=m,k=l;
    while(i<=m-1 && j<=r)
    {
        if(a[i]<=a[j])
        {
             b[k++] = a[i++];

        }
        else
        {
            b[k++]=a[j++];
            inv+=(m-i);
        }

    }
    while(i<=m-1)
        b[k++]=a[i++];
    while(j<=r)
        b[k++]=a[j++];
    for(ll i =l;i<=r;i++)
        a[i]=b[i];
    return inv;

}


ll mergesort(ll a[],ll b[],ll l,ll r)
{
    ll inv = 0,m;
    if(r>l)
    {
        m = (r+l)/2;
        inv +=mergesort(a,b,l,m);
        inv+=mergesort(a,b,m+1,r);
        inv+=merge(a,b,l,m+1,r);
    }
    return inv;
}

ll answer(ll arr[],ll n)
{
    ll *temp = new ll[n];
    return mergesort(arr,temp,0,n-1);
}

int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i =0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<answer(a,n)<<endl;
    }
    return 0;
}
