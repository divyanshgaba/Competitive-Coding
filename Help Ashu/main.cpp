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

const int N = 2e5;
int a[N];
int tree[4*N];
int n;
void build(int node=1,int st=0,int en = n-1)
{
    if(st == en)
    {
        if(a[st] %2 !=0)
            tree[node] = 1;
        else
            tree[node] = 0;
        return;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node] = tree[node*2] + tree[node*2 +1];
}
int query(int node,int st,int en,int l,int r)
{
    if(st> r || en < l)
        return 0;
    if(l<=st && en <=r)
    {
        return tree[node];
    }
    int mid = (st+en)/2;
    int p1 = query(2*node,st,mid,l,r);
    int p2 = query(2*node+1,mid+1,en,l,r);
    return p1 + p2;
}
void modify(int node,int st,int en,int idx,int val)
{
    if(st == en)
    {
        if(a[idx]%2 !=0)
            tree[node]-=1;
        if(val%2 != 0)
            tree[node]+=1;
        a[idx]=val;
        return;
    }
    int mid = (st+en)/2;
    if(st <= idx && idx<=mid)
    {
        modify(2*node,st,mid,idx,val);
    }
    else
    {
        modify(2*node+1,mid+1,en,idx,val);
    }
    tree[node] = tree[2*node] + tree[2*node+1];


}
int main()
{
	fast;
	cin>>n;
	for(int i =0;i<n;i++)
        cin>>a[i];
    build();
    int q;
    cin>>q;
    while(q--)
    {
        int t,l,r;
        cin>>t>>l>>r;
        if(t==0)
        {
            modify(1,0,n-1,l-1,r);
            continue;
        }
        int p = query(1,0,n-1,l-1,r-1);
        if(t == 1)
        {
            cout<<r - l + 1 - p<<endl;
        }
        else
            cout<<p<<endl;
    }
    /*for(int i = 0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i = 0;i<4*n;i++)
        cout<<tree[i]<<" ";*/

	return 0;

}
