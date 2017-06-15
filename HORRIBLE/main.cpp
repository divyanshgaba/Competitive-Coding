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
const ll N = 1e6;
ll a[N];
ll tree[4*N];
ll lazy[4*N];
ll n;
ll query(ll node,ll st,ll en,ll l,ll r)
{
    if(st >r || en < l || en< st)
        return 0;
    if(lazy[node] != 0)
    {
        tree[node]+=((en-st +1)*lazy[node]);
        if(st != en)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l<=st && en<=r)
    {
        return tree[node];
    }
    ll mid = (st+en)/2;
    ll p1 = query(2*node,st,mid,l,r);
    ll p2 = query(2*node+1,mid+1,en,l,r);
    return p1+p2;

}
void update(ll node,ll st,ll en,ll l,ll r,ll val)
{
    if(lazy[node]!=0)
    {
        tree[node]+=((en-st+1)*lazy[node]);
        if(st != en)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(st>en || en<l || st>r)
        return;
    if(l<=st && en<=r)
    {
        tree[node]+=((en-st+1)*val);
        if(st!=en)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    ll mid = (st+en)/2;
    update(2*node,st,mid,l,r,val);
    update(2*node+1,mid+1,en,l,r,val);
    tree[node] = tree[2*node] + tree[2*node+1];
}
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        ll q;
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        memset(a,0,sizeof(a));
        cin>>n>>q;
        //build();
        /*for(ll i = 0;i<4*n;i++)
            cout<<tree[i]<<" ";
        cout<<endl;*/
        while(q--)
        {
            ll t;
            cin>>t;
            if(t==0)
            {
                ll p,q,v;
                cin>>p>>q>>v;
                update(1,0,n-1,p-1,q-1,v);
            }
            else
            {
                ll p,q;
                cin>>p>>q;
                cout<<query(1,0,n-1,p-1,q-1)<<endl;
            }
        }
    }
	return 0;

}
