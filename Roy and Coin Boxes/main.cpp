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
ll n;
const ll N = 1e6+1;
ll a[N];
vector<ll> tree[4*N];
void build(ll node=1,ll st=0,ll en = n-1)
{
    if(st == en)
    {
        tree[node].PB(a[st]);
        return;
    }
    ll mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    merge(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),tree[2*node+1].end(),back_inserter(tree[node]));
}

ll query(ll node,ll st,ll en,ll l,ll r,ll x)
{
    if(st > r || en <l)
        return 0;
    if(l<=st && en <=r)
    {
        //print(tree[node]);
        return lower_bound(tree[node].begin(),tree[node].end(),x) - tree[node].begin();
    }
    ll mid = (st+en)/2;
    ll p1 = query(2*node,st,mid,l,r,x);
    ll p2 = query(2*node+1,mid+1,en,l,r,x);
    return p1+p2;
}
int main()
{
	fast;
	cin>>n;
	ll m;
	cin>>m;
	for(ll i =0;i<m;i++)
    {
        ll l,r;
        cin>>l>>r;
        a[l-1]++,a[r]--;
    }
    for(ll i = 1;i<n;i++)
	{
	    a[i] += a[i-1];
	}
	sort(a,a+n);
	//build();
    ll q;
    cin>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        cout<<n - (lower_bound(a,a+n,x)-a)<<endl;
        //cout<< n - query(1,0,n-1,0,n-1,x)<<endl;
    }
	return 0;

}
