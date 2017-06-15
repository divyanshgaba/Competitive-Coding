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
const int N = 1e5;
int a[N];
int tree[4*N];
int lazy[4*N];
int n;
void build(int node=1,int st=0,int en=n-1)
{
    if(st == en)
    {
        tree[node] = a[st];
        return;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node] = tree[2*node] + tree[2*node+1];
}
int query(int node,int lo,int hi,int l,int r)
{
    if(lo > r || hi < l)
    {
        return 0;
    }
    if(lazy[node] !=0)
    {
        tree[node]+=(hi-lo+1)*lazy[node];
        if(lo!=hi)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l <= lo && hi <=r)
        return tree[node];
    int mid = (lo+hi)/2;
    int p1 = query(2*node,lo,mid,l,r);
    int p2 = query(2*node +1,mid+1,hi,l,r);
    return p1+p2;
}
void updaterange(int node,int lo,int hi,int l ,int r,int val)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(hi-lo +1 )*lazy[node];
    }
    if(lo!=hi)
    {
        lazy[2*node] +=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;
    if(lo> hi || lo >r || hi<l)
    {
        return;
    }
    if(lo>=l && hi <=r)
    {
        tree[node]+=(hi-lo+1)*val;
        if(hi!=lo)
        {
            lazy[node*2]+=val;
            lazy[2*node +1]+=val;
        }
        return;
    }
    int mid = (lo+hi)/2;
    updaterange(2*node,lo,mid,l,r,val);
    updaterange(2*node+1,mid+1,hi,l,r,val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int q;
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        memset(a,0,sizeof(a));
        cin>>n>>q;
        //build();
        /*for(int i = 0;i<4*n;i++)
            cout<<tree[i]<<" ";
        cout<<endl;*/
        while(q--)
        {
            int t;
            cin>>t;
            if(t==0)
            {
                int p,q,v;
                cin>>p>>q>>v;
                updaterange(1,0,n-1,p-1,q-1,v);
            }
            else
            {
                int p,q;
                cin>>p>>q;
                cout<<query(1,0,n-1,p-1,q-1)<<endl;
            }
        }
    }
	return 0;

}
