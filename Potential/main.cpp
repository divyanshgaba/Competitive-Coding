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
const int N = 3e5;
const ll INF = 1e16;
ll segx[2*N];
ll segp[2*N];
ll x[N];
ll p[N];
int n;
void build()
{
    for(int i = n-1;i>0;i--)
        segx[i] = max(segx[i<<1],segx[i<<1|1]),segp[i] = max(segp[i<<1],segp[i<<1|1]);

}
ll queryxi(ll l,ll r)
{
    ll ans = -INF;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            ans = max(ans,segx[l++]);
        if(r&1)
            ans = max(ans,segp[--r]);
    }
    return ans;
}
ll queryxp(ll l,ll r)
{
    ll ans = -INF;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            ans = max(ans,segp[l++]);
        if(r&1)
            ans = max(ans,segp[--r]);
    }
    return ans;
}
ll modifyx(ll pos, ll val)
{
    ll hold = pos;
    x[pos] = val;
    for(segx[pos+n]=x[pos]+pos,pos+=n;pos>1;pos>>=1)
        segx[pos>>1] = max(segx[pos],segx[pos^1]);
    pos = hold;
    for(segp[pos+n]=p[pos]+x[pos],pos+=n;pos>1;pos>>=1)
        segp[pos>>1]=max(segp[pos],segp[pos^1]);
}
ll modifyp(ll pos, ll val)
{
    p[pos] = val;
    for(segp[pos+n]=p[pos]+x[pos],pos+=n;pos>1;pos>>=1)
        segp[pos>>1]=max(segp[pos],segp[pos^1]);
}
int main()
{
	//fast;
	int q;
	cin>>n>>q;
	for(int i = 0;i<n;i++)
        cin>>x[i],segx[i+n]= x[i] + i;
    for(int i = 0;i<n;i++)
        cin>>p[i],segp[i+n]= x[i] + p[i];
    build();
    for(int i = 0;i<2*n;i++)
        cout<<segx[i]<<" ";
    cout<<endl;
    for(int i = 0;i<2*n;i++)
        cout<<segp[i]<<" ";
    cout<<endl;
    while(q--)
    {
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1)
        {
            modifyx(a-1,b);
                for(int i = 0;i<2*n;i++)
        cout<<segx[i]<<" ";
    cout<<endl;
    for(int i = 0;i<2*n;i++)
        cout<<segp[i]<<" ";
    cout<<endl;
        }
        else if(t==2)
        {
            modifyp(a-1,b);
                for(int i = 0;i<2*n;i++)
        cout<<segx[i]<<" ";
    cout<<endl;
    for(int i = 0;i<2*n;i++)
        cout<<segp[i]<<" ";
    cout<<endl;
        }
        else
        {
            cout<<queryxi(a-1,b)<<" "<<queryxp(a-1,b)<<endl;
        }
    }
	return 0;

}
