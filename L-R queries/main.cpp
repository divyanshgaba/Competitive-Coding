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
#define REP(i,a,b) for (int64_t i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int64_t> vi;
typedef pair<int64_t,int64_t> pi;
const int N = 1e5;
multiset<ll> t[2*N];
int n;
void modify(ll p,ll v)
{
    ll ele = *t[p+n].begin();
    for(p+=n;p>=1;p>>=1)
    {
        t[p].erase(t[p].find(ele));
        t[p].insert(v);
    }
}
ll query(ll l,ll r,ll m)
{
    ll ans = *t[l+n].begin();
    ll err = abs(m-ans);
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)
        {
            auto it = t[l].lower_bound(m);
            if(it==t[l].end())
                it--;
            ll val = *it;
            if(abs(val-m)<err)
                ans = val,err=abs(ans-m);
            if(it!=t[l].begin())
                it--;
            val = *it;
            if(abs(val-m)<err)
                ans = val,err=abs(ans-m);
            l++;
        }
        if(r&1)
        {
            --r;
            auto it = t[r].lower_bound(m);
            if(it==t[r].end())
                it--;
            ll val = *it;
            if(abs(val-m)<err)
                ans = val,err=abs(ans-m);
            if(it!=t[r].begin())
                it--;
            val = *it;
            if(abs(val-m)<err)
                ans = val,err=abs(ans-m);
        }
    }
    return ans;
}
void print()
{
    for(int i = 1;i<2*n;i++)
    {
        for(auto j:t[i])
            cout<<j<<" ";
        cout<<endl;
    }
}
multiset<ll> emp;
int main()
{
	fast;
	ll test=1;
	cin>>test;
	while(test--)
    {
		ll q;
		cin>>n>>q;
		ll a;
		for(int i = 0;i<n;i++)
            t[i] = emp;
		for(int i = 0;i<n;i++)
        {
            cin>>a;
            t[i+n] = emp;
            t[i+n].insert(a);
            for(int p = i+n;p>1;p>>=1)
                t[p>>1].insert(a);
        }
        //print();
        while(q--)
        {
            int ty;
            cin>>ty;
            if(ty==1)
            {
                int l,r;
                cin>>l>>r;
                l--,r--;
                ll al = *t[l+n].begin();
                ll ar = *t[r+n].begin();
                ll m = (al+ar);
                //cout<<m<<endl;
                ll am = query(l,r+1,m/2);
                //cout<<am<<endl;
                ll ans = (am-al)*(ar-am);
                if(m&1)                    am = query(l,r+1,(m+1)/2),ans = max(ans,(am-al)*(ar-am));
                cout<<ans<<endl;
            }
            else
            {
                ll x,y;
                cin>>x>>y;
                modify(x-1,y);
            }
            //print();

        }
    }
	return 0;

}
