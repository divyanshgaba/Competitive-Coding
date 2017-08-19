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
ll a[N];
vector<ll> arr[N];
ll vis[N];

void init()
{
    memset(vis,false,sizeof(vis));
    memset(a,0,sizeof(a));
    for(int i = 0;i<N;i++)
        arr[i].clear();
}

void build(ll seg[],int n)
{
    for(int i =n-1;i>0;--i) seg[i] = seg[i<<1] + seg[i<<1|1];
}
ll query(ll seg[],int n,int l,int r)
{
    ll res = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            res += seg[l++];
        if(r&1)
            res+= seg[--r];
    }
    return res;
}

void update(ll seg[],int n,int p, ll val)
{
    for(seg[p+=n] += val;p>1;p>>=1) seg[p>>1] = seg[p] + seg[p^1];
}

ll answer(int i,ll thresh)
{
    ll ans = 0;
    int n = arr[i].size();
    ll seg[2*n];
    memset(seg,0,sizeof(seg));
    for(int j = 0;j<n;j++)
        seg[j+n]= arr[i][j];
    build(seg,n);
    //cout<<query(seg,n,0,n)<<endl;
    if(query(seg,n,0,n) != n*thresh)
        return -1;
    for(int j = 0;j<n;j++)
    {
        if(seg[j+n] <=thresh)
            continue;
        ll surp = seg[j+n] - thresh;
        ll sumL = query(seg,n,0,j);
        ll sumR = query(seg,n,j+1,n);
        ll reqL = j*thresh;
        ll reqR = (n-j-1)*thresh;
        if(reqL - sumL > 0)
        {
            ll giv = min(reqL - sumL, surp);
            ans += giv;
            surp -=giv;
            update(seg,n,j-1,giv);
            update(seg,n,j,-giv);
        }
        if(reqR - sumR > 0)
        {
            ll giv = min(reqR - sumR, surp);
            ans += giv;
            surp -=giv;
            update(seg,n,j+1,giv);
            update(seg,n,j,-giv);
        }
    }
    for(int j = n-1;j>=0;j--)
    {
        if(seg[j+n] <=thresh)
            continue;
        ll surp = seg[j+n] - thresh;
        ll sumL = query(seg,n,0,j);
        ll sumR = query(seg,n,j+1,n);
        ll reqL = j*thresh;
        ll reqR = (n-j-1)*thresh;
        if(reqL - sumL > 0)
        {
            ll giv = min(reqL - sumL, surp);
            ans += giv;
            surp -=giv;
            update(seg,n,j-1,giv);
            update(seg,n,j,-giv);
        }
        if(reqR - sumR > 0)
        {
            ll giv = min(reqR - sumR, surp);
            ans += giv;
            surp -=giv;
            update(seg,n,j+1,giv);
            update(seg,n,j,-giv);
        }
    }
    return ans;

}

int main()
{

	int test=1;
	cin>>test;
	while(test--)
    {
        init();
		int n,d;
		cin>>n>>d;
		ll sum = 0;
		for(int i = 0;i<n;i++)
            cin>>a[i],sum+=a[i];
        bool ispossible = true;
        ll ans = 0;
        ll thresh = sum/n;
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                for(int j = i;j<n;j+=d)
                {
                    vis[j] = true;
                    arr[i].PB(a[j]);
                }
            }
        }
        for(int i = 0;i<n;i++)
        {
            if(arr[i].size() == 0)
                break;
            ll t = answer(i,thresh);
            if(t == -1)
            {
                ispossible = false;
                break;
            }
            else
                ans+=t;
        }
        if(ispossible)
            cout<<ans<<"\n";
        else
            cout<<-1<<"\n";



    }
	return 0;

}
