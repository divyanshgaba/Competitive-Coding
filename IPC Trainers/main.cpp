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
const int D = 100001;
priority_queue<pair<ll, pair<ll,ll> > >  q[100001];
pair<ll, pair<ll,ll> > seg[3*D];

ll n,d;
void init()
{
    for(int i =0;i<D;i++)
        while(!q[i].empty())
            q[i].pop();
}
void build()
{
    for(int i = d-1;i>0;i--) seg[i] = max(seg[i<<1],seg[i<<1|1]);
}
void update(int p, pair<ll,pair<ll,ll>> val)
{
    for(seg[p+=d]=val; p > 1;p>>=1) seg[p>>1] = max(seg[p],seg[p^1]);
}
ll query(ll l,ll r)
{
    pair<ll,pair<ll,ll>> res = MP(0,MP(0,0));
    for(l+=d,r+=d;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            res = max(res,seg[l++]);
        if(r&1)
            res = max(res,seg[--r]);
    }
    if(res.S.F<=1)
    {
        q[res.S.S].pop();
        q[res.S.S].push(MP(0,MP(0,0)));
        update(res.S.S,q[res.S.S].top());
    }
    else
    {
        auto t = res;
        t.S.F -=1;
        q[res.S.S].pop();
        q[res.S.S].push(t);
        update(res.S.S,q[res.S.S].top());
    }
    return res.F;
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		cin>>n>>d;
		init();
		ll total =0;
		for(int i = 0;i<n;i++)
        {
            ll di,t,s;
            cin>>di>>t>>s;
            q[di-1].push(MP(s,MP(t,di-1)));
            total += t*s;
        }
        for(int i = 0;i<d;i++)
        {
            if(!q[i].empty())
                seg[i+d] = q[i].top();
            else
                seg[i+d] = MP(0,MP(0,0));
        }
        build();
        for(int i = 1;i<=d;i++)
        {
            //cout<<total<<" "<<i<<endl;
            total -= (query(0,i));
        }
        cout<<total<<endl;
    }
	return 0;

}
