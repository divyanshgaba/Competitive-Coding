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
#define REP(i,a,b) for (ll i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
const ll N=50000;
const ll INF = -1e5;
struct node
{
    ll val;
    ll left, right, total , bestsum, ans;
    node()
    {
        val = left = right = total = bestsum =ans= INF;
    }

};
node add(node a, node b)
{
    node c;
    c.left = max(a.left, a.total + b.left);
    c.right = max(b.right, b.total + a.right);
    c.total = a.total + b.total;
    c.ans = max(c.left,max(c.right,max(a.ans,max(b.ans,a.right + b.left))));
    return c;
}
void init(node &a)
{
    a.left = a.right = a.total = a.bestsum  = a.ans = a.val;
}
node seg[2*N];
ll n;
void build()
{
    for(ll i = n-1;i>0;--i) seg[i] = add(seg[i<<1],seg[i<<1|1]);
}
ll query(ll l,ll r)
{
    node resl,resr;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            resl = add(resl,seg[l++]);
        if(r&1)
            resr = add(seg[--r],resr);
    }
    return add(resl,resr).ans;
}
int main()
{
    scanf("%lld",&n);
    for(ll i = 0;i<n;++i) scanf("%lld",&seg[i+n].val),init(seg[i+n]);
    build();
    ll m;
    scanf("%lld",&m);
    while(m--)
    {
        ll l,r;
        scanf("%lld %lld",&l,&r);
        printf("%lld\n",query(l-1,r));
    }
	return 0;

}
